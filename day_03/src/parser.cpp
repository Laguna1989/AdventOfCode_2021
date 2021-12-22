#include "parser.hpp"
#include <algorithm>
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

std::vector<std::bitset<5>> convert(std::vector<std::string> const& input)
{
    std::vector<std::bitset<5>> result;
    result.resize(input.size());
    std::transform(input.cbegin(), input.cend(), result.begin(),
        [](auto const& str) { return std::bitset<5> { str }; });
    return result;
}
