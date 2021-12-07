#include "move_command.hpp"

namespace {

std::string to_string(Direction const& direction)
{
    switch (direction) {
    case Direction::FORWARD:
        return "forward";
    case Direction::UP:
        return "up";
    case Direction::DOWN:
        return "down";
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

std::string to_string(MoveCommand const& command)
{
    return "(" + to_string(command.direction) + ", " + std::to_string(command.distance) + ")";
}

Direction direction_from_string(std::string const& direction_string)
{
    Direction direction { Direction::FORWARD };
    if (direction_string == "forward") {
        direction = Direction::FORWARD;
    } else if (direction_string == "up") {
        direction = Direction::UP;
    } else if (direction_string == "down") {
        direction = Direction::DOWN;
    }
    return direction;
}
