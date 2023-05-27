#include "openai.hpp"

#include <boost/algorithm/string.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::string send_line(openai::OpenAI& openai, const std::string input_line);
std::string send_chat(openai::OpenAI& openai, const json& messages);
