#include <iostream>

/**
 * @brief Creates two `float` arrays with `3` `float`s each.
 * @return A pointer to the arrays.
 */
float** get_coords() {
    // Allocate an array of arrays on the heap:
    float **to_ret = new float*[2];

    // Fill the array with arrays containing data:
    to_ret[0] = new float[] { 54.6f, 7.543f, 935.4f };
    to_ret[1] = new float[] { 768.5f, 6.84f, 98.468f };

    // Give it away, expecting a deallocation later:
    return to_ret;
}

int main() {
    float **coords = get_coords();

    for (int i = 0; i < 2; i++) {
        std::cout << "[ ";
        for (int j = 0; j < 3; j++)
            std::cout << coords[i][j] << (j == 2 ? " ]" : ", ");
        std::cout << std::endl;
    }

    // Delete the inner arrays:
    for (int i = 0; i < 3; i++)
        delete[] coords[i];

    // Delete the outer array:
    delete[] coords;

    // Both were allocated for separately, and so, must be deleted that way, too.
}
