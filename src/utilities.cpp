#include "openai.hpp"

#include <fstream>
#include <boost/algorithm/string.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

json load_config() {
    std::ifstream file("config.json");
    return json::parse(file);
}

json request_completion(openai::OpenAI& openai, const std::string input_line) {
    json config = load_config();
    json body = {
        {"model", config.value("model", "gpt-3.5-turbo")},
        {"messages", {
            {
                {"role", "user"},
                {"content", "Short, precise answers only."}
            },
            {
                {"role", "user"},
                {"content", input_line}
            }
        }},
        {"max_tokens", config.value("max_tokens", 25)},
        {"temperature", config.value("temperature", 0)},
    };
    return openai.chat.create(body);
}

std::string get_line(json response) {
    std::string output_line = response["choices"][0]["message"]["content"];
    boost::trim(output_line);
    return output_line;
}

std::string send_line(openai::OpenAI& openai, const std::string input_line) {
    auto response = request_completion(openai, input_line);
    return get_line(response);
}
