#include "BrahvimIoStreamUtils.hpp"
#define PATTERN_CHAR '*'

int main() {
    std::cout << "Please enter the maximum width of the diamond: ";
    declare_then_get_via_cin(size_t, max_width);

    if (max_width == 2) {
        std::cout << R"(
  *
 ***
*****
 ***
  *
        )";
        std::exit(0);
    }

    for (size_t i = 0; i < max_width; i++) {
        const size_t reverse = max_width - i;

        for (size_t j = 0; j <= reverse; j++)
            std::cout << ' ';

        for (size_t j = 0; j <= i; j++)
            std::cout << PATTERN_CHAR;

        for (size_t j = 0; j <= i; j++)
            std::cout << PATTERN_CHAR;

        std::cout << std::endl;
    }

    for (size_t i = max_width; i > 0; i--) {
        const size_t reverse = max_width - i;

        for (size_t j = 0; j <= reverse; j++)
            std::cout << ' ';

        for (size_t j = 0; j <= i; j++)
            std::cout << PATTERN_CHAR;

        for (size_t j = 0; j <= i; j++)
            std::cout << PATTERN_CHAR;

        std::cout << std::endl;
    }

    // Want some bandages?:
    // std::cout << "***";
    // std::cout << "**";
}
