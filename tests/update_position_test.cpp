#include "transform.hpp"
#include "transform_command.hpp"
#include "update_position.hpp"
#include <gtest/gtest.h>

class UpdatePositionParameterizedTestFixture
    : public ::testing::TestWithParam<std::pair<TransformCommand, Transform>> {
};

TEST_P(UpdatePositionParameterizedTestFixture, CorrectUpdateFromDefaultPosition)
{
    Transform const default_position { 0, 0 };

    auto const move_command = GetParam().first;
    auto const expected_position = GetParam().second;

    auto const updated_position = update_transform(default_position, move_command);
    ASSERT_EQ(updated_position, expected_position);
}

TEST_P(UpdatePositionParameterizedTestFixture, CorrectUpdateFromStartingPosition)
{
    auto const magic_offset = 20;
    Transform const default_position { magic_offset, magic_offset };

    auto const move_command = GetParam().first;
    auto const expected_position = Transform { GetParam().second.horizontal + magic_offset,
        GetParam().second.depth + magic_offset };

    auto const updated_position = update_transform(default_position, move_command);
    ASSERT_EQ(updated_position, expected_position);
}

INSTANTIATE_TEST_SUITE_P(UpdatePositionParameterizedTest, UpdatePositionParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(TransformCommand { Direction::FORWARD, 1 }, Transform { 1, 0 }),
        std::make_pair(TransformCommand { Direction::FORWARD, 5 }, Transform { 5, 0 }),
        std::make_pair(TransformCommand { Direction::DOWN, 5 }, Transform { 0, 5 }),
        std::make_pair(TransformCommand { Direction::UP, 5 }, Transform { 0, -5 })));

TEST(ConsecutiveMoveCommands, CorrectResult)
{
    std::vector<TransformCommand> const move_commands { TransformCommand { Direction::FORWARD, 5 },
        TransformCommand { Direction::DOWN, 5 }, TransformCommand { Direction::FORWARD, 8 },
        TransformCommand { Direction::UP, 3 }, TransformCommand { Direction::DOWN, 8 },
        TransformCommand { Direction::FORWARD, 2 } };

    Transform const expected_position { 15, 10 };

    auto const updated_position = update_transform_consecutive(move_commands);
    ASSERT_EQ(updated_position, expected_position);
}
