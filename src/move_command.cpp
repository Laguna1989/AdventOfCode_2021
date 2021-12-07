#include "move_command.hpp"

bool operator==(MoveCommand const& lhs, MoveCommand const& rhs)
{
    return lhs.direction == rhs.direction && lhs.distance == rhs.distance;
}

bool operator!=(MoveCommand const& lhs, MoveCommand const& rhs) { return !(lhs == rhs); }

std::string toString(MoveCommand const& command)
{
    return "(FORWARD, " + std::to_string(command.distance) + ")";
}
