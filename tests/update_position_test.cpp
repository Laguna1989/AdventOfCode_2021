#include "move_command.hpp"
#include "position.hpp"
#include <gtest/gtest.h>

Position update_position(Position const& position, MoveCommand command)
{
    if (command.direction == Direction::FORWARD) {
        return Position { position.x + command.distance, position.y };
    } else if (command.direction == Direction::DOWN) {
        return Position { position.x, position.y + command.distance };
    }
    return Position { position.x, position.y - command.distance };
}

class UpdatePositionParameterizedTestFixture
    : public ::testing::TestWithParam<std::pair<MoveCommand, Position>> {
};

TEST_P(UpdatePositionParameterizedTestFixture, CorrectUpdateFromDefaultPosition)
{
    Position const default_position { 0, 0 };

    auto const move_command = GetParam().first;
    auto const expected_position = GetParam().second;

    auto const updated_position = update_position(default_position, move_command);
    ASSERT_EQ(updated_position, expected_position);
}

TEST_P(UpdatePositionParameterizedTestFixture, CorrectUpdateFromStartingPosition)
{
    auto const magic_offset = 20;
    Position const default_position { magic_offset, magic_offset };

    auto const move_command = GetParam().first;
    auto const expected_position
        = Position { GetParam().second.x + magic_offset, GetParam().second.y + magic_offset };

    auto const updated_position = update_position(default_position, move_command);
    ASSERT_EQ(updated_position, expected_position);
}

INSTANTIATE_TEST_SUITE_P(UpdatePositionParameterizedTest, UpdatePositionParameterizedTestFixture,
    ::testing::Values(std::make_pair(MoveCommand { Direction::FORWARD, 1 }, Position { 1, 0 }),
        std::make_pair(MoveCommand { Direction::FORWARD, 5 }, Position { 5, 0 }),
        std::make_pair(MoveCommand { Direction::DOWN, 5 }, Position { 0, 5 }),
        std::make_pair(MoveCommand { Direction::UP, 5 }, Position { 0, -5 })));

Position update_position_consecutive(
    Position initial_position, std::vector<MoveCommand> const& move_commands)
{
    return Position {};
}

TEST(ConsecutiveMoveCommands, CorrectResult)
{
    Position const default_position { 0, 0 };

    std::vector<MoveCommand> const move_commands { MoveCommand { Direction::FORWARD, 5 },
        MoveCommand { Direction::DOWN, 5 }, MoveCommand { Direction::FORWARD, 8 },
        MoveCommand { Direction::UP, 3 }, MoveCommand { Direction::DOWN, 8 },
        MoveCommand { Direction::FORWARD, 2 } };

    Position const expected_position { 15, 10 };

    auto const updated_position = update_position_consecutive(default_position, move_commands);
    ASSERT_EQ(updated_position, expected_position);
}
