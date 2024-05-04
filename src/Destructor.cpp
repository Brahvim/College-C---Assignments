#include <iostream>

// By the way - I'm following the Microsoft naming convention here.
// All methods are inlined so that old compilers need not worry.

class IntPointer {

    int *pointer = nullptr;

public:

    ~IntPointer() {
        Free();
    }

#pragma region // Setters.
    inline void SetPointer(int *_Ptr) {
        pointer = _Ptr;
    }

    inline void SetValue(int _Val) {
        (*pointer) = _Val;
    }
#pragma endregion

#pragma region // Getters.
    inline int* GetPointer() const { // This doesn't modify the class's members, and is thus `const`.
        return pointer;
    }

    inline int GetValue() const { // This doesn't modify the class's members, and is thus `const`.
        return (*pointer);
    }
#pragma endregion

#pragma region // Pointer status.
    inline bool IsDangling() const { // This doesn't modify the class's members, and is thus `const`.
        return pointer == nullptr;
    }

    inline bool Exists() const { // This doesn't modify the class's members, and is thus `const`.
        return pointer != nullptr;
    }
#pragma endregion

#pragma region // Memory management.
    inline bool Allocate() {
        if (Exists())
            return false;

        pointer = new int;
        return true;
    }

    inline bool Free() {
        if (!Exists()) {
            delete pointer;
            return true;
        }

        return false;
    }
#pragma endregion

};

int main() {
    IntPointer ptr;
    std::cout << "`ptr` as a `nullptr` points to: `" << ptr.GetPointer() << "`." << std::endl;

    ptr.Allocate();
    ptr.SetValue(5);
    std::cout << "`ptr` with an allocation points to: `" << ptr.GetPointer() << "`." << std::endl;

    ptr.Free();
    std::cout << "`ptr` has been deallocated." << std::endl;
}
