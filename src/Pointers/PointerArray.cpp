#include <iostream>

int main() {
    float *coordinates = new float[3];

    coordinates[0] = 0.38f;
    coordinates[1] = 654.7f;
    coordinates[2] = 5522.486f;

    // Incrementing the pointer goes to the next element of the type,
    // and does not merely point to the next bit or byte
    // (generally, this is in bytes, and according to the platform's alignment):
    for (int i = 0; i < 3; i++)
        std::cout << coordinates[i] << std::endl; // De-references the string picked.

    delete[] coordinates;
}
