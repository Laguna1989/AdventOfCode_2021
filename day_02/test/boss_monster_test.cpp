#include "parser.hpp"
#include "test_input.hpp"
#include "transform.hpp"
#include "update_transform.hpp"
#include <gtest/gtest.h>

TEST(BossMonsterTest, JustDoItSimon)
{
    auto const commands = parse_input(massive_input_simon);
    auto const resulting_position = update_transform_consecutive(commands);

    ASSERT_EQ(resulting_position.horizontal * resulting_position.depth, 2086357770);
}

TEST(BossMonsterTest, JustDoItKerim)
{
    auto const commands = parse_input(massive_input_kerim);
    auto const resulting_position = update_transform_consecutive(commands);

    ASSERT_EQ(resulting_position.horizontal * resulting_position.depth, 1840311528);
}
