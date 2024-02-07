#include <limits>
#include <iostream>

std::istream &clear_cin() {
    // Make sure the buffer is empty!:
    return std::cin.ignore(
        // Go as far as a stream can go...:
        // std::numeric_limits<std::streamsize>::max()
        // std::cin.end - std::cin.beg,
        1,
        // ...to find this character!:
        '\n'
    );
}

int main() {
    std::cout << "Do you know me? (Y/n)" << std::endl;
    clear_cin();

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
    clear_cin();
    std::cin >> uin_int;

    std::cout << "You mean `" << uin_int << "`?! Hey, thanks!" << std::endl;

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
