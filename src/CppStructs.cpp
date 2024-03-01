#include <iostream>

struct int_ptr {

    // All members are `public` by default,
    // so that `struct`s can exist without methods and work like they did in C.

    // Stores the pointer passed.
    int *ptr;

    void free() {
        if (this->ptr != nullptr)
            delete this->ptr;
    }

};

int main() {
    int_ptr ptr;
    std::cout << "`ptr` as a wild pointer points to: `" << ptr.ptr << "`." << std::endl;

    ptr.ptr = new int;
    *(ptr.ptr) = 5;
    std::cout << "`ptr` with an allocation points to: `" << ptr.ptr << "`." << std::endl;

    ptr.free();
    std::cout << "`ptr` has been deallocated." << std::endl;
}
