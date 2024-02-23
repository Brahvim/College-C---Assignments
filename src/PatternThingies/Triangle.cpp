#include "BrahvimIoStreamUtils.hpp"

int main() {

    std::cout << "Please enter the width of the base of the triangle: ";
    declare_then_get_via_cin(size_t, base_width);

    for (size_t i = 0; i < base_width; i++) {
        // We print asterisks `i + 1` times:
        for (size_t j = 0; j <= i; j++)
            std::cout << "*";

        std::cout << std::endl;
    }

}
