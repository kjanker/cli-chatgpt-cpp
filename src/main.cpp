#include "openai.hpp"
#include "chatsession.hpp"

#include <iostream>
#include <string>


int main() {
    auto& openai = openai::start();
    ChatSession session(openai);

    Message welcome = session.request_response();
    std::cout << welcome.content << std::endl << "> ";

    for (std::string input_line; std::getline(std::cin, input_line); std::cout << "> ") {
        session.append("user", input_line);
        Message response = session.request_response();
        std::cout << "< " << response.content << std::endl;
    }
};
