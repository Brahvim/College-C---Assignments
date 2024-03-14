#include <type_traits>
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <any>

void exit_if_closed(const std::basic_fstream<char>& p_stream, const std::string& p_message) {
    if (!p_stream.is_open()) {
        std::cerr << p_message << std::endl;
        std::exit(EXIT_FAILURE);
    }
}


std::tuple<std::string, int> create_person() {
    return { "Brahvim", 17 };
}

int main() {
    std::ifstream reader("example.txt");
    std::ofstream writer("example.txt");

    std::any a = 6;
    a = 6.0f;
    a = "";

    // exit_if_closed(writer, "");
    writer << "My name is Brahvim!" << std::endl;
    writer.close();
}
