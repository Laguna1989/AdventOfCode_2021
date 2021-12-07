#include "move_command.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(MoveCommandTest, ComparisonEquals)
{
    MoveCommand const a { Direction::FORWARD, 5 };
    MoveCommand const b { Direction::FORWARD, 5 };

    ASSERT_EQ(a, b);
}

TEST(MoveCommandTest, ComparisonNotEquals)
{
    MoveCommand const a { Direction::FORWARD, 5 };
    MoveCommand const b { Direction::FORWARD, 8 };

    ASSERT_NE(a, b);
}
