#include <iostream>

int main() {
    int correct = 5;
    while (!correct) {
        int uin = 0;
        std::cout << "Please enter the value `5`" << std::endl;
        std::cin >> uin;
        correct = uin == 5;
    }
}
