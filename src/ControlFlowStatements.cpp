#include <limits>
#include <iostream>

/** @brief Make sure the buffer is empty! */
// #define clear_cin() std::cin.ignore(); // std::numeric_limits<std::streamsize>::max(), '\n');
#define clear_cin() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

int main() {
	std::cout << "Do you know me? (Y/n): ";
	// Using a `switch`-statement:
	switch (std::cin.get()) {
		case 'Y':
		case 'y': {
			// Nothing here :>
		} break;

		default: {
			std::cout << "It seems you don't. Hi there, I'm a program!" << std::endl;
		} break;
	}
	// Call after an `std::cin` operation:
	clear_cin();

	int uin_int = 0;
	std::cout << "Mind entering a `" << sizeof(int) << "`-byte integer?: ";
	std::cin >> uin_int;
	clear_cin();

	std::cout << "You mean `" << uin_int << "`?! Hey, thanks!" << std::endl;

	if (uin_int == 0) {
		std::cout << "I can even tell that it's zero!" << std::endl;
		goto bye_bye; // This uses a `goto`-label.
	} else {
		const bool below_zero = uin_int < 0;
		std::cout << "I can even count to it like so!: ";

		const int limit = uin_int + (below_zero ? 1 : -1); // Limit for the loop.
		// This uses another conditional - the ternary operator!

		int i = 0; // Iteration accumulator.
		if (below_zero) {
			// We're counting till an `int`, so I'll use that type here.
			while (1) {
				if (i < limit)
					break; // Showcasing `break` here.
				std::cout << i-- << ", ";
			}
		} else {
			while (1) {
				// When counting down, we'll need to check the other way around!:
				if (i > limit)
					break;
				std::cout << i++ << ", ";
			}
		}

		// ...A fullstop for the effect:
		std::cout << uin_int << "." << std::endl;
	}

bye_bye: // Example of a `goto`-label!
	std::cout << "Bye-bye!" << std::endl;
}
