#include <iostream>
#include <string>

class shape {
public:
    // This is a "virtual method" - one that *can be* overriden. Id est, it is
    // optional to override it, since a default implementation has been provided.
    // It does so using dynamic dispatch (an implementation of the concept of "dynamic binding").
    // It is now a **polymorphic type**, since it has a V-table.
    // ...Do note that **this can be quite slow** since a lookup is involved.
    // Efficiency-focused programming paradigms like data-oriented design often reject it.
    // Later, I'll provide an example of static polymorphism, which has very funny syntax in C++!
    virtual std::string params_as_string() {
        return "";
    }

    // This is a "pure virtual method" - one that must be overriden by a subclass to be called at all.
    // This also means that `shape` is now completely impossible to instantiate!
    virtual void scale(const float amount) = 0;

};

class square : public shape {
private:
    float side_length = 0;

public:
    square(const float p_side_length)
        : side_length(p_side_length) {
    }

    square() { }

    void scale(const float p_amount) final override {
        this->side_length *= p_amount;
    }

    std::string params_as_string() final override {
        return "[ " + std::to_string(this->side_length) + " ]";
    }

};

class circle : public shape {
private:
    float radius = 0;

public:
    circle(const float p_radius)
        : radius(p_radius) {
    }

    circle() { }

    // `final` means that the method may not overriden by and subclasses of this class (`circle`).
    void scale(const float p_amount) final override {
        this->radius *= p_amount;
    }
    // The `override` keyword acts as guard to throw an error to notify us that `shape::scale(float)` is not overridable,
    // if that ever *does* happen. It acts as just a marker to let us know that a method has been overriden, otherwise.

    std::string params_as_string() final override {
        return "[ " + std::to_string(this->radius) + " ]";
    }

};

int main() {
    circle circ1(4);
    square sq1(0.5f);

    shape *shape1 = &sq1;
    shape *shape2 = &circ1;

    // (Attempting a `dynamic_cast<>()` from a pointer to another within a hierarchy:)
    square *sq_ptr = dynamic_cast<square*>(shape1);
    circle *circ_ptr = dynamic_cast<circle*>(shape2);

    if (circ_ptr) { // Same condition as `circ_ptr != 0`.
        std::cout << "Dynamic cast successful! We have a `circle`:" << std::endl;
        std::cout << circ_ptr->params_as_string() << std::endl;
    } else
        std::cout << "Dynamic cast failed: Not a `circle`." << std::endl;

    if (sq_ptr) {
        std::cout << "Dynamic cast successful! We have a `square`:" << std::endl;
        std::cout << sq_ptr->params_as_string() << std::endl;
    } else
        std::cout << "Dynamic cast failed: Not a `square`." << std::endl;
}
