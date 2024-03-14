#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

void exit_if_closed(const std::ifstream &p_stream, const std::string_view &p_message) {
    if (p_stream.is_open())
        return;

    std::cerr << p_message << std::endl;
    std::exit(EXIT_FAILURE);
}

void exit_if_closed(const std::ofstream &p_stream, const std::string_view &p_message) {
    if (p_stream.is_open())
        return;

    std::cerr << p_message << std::endl;
    std::exit(EXIT_FAILURE);
}

std::tuple<std::string, int> create_person() { return { "Brahvim", 17 }; }

int main() {
    std::ifstream reader("example.txt");
    std::ofstream writer("example.txt");

    exit_if_closed(writer, "");
    writer << "My name is Brahvim!" << std::endl;
    writer.close();
}
