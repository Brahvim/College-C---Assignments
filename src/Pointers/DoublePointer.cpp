#include <iostream>

/**
 * @brief Creates two `float` arrays with `3` `float`s each.
 * @return A pointer to the arrays.
 */
float** get_coords() {
    float **to_ret = new float*[2];

    to_ret[0] = new float[] { 54.6f, 7.543f, 935.4f };
    to_ret[1] = new float[] { 768.5f, 6.84f, 98.468f };

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
}
