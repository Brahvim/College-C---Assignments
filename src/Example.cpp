#include <iostream>

class triangle {

    int s1, s2, s3;

public:

    int get_side_1() {
        return this->s1;
    }

    int get_side_2() {
        return this->s2;
    }

    int get_side_3() {
        return this->s3;
    }

    bool set_side_1(int p_side) {
        if (p_side > 0) {
            this->s1 = p_side;
            return true;
        }

        return false;
    }

    bool set_side_2(int p_side) {
        if (p_side > 0) {
            this->s2 = p_side;
            return true;
        }

        return false;
    }

    bool set_side_3(int p_side) {
        if (p_side > 0) {
            this->s3 = p_side;
            return true;
        }

        return false;
    }

    int get_area() {
        return this->s1 * this->s2 * this->s3;
    }

};

int main() {
    triangle t;
    std::cout << t.get_side_1();

    if (t.set_side_1(5)) {
        std::cout << "Set triangle side 1 to `5`." << std::endl;
    }

    if (t.set_side_1(-500)) {
        std::cout << "Set triangle side 1 to `-500`." << std::endl;
    }

    std::cout << t.get_side_1();
}
