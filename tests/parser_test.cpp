#include "move_command.hpp"
#include <cassert>
#include <gtest/gtest.h>
#include <regex>
#include <string>

using namespace ::testing;

MoveCommand parse_input(std::string const& input)
{
    std::regex pattern { "(\\w+) (\\d+)" };
    std::smatch match;
    std::regex_search(input, match, pattern);
    auto const& direction_string = match[1];

    auto const direction = direction_from_string(direction_string);
    auto const distance = std::stoi(match[2]);
    return MoveCommand { direction, distance };
}

class ParserParametrizedTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, MoveCommand>> {
};

TEST_P(ParserParametrizedTestFixture, ForwardInput)
{
    auto const input = GetParam().first;
    auto const expected_command = GetParam().second;
    auto const command = parse_input(input);

    ASSERT_EQ(expected_command, command);
}

INSTANTIATE_TEST_SUITE_P(ParserParametrizedTest, ParserParametrizedTestFixture,
    ::testing::Values(std::make_pair("forward 9", MoveCommand { Direction::FORWARD, 9 }),
        std::make_pair("forward 5", MoveCommand { Direction::FORWARD, 5 }),
        std::make_pair("up 5", MoveCommand { Direction::UP, 5 }),
        std::make_pair("down 22", MoveCommand { Direction::DOWN, 22 })));
