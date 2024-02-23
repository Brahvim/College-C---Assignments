#include "BrahvimIoStreamUtils.hpp"

int main() {

    // std::cout << "Please enter the maximum width of the diamond: ";
    // declare_then_get_via_cin(size_t, max_width);
    size_t max_width = 4;

    for (size_t i = max_width; i > 0; i--) {
        // We print asterisks `i + 1` times:
        for (size_t j = 0; j <= i; j++)
            std::cout << " ";

        std::cout << "*";
        for (size_t j = 0; j < max_width; j++)
            std::cout << " ";

        // for (size_t j = max_width; j > i; j--)
        //     std::cout << " ";

        for (size_t j = 0; j < max_width; j++)
            std::cout << " ";

        std::cout << "*" << std::endl;
    }

}
