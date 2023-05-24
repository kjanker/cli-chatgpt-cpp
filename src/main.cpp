#include "openai.hpp"
#include "utilities.hpp"

#include <iostream>
#include <string>

int main() {
    auto& openai = openai::start();

    auto msg = "< How can I help you?";
    std::cout << msg << std::endl << "> ";

    for (std::string input_line; std::getline(std::cin, input_line); std::cout << "> ") {
        auto output_line = send_line(openai, input_line);
        std::cout << "< " << output_line << std::endl;
    }
}
