#include <iostream>

int main() {
    int arr[] = { 2,4,6,8,10 };
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        std::cout << arr[i] << std::endl;
}
