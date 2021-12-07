#include "move_command.hpp"

namespace {

std::string to_string(Direction const& direction)
{
    switch (direction) {
    case Direction::FORWARD:
        return "FORWARD";
    case Direction::UP:
        return "UP";
    case Direction::DOWN:
        return "DOWN";
    default:
        return "";
    }
}

} // namespace

bool operator==(MoveCommand const& lhs, MoveCommand const& rhs)
{
    return lhs.direction == rhs.direction && lhs.distance == rhs.distance;
}

bool operator!=(MoveCommand const& lhs, MoveCommand const& rhs) { return !(lhs == rhs); }

std::string toString(MoveCommand const& command)
{
    return "(" + to_string(command.direction) + ", " + std::to_string(command.distance) + ")";
}
