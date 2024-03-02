#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>

union vec3 {
    float as_array[3];
    struct { float x; float y; float z; };

#pragma region // Constructors.
    vec3(): x(0), y(0), z(0) { }

    vec3(float p_x, float p_y): x(p_x), y(p_y), z(0) { }

    vec3(vec3& p_other): x(p_other.x), y(p_other.y), z(p_other.z) { }

    vec3(float p_x, float p_y, float p_z): x(p_x), y(p_y), z(p_z) { }
#pragma endregion

    inline float mag() {
        return sqrt(this->mag_sq());
    }

    inline float mag_sq() {
        return
            this->x * this->x +
            this->y * this->y +
            this->z * this->z;
    }

    inline vec3& add(const vec3 &p_other) {
        this->x += p_other.x;
        this->y += p_other.y;
        this->z += p_other.z;
        return *this;
    }

    inline vec3& sub(const vec3 &p_other) {
        this->x += p_other.x;
        this->y += p_other.y;
        this->z += p_other.z;
        return *this;
    }

    inline float dot(const vec3& other) const {
        return
            this->x * other.x +
            this->y * other.y +
            this->z * other.z;
    }

    inline vec3 cross(const vec3& other) const {
        return vec3(
            this->y * other.z - this->z * other.y,
            this->z * other.x - this->x * other.z,
            this->x * other.y - this->y * other.x
        );
    }

};

class entity {
protected:
    float health = 0, power = 0, range = 0;
    vec3 *position = new vec3();
    std::string name = "";
    int flags = 0;

    ~entity() {
        delete this->position;
    }

public:
    inline int get_tags() {
        return this->flags;
    }

    inline int get_position() {
        return this->flags;
    }

    inline float get_health() {
        return this->health;
    }

    inline void and_flag(int p_flags) {
        this->flags &= p_flags;
    }

    inline void mod_health(float p_to_add) {
        this->health += p_to_add;

        if (this->health < 0) {
            this->health = 0;
            this->and_flag(0);
        }
    }

    inline void attempt_attack(entity &p_victim) {
        if (p_victim.position->mag_sq() < this->range)
            p_victim.mod_health(-this->power);
    }

    inline void set_position(float *p_position_array) {
        this->position->as_array[0] = p_position_array[0];
        this->position->as_array[1] = p_position_array[1];
        this->position->as_array[2] = p_position_array[2];
    }

    inline void set_position(float p_x, float p_y, float p_z) {
        this->position->x = p_x;
        this->position->y = p_y;
        this->position->z = p_z;
    }

};

class enemy : public entity {
public:
    const static int tag = 0x02;

    enemy() {
        this->range = 8;
        this->power = 20;
        this->health = 20;
        this->flags &= enemy::tag;
    }

};

class player : public entity {
public:
    const static int tag = 0x01;

    player() {
        this->range = 10;
        this->power = 50;
        this->health = 50;
        this->flags &= player::tag;
    }

};

enum class game_flags : int {
    invalid = 0, enemy = 1, player = 2
};

void sleep_for_ms(const size_t p_millis) {
    std::this_thread::sleep_for(std::chrono::milliseconds(p_millis));
}

void sleep_for_ns(const size_t p_millis) {
    std::this_thread::sleep_for(std::chrono::nanoseconds(p_millis));
}

void sleep_for_s(const size_t p_millis) {
    std::this_thread::sleep_for(std::chrono::seconds(p_millis));
}

int main() {
    player hero;
    std::cout
        << "You are a hero with `"
        << hero.get_health()
        << "` health points."
        << std::endl;

    sleep_for_s(1);

    std::cout << "(This program continues as you press `Enter`.)" << std::endl;

    std::cin.ignore();

    enemy e1, e2;
    std::cout
        << "Two enemies with `"
        << e1.get_health()
        << "` and `"
        << e2.get_health()
        << "` health points have appeared!" << std::endl;
    std::cin.ignore();

    hero.attempt_attack(e1);
    std::cout << "Hero attacked the first!" << std::endl;
    std::cout << "The first enemy has `" << e1.get_health() << "` health!" << std::endl;
    std::cin.ignore();

    e2.attempt_attack(hero);
    std::cout << "Other enemy attacked the hero!" << std::endl;
    std::cout << "The hero has `" << hero.get_health() << "` health!" << std::endl;
    std::cin.ignore();

    hero.attempt_attack(e2);
    std::cout << "Hero attacked the second!" << std::endl;
    std::cout << "The second enemy has `" << e2.get_health() << "` health!" << std::endl;
    std::cin.ignore();

    std::cout << "The hero has won and survived." << std::endl;
    std::cout << "(Press any key to exit.)";
    std::cin.ignore();
}
