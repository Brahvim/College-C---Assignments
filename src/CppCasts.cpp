#include <iostream>
#include <cmath>

// The C++ programming language introduces **four** new types of casts to ensure that programmers
// do not create unsafe operations when casting using C-style casts' confusing syntax.
// They appear to be implemented using templated functions, but actually use keywords.
// Said 'unsafe operations', most of the time, are edge cases - ones that aren't realized until
// a bug has actually occurred during testing.

struct vec2 {

    float x = 0; float y = 0;

    vec2() { }

    vec2(const float &p_x, const float &p_y): x(p_x), y(p_y) { }

};

struct vec3 : public vec2 {

    float z = 0;

    vec3() { }

    // This is how C++ does it's "`super()`-constructor calls" (like Java!):
    vec3(const float &p_x, const float &p_y, const float &p_z): vec2(p_x, p_y), z(p_z) { }
    // vec2(p_x, p_y); // <-- Could also place it here instead of in the member initializer list.
};

void clear_vec2(vec2 &p_vec2) {
    p_vec2.x = 0;
    p_vec2.y = 0;
}

void clear_vec3(vec3 &p_vec3) {
    p_vec3.x = 0;
    p_vec3.y = 0;
    p_vec3.z = 0;
}

int main() {
    vec2 two;
    vec3 three(6, 4, 5);

    // `static_cast<>()` is used for up/-down casts given a hierarchy of classes:
    clear_vec2(static_cast<vec2&>(three));
    // Even a downcast can be unsafe, *occasionally*, if performed using C-style casts.
    // **It is important to use `static_cast<>()` instead of a C-style cast for downcasting within a hierarchy.**

    // A `const_cast<>()` can add or remove the effects of the `const` keyword:
    const vec3 const_three(6, 4, 5);
    clear_vec3(const_cast<vec3&>(const_three));
    // This throws an error at compile-time otherwise!:
    // clear_vec3(three);

    // ...Now we have `reinterpret_cast<>()`. This cast exists to allow bit-level manipulation of data.
    // The cast is generally performed on pointers, since re-interpretation always generates warnings or errors otherwise.
    // `union`s can be used to perform the same operations as a `reinterpret_cast<>()`, but making a `union` as well as an 
    // instance of it *for each cast we want to perform* is inconvenient and also performs slow. Thus we use the cast.
    // Here's an example:
    double d = 0;
    (*reinterpret_cast<float*>(&d)) = 0xCAFEBABE;
    // Even `clang-tidy` (a linter; a 'static code analysis tool') offers the following
    // "`clang-diagnostic-implicit-const-int-float-conversion`" warning!:
    // ```bash
    // implicit conversion from 'unsigned int' to 'float' changes value from 3405691582 to 3405691648
    // ```
    // PS This bit-level manipulation practice is also called "type punning"!

    //

}
