#include <iostream>
#include <string>

class entity {
protected:
    float *position = new float[3];
    std::string name = "";
    int flags = 0;

    ~entity() {
        delete[] this->position;
    }

    inline int get_tags() {
        return this->flags;
    }

    inline int get_position() {
        return this->flags;
    }

    inline void add_tag(int p_flags) {
        this->flags &= p_flags;
    }

    inline void set_position(float *p_position_array) {
        this->position[0] = p_position_array[0];
        this->position[1] = p_position_array[1];
        this->position[2] = p_position_array[2];
    }

    inline void set_position(float p_x, float p_y, float p_z) {
        this->position[0] = p_x;
        this->position[1] = p_y;
        this->position[2] = p_z;
    }

};

class player : public entity {
public:
    const static int tag = 0x01;

    player() {
        this->flags &= player::tag;
    }

};

class enemy : public entity {
public:
    const static int tag = 0x02;

    enemy() {
        this->flags &= enemy::tag;
    }

};

int main() {
}
