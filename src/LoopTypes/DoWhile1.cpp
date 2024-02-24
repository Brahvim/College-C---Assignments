#include <iostream>

void task_to_do_at_least_once() {
    std::cout << "(This task was supposed to be done at least once in a loop.)" << std::endl;
}

int main() {
    int condition = 0;
    do {
        task_to_do_at_least_once();
    } while (condition);
}
