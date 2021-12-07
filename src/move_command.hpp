#ifndef MOVE_COMMAND_HPP
#define MOVE_COMMAND_HPP

#include <string>

enum class Direction { FORWARD, UP, DOWN };

struct MoveCommand {
    Direction direction;
    int distance;
};

bool operator==(MoveCommand const& lhs, MoveCommand const& rhs);

bool operator!=(MoveCommand const& lhs, MoveCommand const& rhs);

std::string toString(MoveCommand const&);

#endif /*MOVE_COMMAND_HPP*/
