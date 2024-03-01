#include <iostream>
#include <string>

using namespace std;

int main() {
    string names[] = { "Brahvim", "Sheetal", "Karan", "Junaid", "Utkarsh" };
    for (auto &s : names)
        cout << s;
}
