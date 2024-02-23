#include "BrahvimIoStreamUtils.hpp"

int main() {
    std::cout << "Please enter width of the rectangle: ";
    declare_then_get_via_cin(size_t, width);

    for (size_t i = 0; i < width; i++) {
        // We print asterisks `width` times:
        for (size_t j = 0; j < width; j++)
            std::cout << "*";

        std::cout << std::endl;
    }
}
