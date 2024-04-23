#include <iostream>

class person {

public:
    person(std::string p_name, int p_age): name(p_name), age(p_age) { // cppcheck-suppress passedByValue

    }

    static person create_null() {
        return person("", 0);
    }

    static size_t instance_count() {
        return s_instance_count;
    }

private:
#pragma region // Static members.
    static size_t s_instance_count; // Prefixing `s_` is a naming convention for static symbols for many.
    // The symbols need not be *`static` class members* specifically!
#pragma endregion

#pragma region // Instance members.
    std::string name;
    unsigned int age;
#pragma endregion

};

int main() {
}
