#include "parser.hpp"
#include <sstream>

std::vector<std::string> parse(std::string const& input)
{
    std::stringstream str;
    str << input;

    std::vector<std::string> result;
    std::string line;
    while (std::getline(str, line)) {
        result.push_back(line);
    }

    return result;
}
