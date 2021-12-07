#ifndef GUARD_PARSER_HPP
#define GUARD_PARSER_HPP

#include "move_command.hpp"
#include <string>
#include <vector>

MoveCommand parse_input_line(std::string const& input);

std::vector<MoveCommand> parse_input(std::string const& input);

#endif
