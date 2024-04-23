#include <iostream>

class person {

private:
#pragma region // Fields.
#pragma region // Static members.
    static size_t s_instance_count; // Prefixing `s_` is a naming convention for static symbols for many.
    // The symbols need not be *`static` class members* specifically!
#pragma endregion

#pragma region // Instance members.
    std::string name;
    unsigned int age;
#pragma endregion
#pragma endregion

public:
    person(std::string name, int age);

#pragma region // Static methods.
    static person create_null();

    static size_t instance_count();
#pragma endregion

    // `std::cout::<<` overload:
    friend std::ostream& operator<<(std::ostream& output_stream, const person& person);

#pragma region // Getters.
    unsigned int get_age() const;

    std::string get_name() const;
#pragma endregion

#pragma region // Setters.
    void set_age(unsigned int new_age);

    void set_name(const std::string new_name); // cppcheck-suppress passedByValue
#pragma endregion

};
