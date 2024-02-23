#include <limits>
#include <iostream>

/** @brief Make sure the buffer is empty! */
void inline clear_cin() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

#define get_via_cin(x)  \
std::cin >> x;          \
clear_cin();

#define declare_then_get_via_cin(type, var_name)    \
type var_name;                                      \
std::cin >> var_name;                               \
clear_cin();
