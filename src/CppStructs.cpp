#include <iostream>

struct IntPointer {

    // All members are `public` by default,
    // so that `struct`s can exist without methods and work like they did in C.

    // Stores the pointer passed.
    int *ptr;

    void deallocate() {
        if (ptr != nullptr)
            delete ptr;
    }

};

int main() {
    IntPointer ptr;
    std::cout << "`ptr` as a wild pointer points to: `" << ptr.ptr << "`." << std::endl;

    ptr.ptr = new int;
    *(ptr.ptr) = 5;
    std::cout << "`ptr` with an allocation points to: `" << ptr.ptr << "`." << std::endl;

    ptr.deallocate();
    std::cout << "`ptr` has been deallocated.`" << std::endl;
}
