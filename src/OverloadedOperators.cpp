#include <iostream>
#include <string>

// I use this style instead of using `struct`s since it makes
// "C-style folks" have less to worry about when using C++ `struct`s:
class Person {
public: // I leave the first line empty in classes, but C++ requires this keyword.
    // ...I'll just change my style to adjust to it.

#pragma region // Custom types.
    // Should've been `size_t`...?
    typedef unsigned int age_t;

    // Should really be `std::u8string`.
    typedef std::string name_t;

    // Not using enums (`enum class`es, specifically) here.
    // Enjoy having the nature you WANT!
    typedef std::string nature_t;
#pragma endregion

#pragma region // Fields and constructor.
    Person::age_t age;
    Person::name_t name;
    Person::nature_t nature;

    Person(
        Person::name_t p_name,
        Person::age_t p_age,
        Person::nature_t p_nature)
        : age(p_age), name(p_name), nature(p_nature) {
    }
#pragma endregion 

    // `std::cout::<<` overload:
    friend std::ostream& operator<<(std::ostream& p_output_stream, const Person& p_this) {
        p_output_stream
            << "Person: [ "
            << p_this.name
            << ", "
            << p_this.age
            << ", "
            << p_this.nature
            << " ]";

        return p_output_stream;
    }

};

int main() {
    std::cout << "Fields in this object are: `" << Person("Brahvim", 17, "nerdy") << "`.";
}
