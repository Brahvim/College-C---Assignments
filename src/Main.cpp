#include <limits>
#include <iostream>

std::istream &clear_cin() {
    return std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::cout << "Do you know me? (Y/n)" << std::endl;
    std::cin.ignore(); // Make sure the buffer is empty!

    // Using a `switch`-statement:
    switch (std::cin.get()) {
        case 'Y':
        case 'y': {
            // Nothing here :>
        } break;
        default: {
            std::cout << "Wait, you don't? I'm a program!" << std::endl;
        } break;
    }

    int uin_int = 0;
    std::cout << "Mind entering a `" << sizeof(int) << "`-byte integer?" << std::endl;
    std::cin.ignore(); // Make sure the buffer is empty!
    std::cin >> uin_int;

    std::cout << "You mean `" << uin_int << "`?! Hey! Thanks!" << std::endl;

    if (uin_int == 0) {
        std::cout << "I also see that it's zero!" << std::endl;
        goto bye_bye; // This uses a `goto`-label.
    } else {
        const bool below_zero = uin_int < 0;
        std::cout << "In fact, I can count to it like so:" << std::endl;

        const int limit = uin_int + (below_zero ? 1 : -1); // Limit for the loop.
        // This uses another conditional - the ternary operator!

        int i = 0; // Iteration accumulator.
        if (below_zero) {
            // We're counting till an `int`, so I'll use that type here.
            while (1) {
                if (i < limit)
                    break;
                std::cout << --i << ", ";
            }
        } else {
            // When counting down, we need to check the other way around!:
            while (1) {
                if (i > limit)
                    break;
                std::cout << ++i << ", ";
            }
        }

        std::cout << uin_int << "." << std::endl;
    }

bye_bye: // Example of a `goto`-label!
    std::cout << "Bye-bye!" << std::endl;
}
