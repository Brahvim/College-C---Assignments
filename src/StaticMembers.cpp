#include <iostream>

class person {

private:
#pragma region // Fields.
#pragma region // Static members.
	static size_t s_instance_count = 0; // Prefixing `s_` is a naming convention for static symbols for many.
	// The symbols need not be *`static` class members* specifically!
#pragma endregion

#pragma region // Instance members.
	std::string name;
	unsigned int age;
#pragma endregion
#pragma endregion

public:
	person(std::string p_name, int p_age): name(p_name), age(p_age) { // cppcheck-suppress passedByValue

	}

#pragma region // Static methods.
	static person create_null() {
		return person("", 0);
	}

	static size_t instance_count() {
		return s_instance_count;
	}
#pragma endregion

#pragma region // Getters.
	unsigned int get_age() const {
		return age;
	}

	std::string get_name() const {
		return name;
	}
#pragma endregion

#pragma region // Setters.
	void set_age(unsigned int p_new_age) {
		age = p_new_age;
	}

	void set_name(const std::string& p_new_name) {
		name = p_new_name;
	}
#pragma endregion

};

int main() {
	const person person1("Brahvim", 17);              // cppcheck-suppress unreadVariable
	const person person2 = person::create_null();     // cppcheck-suppress unreadVariable

	std::cout << "Number of people: " << person::instance_count() << std::endl;
}
