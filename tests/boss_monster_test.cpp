#include "parser.hpp"
#include "test_input.hpp"
#include "transform.hpp"
#include "update_position.hpp"
#include <gtest/gtest.h>

TEST(BossMonsterTest, JustDoIt)
{
    auto const commands = parse_input(massive_input_simon);
    auto const resulting_position = update_transform_consecutive(commands);

    ASSERT_EQ(resulting_position.horizontal * resulting_position.depth, 2187380);
}
