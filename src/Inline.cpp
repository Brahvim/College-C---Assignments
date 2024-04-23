#include <cmath>
#include <iostream>

// (NOT `constexpr` so the C++ runtime has to explicitly add a value to this thing!:)
const bool g_should_print = rand() % 2 == 0;

// According to the points on Indian education websites like GeeksForGeeks and JavaTPoint, this shouldn't be inlined.
// Why? It has a conditional!
// ...
// Veeery simple (AND SLOW!) `std::string` passed-by-value!
inline void print_global(std::string p_data) { // cppcheck-suppress passedByValue
	if (g_should_print)
		std::cout << p_data << std::endl;
}

// Will be inlined even without the hint! It's a quite simple function after all!:
inline void print(std::string p_data) { // cppcheck-suppress passedByValue
	std::cout << p_data << std::endl;
	print(p_data);
}

int main() {
	print("This string should print regardless!");
	print_global("This string should be visible if `g_should_print` is `true`!");
}