#include <iostream>
// By the way - I'm following the Microsoft naming convention here.

// All methods are `inline`d so that old compilers need not worry.
class IntPointer {

    int *m_Pointer = nullptr;

public:

    ~IntPointer() {
        Free();
    }

#pragma region // Setters.
    inline void SetPointer(int *_Ptr) {
        m_Pointer = _Ptr;
    }

    inline void SetValue(int _Val) {
        (*m_Pointer) = _Val;
    }
#pragma endregion

#pragma region // Getters.
    inline int* GetPointer() const { // This doesn't modify the class's members, and is thus `const`.
        return m_Pointer;
    }

    inline int GetValue() const { // This doesn't modify the class's members, and is thus `const`.
        return (*m_Pointer);
    }
#pragma endregion

#pragma region // Pointer status.
    inline bool IsDangling() const { // This doesn't modify the class's members, and is thus `const`.
        return m_Pointer == nullptr;
    }

    inline bool Exists() const { // This doesn't modify the class's members, and is thus `const`.
        return m_Pointer != nullptr;
    }
#pragma endregion

#pragma region // Memory management.
    inline bool Allocate() {
        if (Exists())
            return false;

        m_Pointer = new int;
        return true;
    }

    inline bool Free() {
        if (!Exists()) {
            delete m_Pointer;
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
