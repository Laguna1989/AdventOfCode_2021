#ifndef GUARD_PARSER_HPP
#define GUARD_PARSER_HPP

#include "transform_command.hpp"
#include <string>
#include <vector>

TransformCommand parse_input_line(std::string const& input);

std::vector<TransformCommand> parse_input(std::string const& input);

#endif
