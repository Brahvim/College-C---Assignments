#include <iostream>
#include <string>

typedef void (*fxn_t)();

void fxn1();
void fxn2();
void fxn3();
void fxn4();

// Could be done without the `typedef`, but we can't measure the size of each function then:
// void(*const g_functions_list[])() = { fxn1, fxn2, fxn3, fxn4 };
const fxn_t g_functions_list[] = { fxn1, fxn2, fxn3, fxn4 };
const size_t g_functions_list_length = sizeof(g_functions_list) / sizeof(fxn_t);

size_t size = sizeof(void(*));

int main() {
    unsigned short int fxn_id = 0;

    while (!(fxn_id < 5 && fxn_id > 0)) {
        std::cout << "Which of our `4` functions should we call?" << std::endl;
        std::cin >> fxn_id;
    }

    g_functions_list[fxn_id - 1]();
}

#pragma region Functions.
void fxn1() {
    std::cout << "I am function `1`!" << std::endl;
}

void fxn2() {
    std::cout << "I am function `2`!" << std::endl;
}

void fxn3() {
    std::cout << "I am function `3`!" << std::endl;
}

void fxn4() {
    std::cout << "I am function `4`!" << std::endl;
}
#pragma endregion
