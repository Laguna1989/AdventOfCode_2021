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
    // auto const& direction_string = match[1];
    auto const distance = std::stoi(match[2]);
    return MoveCommand { Direction::FORWARD, distance };
}

TEST(ParserTest, ForwardInput)
{
    std::string const input { "forward 5" };

    MoveCommand const expected_command { Direction::FORWARD, 5 };

    auto const command = parse_input(input);

    ASSERT_EQ(expected_command, command);
}

TEST(ParserTest, ForwardInput2)
{
    std::string const input { "forward 9" };

    MoveCommand const expected_command { Direction::FORWARD, 9 };

    auto const command = parse_input(input);

    ASSERT_EQ(expected_command, command);
}
