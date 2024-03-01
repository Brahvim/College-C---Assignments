#include <iostream>
#include <iomanip>
// By the way - I'm following my own naming convention here,
// which I've developed over the years writing code in some languages, mainly Java.

// All methods are `inline`d so that old compilers need not worry.
class IntPointer {

    int *pointer = nullptr;

public:

#pragma region // Constructors.
    IntPointer() {
        this->allocate();
    }

    IntPointer(int p_value) {
        this->allocate();
        this->setValue(p_value);
    }

    IntPointer(int *p_pointer) {
        this->allocate();
        this->setPointer(p_pointer);
    }
#pragma endregion

    ~IntPointer() {
        this->free();
    }

#pragma region // Setters.
    inline void setPointer(int *p_pointer) {
        this->pointer = p_pointer;
    }

    inline void setValue(int p_value) {
        (*this->pointer) = p_value;
    }
#pragma endregion

#pragma region // Getters.
    inline int* getPointer() const { // This doesn't modify the class's members, and is thus `const`.
        return this->pointer;
    }

    inline int getValue() const { // This doesn't modify the class's members, and is thus `const`.
        return (*this->pointer);
    }
#pragma endregion

#pragma region // Pointer status.
    inline bool isDangling() const { // This doesn't modify the class's members, and is thus `const`.
        return this->pointer == nullptr;
    }

    inline bool exists() const { // This doesn't modify the class's members, and is thus `const`.
        return this->pointer != nullptr;
    }
#pragma endregion

#pragma region // Memory management.
    inline bool allocate() {
        if (this->exists())
            return false;

        this->pointer = new int;
        return true;
    }

    inline bool free() {
        if (!this->exists()) {
            delete this->pointer;
            return true;
        }

        return false;
    }
#pragma endregion

    friend std::ostream& operator<<(std::ostream& p_outputStream, const IntPointer& p_this) {
        // The stream will probably be in decimal mode, mostly, so...:
        if (p_outputStream.flags() & std::ios_base::dec) {
            p_outputStream << p_this.getValue();
            return p_outputStream;
        } else if (p_outputStream.flags() & std::ios_base::hex) {
            p_outputStream << p_this.getPointer();
            return p_outputStream;
        }


        return p_outputStream;
    }

};

int main() {
    IntPointer *ptr1; // Remember: No allocation takes place here.
    // We have only declared a pointer to our object.

    {
        IntPointer ptr2(5);
        ptr1 = &ptr2;

        std::hex(std::cout); // We want to print the pointer's memory location!!!
        std::cout << "`ptr1` currently points to `ptr2`(" << ptr1 << ")." << std::endl;
        std::dec(std::cout); // ..Let's go back to where we were...
    }
    // PS `ptr2::~IntPointer()` is called at the ending `}`, which means that the pointer gets deallocated!
    // This 'trick' is used by `std::auto_ptr` and `std::unique_ptr` (the latter is newer and better).

    std::cout << "`ptr1` is now a dangling pointer!" << std::endl;
}
