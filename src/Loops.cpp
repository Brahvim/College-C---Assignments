#include <iostream>

int main() {
    std::cout << "Do you know me? (Y/n)" << std::endl;
    std::cin.ignore();

    switch (std::cin.get()) {
        case 'Y':
        case 'y': {
            std::cout << "I'm a program!" << std::endl;
        } break;
    }

    


}