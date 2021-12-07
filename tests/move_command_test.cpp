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

class MoveCommandParameterizedValidTestFixture
    : public ::testing::TestWithParam<std::pair<MoveCommand, std::string>> {
};

TEST_P(MoveCommandParameterizedValidTestFixture, CorrectToString)
{
    auto const command = GetParam().first;
    auto const expected_string = GetParam().second;
    ASSERT_EQ(toString(command), expected_string);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandParameterizedTest, MoveCommandParameterizedValidTestFixture,
    ::testing::Values(std::make_pair(MoveCommand { Direction::FORWARD, 10 }, "(FORWARD, 10)"),
        std::make_pair(MoveCommand { Direction::UP, 3 }, "(UP, 3)"),
        std::make_pair(MoveCommand { Direction::DOWN, 7 }, "(DOWN, 7)"),
        std::make_pair(MoveCommand { Direction::FORWARD, 5 }, "(FORWARD, 5)")));

class MoveCommandParameterizedInvalidTestFixture
    : public ::testing::TestWithParam<std::pair<MoveCommand, std::string>> {
};

TEST_P(MoveCommandParameterizedInvalidTestFixture, IncorrectToString)
{
    auto const command = GetParam().first;
    auto const expected_string = GetParam().second;
    ASSERT_NE(toString(command), expected_string);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandParameterizedInvalidTest,
    MoveCommandParameterizedInvalidTestFixture,
    ::testing::Values(std::make_pair(MoveCommand { Direction::FORWARD, 5 }, "(FORWARD, 10)"),
        std::make_pair(MoveCommand { Direction::FORWARD, 7 }, "(FORWARD, 5)")));
