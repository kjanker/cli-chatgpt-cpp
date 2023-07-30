#ifndef CHAT_SESSION_H
#define CHAT_SESSION_H

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "openai.hpp"


struct Message {
    std::string role;
    std::string content;

    Message(const std::string role, const std::string content);
};

class ChatSession {

private:
    openai::_detail::OpenAI& openai;
    std::string model;
    int max_tokens;
    float temperature;
    std::vector<Message> messages;

public:
    ChatSession(openai::_detail::OpenAI& openai);
    void append(const Message& message);
    void append(const std::string role, const std::string content);
    Message last();
    bool request_response();
    json to_json();
};

#endif
