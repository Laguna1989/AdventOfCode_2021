#include "update_position.hpp"
#include <algorithm>

Position update_position(Position const& position, MoveCommand command)
{
    if (command.direction == Direction::FORWARD) {
        return Position { position.x + command.distance, position.y };
    } else if (command.direction == Direction::DOWN) {
        return Position { position.x, position.y + command.distance };
    }
    return Position { position.x, position.y - command.distance };
}

Position update_position_consecutive(std::vector<MoveCommand> const& move_commands)
{
    Position end_position {};
    std::for_each(
        move_commands.begin(), move_commands.end(), [&end_position](auto const& move_command) {
            end_position = update_position(end_position, move_command);
        });
    return end_position;
}
