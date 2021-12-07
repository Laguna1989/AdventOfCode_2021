#include "move_command.hpp"
#include <cassert>
#include <gtest/gtest.h>
#include <regex>
#include <string>

using namespace ::testing;

MoveCommand parse_input_line(std::string const& input)
{
    std::regex pattern { "(\\w+) (\\d+)" };
    std::smatch match;
    std::regex_search(input, match, pattern);
    auto const& direction_string = match[1];

    auto const direction = direction_from_string(direction_string);
    auto const distance = std::stoi(match[2]);
    return MoveCommand { direction, distance };
}

std::vector<MoveCommand> parse_input(std::string const& input)
{
    std::vector<MoveCommand> commands;

    std::stringstream str { input };
    std::string line;
    while (std::getline(str, line)) {
        commands.push_back(parse_input_line(line));
    }

    return commands;
}

class ParserParametrizedTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, MoveCommand>> {
};

TEST_P(ParserParametrizedTestFixture, ForwardInput)
{
    auto const input = GetParam().first;
    auto const expected_command = GetParam().second;
    auto const command = parse_input_line(input);

    ASSERT_EQ(expected_command, command);
}

INSTANTIATE_TEST_SUITE_P(ParserParametrizedTest, ParserParametrizedTestFixture,
    ::testing::Values(std::make_pair("forward 9", MoveCommand { Direction::FORWARD, 9 }),
        std::make_pair("forward 5", MoveCommand { Direction::FORWARD, 5 }),
        std::make_pair("up 5", MoveCommand { Direction::UP, 5 }),
        std::make_pair("down 22", MoveCommand { Direction::DOWN, 22 })));

TEST(ParserTest, MultiLineInput)
{
    auto const input = R"(forward 5
down 5)";
    std::vector<MoveCommand> const expected_commands { MoveCommand { Direction::FORWARD, 5 },
        MoveCommand { Direction::DOWN, 5 } };

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
    std::vector<MoveCommand> const expected_commands { MoveCommand { Direction::FORWARD, 5 },
        MoveCommand { Direction::DOWN, 5 }, MoveCommand { Direction::FORWARD, 8 },
        MoveCommand { Direction::UP, 3 }, MoveCommand { Direction::DOWN, 8 },
        MoveCommand { Direction::FORWARD, 2 } };

    auto const parsed_input = parse_input(input);

    ASSERT_EQ(parsed_input, expected_commands);
}
