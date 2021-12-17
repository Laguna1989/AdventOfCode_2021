#include "parser.hpp"
#include "transform_command.hpp"
#include <cassert>
#include <gtest/gtest.h>
#include <regex>
#include <string>

using namespace ::testing;

class ParserParametrizedTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, TransformCommand>> {
};

TEST_P(ParserParametrizedTestFixture, ForwardInput)
{
    auto const input = GetParam().first;
    auto const expected_command = GetParam().second;
    auto const command = parse_input_line(input);

    ASSERT_EQ(expected_command, command);
}

INSTANTIATE_TEST_SUITE_P(ParserParametrizedTest, ParserParametrizedTestFixture,
    ::testing::Values(std::make_pair("forward 9", TransformCommand { Direction::FORWARD, 9 }),
        std::make_pair("forward 5", TransformCommand { Direction::FORWARD, 5 }),
        std::make_pair("up 5", TransformCommand { Direction::UP, 5 }),
        std::make_pair("down 22", TransformCommand { Direction::DOWN, 22 })));

TEST(ParserTest, MultiLineInput)
{
    auto const input = R"(forward 5
down 5)";
    std::vector<TransformCommand> const expected_commands {
        TransformCommand { Direction::FORWARD, 5 }, TransformCommand { Direction::DOWN, 5 }
    };

    auto const parsed_input = parse_input(input);
    ASSERT_EQ(parsed_input, expected_commands);
}

TEST(ParserTest, BossMonster)
{
    auto const input = R"(forward 5
down 5
forward 8
up 3
down 8
forward 2)";
    std::vector<TransformCommand> const expected_commands {
        TransformCommand { Direction::FORWARD, 5 }, TransformCommand { Direction::DOWN, 5 },
        TransformCommand { Direction::FORWARD, 8 }, TransformCommand { Direction::UP, 3 },
        TransformCommand { Direction::DOWN, 8 }, TransformCommand { Direction::FORWARD, 2 }
    };

    auto const parsed_input = parse_input(input);

    ASSERT_EQ(parsed_input, expected_commands);
}
