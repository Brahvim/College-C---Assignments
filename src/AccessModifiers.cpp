#include <iostream>
#include <string>

// If this is defined, the code will try to access `private` members from `person`.
// If it does, the code won't compile.

// To have the same effect as un-commenting this line, try passing `-DTRY_ACCESSING_PRIVATE_MEMBERS` to `g++`.
// #define TRY_ACCESSING_PRIVATE_MEMBERS 1

// ...back to snake-case.
// As always, all methods are declared as `inline`, so old compilers need not worry.

class person {
public:
    typedef unsigned short int age_t;
    typedef std::string name_t; // This should be `std::u8string` from glibc++.

#pragma region // Constructors.
    person(person::age_t p_age, person::name_t&& p_name): name(p_name), age(p_age) { };

    // Copy-constructor. It can access private members of another object of this class:
    person(const person& p_person): age(p_person.age), name(std::string(p_person.name)) { }

    person(person::age_t p_age): age(p_age), name(std::string("")) { };

    person(person::name_t p_name): name(std::string(p_name)) { };

    person(): name(std::string("")) { }
#pragma endregion

    inline age_t get_age() {
        return this->age;
    }

    inline std::string& get_name() {
        return this->name;
    }

    inline bool set_age(person::age_t p_age) {
        if (p_age < 18)
            return false;

        this->age = p_age;
        return true;
    }

    inline void set_name(const person::name_t& p_name) {
        this->name = std::string(p_name);
    }

private:
    person::age_t age = 0;
    person::name_t name;

};

int main() {
    person p1(17, "Brahvim");
    person p2("Akhil");

#ifdef TRY_ACCESSING_PRIVATE_MEMBERS
    p1.age = 18;
    p2.age = 18;
#endif

    p1.set_age(18);
}
