#include <iostream>
#include <cmath>

struct vec2 {
    float x; float y;
};

struct vec3 : public vec2 {
    float z;
};

void init_vec2(vec2 &p_vec2) {
    p_vec2.x = 0;
    p_vec2.y = 0;
}

void init_vec3(vec3 &p_vec3) {
    p_vec3.x = 0;
    p_vec3.y = 0;
    p_vec3.z = 0;
}

int main() {
    vec2 two;
    vec3 three;
    const double d = 0.5f; // This, is an "implicit cast". The compiler is aware that we're doing this, and allows it.

    init_vec2(three); // `vec3` is a subclass of `vec2`, thus, a `vec3` is also a `vec2`!
    // This is called an "upcast".

    // Here, is an 'explicit' cast, which we have to perform ourselves, just like C does:
    init_vec3((vec3&)two); // Could cause a crash at runtime, since `two::z` does not exist.
    // For all we know, this *is* undefined behavior.
    // What we did here, is called a "downcast".
}
