#include "update_position.hpp"
#include <algorithm>

Transform update_transform(Transform const& transform, TransformCommand command)
{
    if (command.direction == Direction::FORWARD) {
        return Transform { transform.horizontal + command.distance,
            transform.depth + command.distance * transform.aim, transform.aim };
    } else if (command.direction == Direction::DOWN) {
        return Transform { transform.horizontal, transform.depth,
            transform.aim + command.distance };
    }
    return Transform { transform.horizontal, transform.depth, transform.aim - command.distance };
}

Transform update_transform_consecutive(std::vector<TransformCommand> const& move_commands)
{
    Transform end_position {};
    std::for_each(
        move_commands.begin(), move_commands.end(), [&end_position](auto const& move_command) {
            end_position = update_transform(end_position, move_command);
        });
    return end_position;
}
