#include "transform.hpp"
#include "transform_command.hpp"
#include "update_position.hpp"
#include <gtest/gtest.h>
#include <ostream>

namespace std {

ostream& operator<<(ostream& s, Transform const& value) { return s << to_string(value); }

} // namespace std

class UpdatePositionParameterizedTestFixture
    : public ::testing::TestWithParam<std::pair<TransformCommand, Transform>> {
};

TEST_P(UpdatePositionParameterizedTestFixture, CorrectUpdateFromDefaultPosition)
{
    Transform const default_transform { 0, 0 };

    auto const move_command = GetParam().first;
    auto const expected_transform = GetParam().second;

    auto const updated_transform = update_transform(default_transform, move_command);
    ASSERT_EQ(updated_transform, expected_transform);
}

TEST_P(UpdatePositionParameterizedTestFixture, CorrectUpdateFromStartingPosition)
{
    auto const magic_offset = 20;
    Transform const default_transform { magic_offset, magic_offset, 0 };

    auto const move_command = GetParam().first;
    Transform initial_transform = GetParam().second;
    auto const expected_transform = Transform { initial_transform.horizontal + magic_offset,
        initial_transform.depth + magic_offset, initial_transform.aim };

    auto const updated_transform = update_transform(default_transform, move_command);
    ASSERT_EQ(updated_transform, expected_transform);
}

INSTANTIATE_TEST_SUITE_P(UpdatePositionParameterizedTest, UpdatePositionParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(TransformCommand { Direction::FORWARD, 1 }, Transform { 1, 0 }),
        std::make_pair(TransformCommand { Direction::FORWARD, 5 }, Transform { 5, 0 }),
        std::make_pair(TransformCommand { Direction::DOWN, 5 }, Transform { 0, 0, 5 }),
        std::make_pair(TransformCommand { Direction::UP, 5 }, Transform { 0, 0, -5 })));

TEST(ConsecutiveMoveCommands, CorrectResult)
{
    std::vector<TransformCommand> const move_commands { TransformCommand { Direction::FORWARD, 5 },
        TransformCommand { Direction::DOWN, 5 }, TransformCommand { Direction::FORWARD, 8 },
        TransformCommand { Direction::UP, 3 }, TransformCommand { Direction::DOWN, 8 },
        TransformCommand { Direction::FORWARD, 2 } };

    Transform const expected_transform { 15, 60, 10 };

    auto const updated_transform = update_transform_consecutive(move_commands);
    ASSERT_EQ(updated_transform, expected_transform);
}
