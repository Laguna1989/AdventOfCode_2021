#include <gtest/gtest.h>

using namespace ::testing;

enum class Direction { FORWARD };

struct MoveCommand {
    Direction direction;
    int distance;
};

MoveCommand parse_input(std::string const& input)
{
    // TODO replace fake
    return MoveCommand { Direction::FORWARD, 5 };
}

TEST(ParserTest, IsThisWorking)
{
    std::string const input { "forward 5" };

    MoveCommand expected_command { Direction::FORWARD, 5 };

    auto command = parse_input(input);

    // TODO use operator==
    ASSERT_EQ(expected_command.distance, command.distance);
    ASSERT_EQ(expected_command.direction, command.direction);
}
