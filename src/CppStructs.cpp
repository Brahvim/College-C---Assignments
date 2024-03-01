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

    ptr.ptr = new int;
    *(ptr.ptr) = 5;

    ptr.deallocate();
}
