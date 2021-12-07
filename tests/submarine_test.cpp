#include "move_command.hpp"
#include "position.hpp"
#include <gtest/gtest.h>

Position update_position(Position const&, MoveCommand command) { return Position { 1, 0 }; }

TEST(UpdatePositionTest, Forward1)
{
    MoveCommand const command { Direction::FORWARD, 1 };
    Position pos { 0, 0 };

    auto const updatedPosition = update_position(pos, command);
    auto const expectedPosition = Position { 1, 0 };
    ASSERT_EQ(updatedPosition, expectedPosition);
}
