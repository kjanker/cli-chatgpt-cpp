#include "chatsession.hpp"
#include "utilities.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;


Message::Message(const std::string role, const std::string content) : role(role), content(content) {};


ChatSession::ChatSession(openai::_detail::OpenAI& openai) : openai(openai) {
    json config = load_config();
    this->model = config.value("model", "gpt-3.5-turbo");
    this->max_tokens = config.value("max_tokens", 25);
    this->temperature = config.value("temperature", 0);
    this->append("system", config.value("prior", "Your role is to be decisive and give very short, precise answers to assist the user."));
};

void ChatSession::append(const Message& message) {
    messages.push_back(message);
};

void ChatSession::append(const std::string role, const std::string content) {
    Message message(role, content);
    this->append(message);
};

Message ChatSession::last() {
    return this->messages.back();
};

bool ChatSession::request_response() {
    json body = {
        {"model", this->model},
        {"messages", this->to_json()},
        {"max_tokens", this->max_tokens},
        {"temperature", this->temperature},
    };
    auto response = this->openai.chat.create(body);
    json choice = response["choices"][0];
    json m = choice["message"];
    Message msg(m["role"], m["content"]);
    this->append(msg);
    // finish_reason can be 'length' and 'stop'.
    return (choice["finish_reason"] == "length");
};

json ChatSession::to_json() {
    json jsonData;
    for (const auto& message : messages) {
        json messageData;
        messageData["role"] = message.role;
        messageData["content"] = message.content;
        jsonData.push_back(messageData);
    }
    return jsonData;
};
