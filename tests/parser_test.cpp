#include "move_command.hpp"
#include <gtest/gtest.h>
#include <string>

using namespace ::testing;

MoveCommand parse_input(std::string const& /*input*/)
{
    // TODO replace fake
    return MoveCommand { Direction::FORWARD, 5 };
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
