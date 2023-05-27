#ifndef CHAT_SESSION_H
#define CHAT_SESSION_H

#include <nlohmann/json.hpp>
using json = nlohmann::json;


struct Message {
    std::string role;
    std::string content;

    Message(const std::string role, const std::string content);
};

class ChatSession {

private:
    std::vector<Message> messages;

public:
    void append(const Message& message);
    void append(const std::string role, const std::string content);
    json to_json();
};

#endif
