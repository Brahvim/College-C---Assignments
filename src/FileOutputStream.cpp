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
    if (p_stream) // This is not a `nullptr` check!
        return; // Look up `std::ofstream::operator bool`!

    std::cerr << p_message << std::endl;
    std::exit(EXIT_FAILURE);
}

std::tuple<std::string, int> create_person() { return { "Brahvim", 17 }; }

int main() {
    std::ifstream reader("example.txt");
    std::ofstream writer("example.txt");

    // If the stream couldn't be opened, exit!:
    exit_if_closed(reader, "The reader went, \"Uh-oh!\"...");
    exit_if_closed(writer, "The writer went, \"Uh-oh!\"...");

    writer << "My name is Brahvim!" << std::endl;
    writer << "A is for Apple!" << std::endl;
    writer.close();

    std::cout << "File contents!:" << std::endl;
    std::cout << "---------------" << std::endl;

    while (reader) { // ...If we have something to read, READ!!!:
        std::string line;
        reader >> line;
        std::cout << line << ' ';
    }
    std::cout << std::endl;

    reader.close();
    std::cout << "---------------------------" << std::endl;
    std::cout << "(File contents have ended.)" << std::endl;
}
