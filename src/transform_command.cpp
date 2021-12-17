#include "transform_command.hpp"

namespace {

std::string to_string(Direction const& direction)
{
    if (direction == Direction::FORWARD) {
        return "forward";
    }
    if (direction == Direction::UP) {
        return "up";
    }
    if (direction == Direction::DOWN) {
        return "down";
    }
    return "";
}

} // namespace

bool operator==(TransformCommand const& lhs, TransformCommand const& rhs)
{
    return lhs.direction == rhs.direction && lhs.distance == rhs.distance;
}

bool operator!=(TransformCommand const& lhs, TransformCommand const& rhs) { return !(lhs == rhs); }

std::string to_string(TransformCommand const& command)
{
    return "(" + to_string(command.direction) + ", " + std::to_string(command.distance) + ")";
}

Direction direction_from_string(std::string const& direction_string)
{
    if (direction_string == "up") {
        return Direction::UP;
    }
    if (direction_string == "down") {
        return Direction::DOWN;
    }
    return Direction::FORWARD;
}
