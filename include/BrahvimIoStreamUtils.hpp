#include <limits>
#include <iostream>

/** @brief Make sure the buffer is empty! */
#define clear_cin() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

#define declare_then_cin(x) x;   \
std::cin >> x;

#define via_cin(x) x;   \
std::cin >> x;          \
clear_cin();
