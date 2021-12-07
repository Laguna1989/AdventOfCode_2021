#include "move_command.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class MoveCommandEqualsParametrizedTestFixture : public ::testing::TestWithParam<MoveCommand> {
};

TEST_P(MoveCommandEqualsParametrizedTestFixture, CorrectComparison)
{
    MoveCommand const a { GetParam() };
    MoveCommand const b { GetParam() };

    ASSERT_EQ(a, b);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandEqualsParametrizedTest,
    MoveCommandEqualsParametrizedTestFixture,
    ::testing::Values(MoveCommand { Direction::FORWARD, 5 }, MoveCommand { Direction::UP, 5 },
        MoveCommand { Direction::FORWARD, 10 }, MoveCommand { Direction::DOWN, -5 }));

TEST(MoveCommandTest, ComparisonNotEquals)
{
    MoveCommand const a { Direction::FORWARD, 5 };
    MoveCommand const b { Direction::FORWARD, 8 };

    ASSERT_NE(a, b);
}

class MoveCommandToStringParameterizedBaseTestFixture
    : public ::testing::TestWithParam<std::pair<MoveCommand, std::string>> {
};

using MoveCommandParameterizedValidTestFixture = MoveCommandToStringParameterizedBaseTestFixture;

TEST_P(MoveCommandParameterizedValidTestFixture, CorrectToString)
{
    auto const command = GetParam().first;
    auto const expected_string = GetParam().second;
    ASSERT_EQ(to_string(command), expected_string);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandParameterizedTest, MoveCommandParameterizedValidTestFixture,
    ::testing::Values(std::make_pair(MoveCommand { Direction::FORWARD, 10 }, "(FORWARD, 10)"),
        std::make_pair(MoveCommand { Direction::UP, 3 }, "(UP, 3)"),
        std::make_pair(MoveCommand { Direction::DOWN, 7 }, "(DOWN, 7)"),
        std::make_pair(MoveCommand { Direction::FORWARD, 5 }, "(FORWARD, 5)")));

using MoveCommandParameterizedInvalidTestFixture = MoveCommandToStringParameterizedBaseTestFixture;

TEST_P(MoveCommandParameterizedInvalidTestFixture, IncorrectToString)
{
    auto const command = GetParam().first;
    auto const expected_string = GetParam().second;
    ASSERT_NE(to_string(command), expected_string);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandParameterizedInvalidTest,
    MoveCommandParameterizedInvalidTestFixture,
    ::testing::Values(std::make_pair(MoveCommand { Direction::FORWARD, 5 }, "(FORWARD, 10)"),
        std::make_pair(MoveCommand { Direction::FORWARD, 7 }, "(FORWARD, 5)"),
        std::make_pair(MoveCommand { Direction::DOWN, 7 }, "(FORWARD, 7)"),
        std::make_pair(MoveCommand { Direction::DOWN, 22 }, "(UP, 22)")));
