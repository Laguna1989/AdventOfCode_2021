#ifndef MOVE_COMMAND_HPP
#define MOVE_COMMAND_HPP

#include <string>

enum class Direction { FORWARD, UP, DOWN };

struct TransformCommand {
    Direction direction;
    int distance;
};

bool operator==(TransformCommand const& lhs, TransformCommand const& rhs);

bool operator!=(TransformCommand const& lhs, TransformCommand const& rhs);

std::string to_string(TransformCommand const&);

Direction direction_from_string(std::string const& direction_string);

#endif /*MOVE_COMMAND_HPP*/
