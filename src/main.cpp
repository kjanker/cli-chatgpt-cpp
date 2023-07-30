#include "openai.hpp"
#include "chatsession.hpp"

#include <iostream>
#include <string>


int main() {
    auto& openai = openai::start();
    ChatSession session(openai);

    session.request_response();
    std::cout << session.last().content << std::endl << "> ";

    for (std::string input_line; std::getline(std::cin, input_line); std::cout << "> ") {
        session.append("user", input_line);
        bool response_unfinished = session.request_response();
        std::cout << "< " << session.last().content;
        if (response_unfinished) {
            std::cout << " [...]" << std::endl << "Continue? (y/n)";
            char response;
            std::cin >> response;

            // Clear the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            
            if (response == 'y'){
                bool response_unfinished = session.request_response();
                std::cout << "[...] " << session.last().content;
            };
        };
        std::cout << std::endl;
    }
};
