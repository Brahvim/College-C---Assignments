#include <iostream>

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
    std::cin >> uin_int;

    std::cout << "You mean `" << uin_int << "`?! Hey! Thanks!" << std::endl;

    if (uin_int == 0) {
        std::cout << "I also see that it's zero!" << std::endl;
        goto bye_bye; // This uses a `goto`-label.
    } else {
        const bool below_zero = uin_int < 0;
        const int loop_update_amount = below_zero ? -1 : 1; // Use of the ternary operator.
        std::cout << "In fact, I can count to it like so:" << std::endl;

        const int limit = uin_int + (below_zero ? 1 : -1); // Limit for the loop.
        for (int i = 0;
            below_zero ? i > limit : i < limit;
            // ^^^ If counting down, we need to check the other way around!
            i += loop_update_amount)
            std::cout << i << ", ";
        std::cout << uin_int << "." << std::endl;
    }

bye_bye: // Example of a `goto`-label!
    std::cout << "Bye-bye!" << std::endl;
}
