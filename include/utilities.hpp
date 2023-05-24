#include "openai.hpp"

#include <boost/algorithm/string.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::string get_line(json response);
std::string send_line(openai::OpenAI& openai, const std::string input_line);
