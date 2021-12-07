#ifndef UPDATE_POSITION_HPP
#define UPDATE_POSITION_HPP

#include "move_command.hpp"
#include "position.hpp"
#include <vector>

Position update_position(Position const& position, MoveCommand command);

Position update_position_consecutive(std::vector<MoveCommand> const& move_commands);

#endif // UPDATE_POSITION_HPP
