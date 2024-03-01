#include <iostream>
#include <string>

int main() {
    std::cout << "Enter something." << std::endl;
    std::string uin;

    std::getline(std::cin, uin);

    std::cout << "The string is store in memory at `" << &uin << "`." << std::endl;
}
