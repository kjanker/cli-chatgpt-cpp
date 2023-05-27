#include "openai.hpp"
#include "utilities.hpp"
#include "chatsession.hpp"

#include <iostream>
#include <string>


int main() {
    auto& openai = openai::start();

    ChatSession session;

    auto msg = "< How can I help you?";
    std::cout << msg << std::endl << "> ";

    for (std::string input_line; std::getline(std::cin, input_line); std::cout << "> ") {

        session.append("user", input_line);

        auto output_line = send_chat(openai, session.to_json());

        session.append("assistant", output_line);

        std::cout << "< " << output_line << std::endl;
    }
}
