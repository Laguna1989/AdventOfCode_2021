#include "position.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(PositionTest, InitialValue)
{
    Position p;
    ASSERT_EQ(p.x, 0);
    ASSERT_EQ(p.y, 0);
}

TEST(PositionTest, ValuesAfterSet)
{
    int expected_x = 5;
    int expected_y = 9;

    Position p { expected_x, expected_y };

    ASSERT_EQ(p.x, expected_x);
    ASSERT_EQ(p.y, expected_y);
}

TEST(PositionTest, ComparisonEquals)
{
    int expected_x = 2;
    int expected_y = 3;

    Position p1 { expected_x, expected_y };
    Position p2 { expected_x, expected_y };

    ASSERT_EQ(p1, p2);
}

TEST(PositionTest, ComparisonNotEquals)
{
    int expected_x = 2;
    int expected_y = 3;

    Position p1 { expected_x, expected_y };
    Position p2 { expected_x + 1, expected_y };

    ASSERT_NE(p1, p2);
}

TEST(PositionTest, StringOperator)
{
    int expected_x = 2;
    int expected_y = 3;

    Position p { expected_x, expected_y };

    std::stringstream str;
    str << "(" << expected_x << ", " << expected_y << ")";

    ASSERT_EQ(toString(p), str.str());
}
