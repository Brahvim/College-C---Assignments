#include <iostream>

// In a class, everything is `private` by default:
class int_ptr {

    int *ptr = nullptr; // This is private!

public:
#pragma region // Setters.
    void set_ptr(int *p_ptr) {
        this->ptr = p_ptr;
    }

    void set_val(int p_val) {
        (*this->ptr) = p_val;
    }
#pragma endregion

#pragma region // Getters.
    int* get_ptr() const { // This doesn't modify the class's members, and is thus `const`.
        return this->ptr;
    }

    int get_val() const { // This doesn't modify the class's members, and is thus `const`.
        return (*this->ptr);
    }
#pragma endregion

#pragma region // Pointer status.
    bool dangling() const { // This doesn't modify the class's members, and is thus `const`.
        return this->ptr == nullptr;
    }

    bool exists() const { // This doesn't modify the class's members, and is thus `const`.
        return this->ptr != nullptr;
    }
#pragma endregion

#pragma region // Memory management.
    bool alloc() {
        if (this->ptr)
            return false;

        this->ptr = new int;
        return true;
    }

    bool free() {
        if (this->ptr != nullptr) {
            delete this->ptr;
            return true;
        }

        return false;
    }
#pragma endregion

};

int main() {
    int_ptr ptr;
    std::cout << "`ptr` as a `nullptr` points to: `" << ptr.get_ptr() << "`." << std::endl;

    ptr.alloc();
    ptr.set_val(5);
    std::cout << "`ptr` with an allocation points to: `" << ptr.get_ptr() << "`." << std::endl;

    ptr.free();
    std::cout << "`ptr` has been deallocated." << std::endl;
}
