#include "StaticMembers.hpp"

// Need to initialize this, ...here???!!:
size_t person::s_instance_count = 0;

person::person(std::string p_name, int p_age)
	: name(p_name), age(p_age) {
	++s_instance_count; // Use the prefixed one.
	// The postfix one creates a copy.
	// Obviously your compiler optimizes it! But...
	// REMEMBER MIKE ACTON'S 2014 TALK!
}

#pragma region // Static methods.
person person::create_null() {
	return person("", 0);
}

size_t person::instance_count() {
	return s_instance_count;
}
#pragma endregion

#pragma region // Getters.
unsigned int person::get_age() const {
	return this->age;
}

std::string person::get_name() const {
	return this->name;
}
#pragma endregion

#pragma region // Setters.
void person::set_age(unsigned int p_new_age) {
	this->age = p_new_age;
}

void person::set_name(const std::string p_new_name) {
	this->name = p_new_name;
}
#pragma endregion

int main() {
	const person person1("Brahvim", 17);
	const person person2 = person::create_null();

	std::cout << "Population: " << person::person::instance_count() << std::endl;
	std::cout << "People: " << std::endl;
	std::cout << person1 << std::endl;
	std::cout << person2 << std::endl;
}
