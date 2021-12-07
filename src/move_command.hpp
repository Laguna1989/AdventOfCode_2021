#ifndef MOVE_COMMAND_HPP
#define MOVE_COMMAND_HPP

enum class Direction { FORWARD };

struct MoveCommand {
    Direction direction;
    int distance;
};

bool operator==(MoveCommand const& lhs, MoveCommand const& rhs);

bool operator!=(MoveCommand const& lhs, MoveCommand const& rhs);

#endif /*MOVE_COMMAND_HPP*/
