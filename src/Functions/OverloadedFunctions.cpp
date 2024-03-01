#include <iostream>

void print() {
    std::cout << std::endl;
}

void print(int p_value) {
    std::cout << p_value;
}

void print(float p_value) {
    std::cout << p_value;
}

float print(float p_first, float p_second) {
    std::cout << p_first << ", " << p_second;
    return p_first + p_second;
}

int main() {
    print(3.14f);
    print();

    print(5);
    print();

    print(3.5f, 2);
}
