#include "move_command.hpp"
#include "position.hpp"
#include <gtest/gtest.h>

Position update_position(Position const& position, MoveCommand command)
{
    return Position { position.x + command.distance, 0 };
}

class UpdatePositionParameterizedTestFixture
    : public ::testing::TestWithParam<std::pair<MoveCommand, Position>> {
};

TEST_P(UpdatePositionParameterizedTestFixture, Forward1)
{
    Position const default_position { 0, 0 };

    auto const move_command = GetParam().first;
    auto const expected_position = GetParam().second;

    auto const updated_position = update_position(default_position, move_command);
    ASSERT_EQ(updated_position, expected_position);
}

INSTANTIATE_TEST_SUITE_P(UpdatePositionParameterizedTest, UpdatePositionParameterizedTestFixture,
    ::testing::Values(std::make_pair(MoveCommand { Direction::FORWARD, 1 }, Position { 1, 0 }),
        std::make_pair(MoveCommand { Direction::FORWARD, 5 }, Position { 5, 0 }),
        std::make_pair(MoveCommand { Direction::DOWN, 5 }, Position { 0, 5 })));
