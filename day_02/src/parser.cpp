#include "parser.hpp"
#include <regex>
#include <sstream>

TransformCommand parse_input_line(std::string const& input)
{
    std::regex const pattern { "(\\w+) (\\d+)" };
    std::smatch match;
    std::regex_search(input, match, pattern);
    auto const& direction_string = match[1];

    auto const direction = direction_from_string(direction_string);
    auto const distance = std::stoi(match[2]);
    return TransformCommand { direction, distance };
}

std::vector<TransformCommand> parse_input(std::string const& input)
{
    std::vector<TransformCommand> commands;

    std::stringstream str { input };
    std::string line;
    while (std::getline(str, line)) {
        commands.push_back(parse_input_line(line));
    }

    return commands;
}
