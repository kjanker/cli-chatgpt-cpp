#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

json load_config() {
    std::ifstream file("config.json");
    return json::parse(file);
}
