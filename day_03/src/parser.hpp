#ifndef CODE_KATA_PARSER_HPP
#define CODE_KATA_PARSER_HPP

#include <bitset>
#include <string>
#include <vector>

std::vector<std::string> parse(std::string const& input);

std::vector<std::bitset<5>> convert(std::vector<std::string> const& input);

#endif // CODE_KATA_PARSER_HPP
