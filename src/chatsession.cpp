#include "chatsession.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;


Message::Message(const std::string role, const std::string content) : role(role), content(content) {};


void ChatSession::append(const Message& message) {
    messages.push_back(message);
};

void ChatSession::append(const std::string role, const std::string content) {
    Message message(role, content);
    this->append(message);
};

json ChatSession::to_json() {
    json jsonData;
    for (const auto& message : messages) {
        json messageData;
        messageData["role"] = message.role;
        messageData["content"] = message.content;
        // Add additional message properties to 'messageData' if needed
        jsonData.push_back(messageData);
    }
    return jsonData;
};
