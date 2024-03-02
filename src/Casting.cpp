#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "This text will be erased in a moment..." << std::flush;
    
    // Wait for a moment (you can replace this with your logic)
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // Move the cursor back to the beginning of the line and overwrite with spaces
    std::cout << "\r";
    for (int i = 0; i < 40; ++i) {
        std::cout << ' ';
    }
    std::cout << "\r";
    
    std::cout << "Text erased!" << std::endl;
    
    return 0;
}