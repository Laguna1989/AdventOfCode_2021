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

class MoveCommandParametrizedTestFixture
    : public ::testing::TestWithParam<std::pair<MoveCommand, std::string>> {
};

TEST_P(MoveCommandParametrizedTestFixture, CorrectToString)
{
    auto const command = GetParam().first;
    auto const expected_string = GetParam().second;
    ASSERT_EQ(toString(command), expected_string);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandParametrizedTest, MoveCommandParametrizedTestFixture,
    ::testing::Values(std::make_pair(MoveCommand { Direction::FORWARD, 10 }, "(FORWARD, 10)"),
        std::make_pair(MoveCommand { Direction::FORWARD, 5 }, "(FORWARD, 5)")));
