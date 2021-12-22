#include "transform_command.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class MoveCommandEqualsParametrizedTestFixture : public ::testing::TestWithParam<TransformCommand> {
};

TEST_P(MoveCommandEqualsParametrizedTestFixture, CorrectComparison)
{
    TransformCommand const a { GetParam() };
    TransformCommand const b { GetParam() };

    ASSERT_EQ(a, b);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandEqualsParametrizedTest,
    MoveCommandEqualsParametrizedTestFixture,
    ::testing::Values(TransformCommand { Direction::FORWARD, 5 },
        TransformCommand { Direction::UP, 5 }, TransformCommand { Direction::FORWARD, 10 },
        TransformCommand { Direction::DOWN, -5 }));

TEST(MoveCommandTest, ComparisonNotEquals)
{
    TransformCommand const a { Direction::FORWARD, 5 };
    TransformCommand const b { Direction::FORWARD, 8 };

    ASSERT_NE(a, b);
}

class MoveCommandToStringParameterizedBaseTestFixture
    : public ::testing::TestWithParam<std::pair<TransformCommand, std::string>> {
};

using MoveCommandParameterizedValidTestFixture = MoveCommandToStringParameterizedBaseTestFixture;

TEST_P(MoveCommandParameterizedValidTestFixture, CorrectToString)
{
    auto const command = GetParam().first;
    auto const expected_string = GetParam().second;
    ASSERT_EQ(to_string(command), expected_string);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandParameterizedTest, MoveCommandParameterizedValidTestFixture,
    ::testing::Values(std::make_pair(TransformCommand { Direction::FORWARD, 10 }, "(forward, 10)"),
        std::make_pair(TransformCommand { Direction::UP, 3 }, "(up, 3)"),
        std::make_pair(TransformCommand { Direction::DOWN, 7 }, "(down, 7)"),
        std::make_pair(TransformCommand { Direction::FORWARD, 5 }, "(forward, 5)")));

using MoveCommandParameterizedInvalidTestFixture = MoveCommandToStringParameterizedBaseTestFixture;

TEST_P(MoveCommandParameterizedInvalidTestFixture, IncorrectToString)
{
    auto const command = GetParam().first;
    auto const expected_string = GetParam().second;
    ASSERT_NE(to_string(command), expected_string);
}

INSTANTIATE_TEST_SUITE_P(MoveCommandParameterizedInvalidTest,
    MoveCommandParameterizedInvalidTestFixture,
    ::testing::Values(std::make_pair(TransformCommand { Direction::FORWARD, 5 }, "(forward, 10)"),
        std::make_pair(TransformCommand { Direction::FORWARD, 7 }, "(forward, 5)"),
        std::make_pair(TransformCommand { Direction::DOWN, 7 }, "(forward, 7)"),
        std::make_pair(TransformCommand { Direction::DOWN, 22 }, "(up, 22)")));
