#include "transform.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(TransformTest, InitialValue)
{
    Transform p;
    ASSERT_EQ(p.horizontal, 0);
    ASSERT_EQ(p.depth, 0);
}

TEST(TransformTest, ValuesAfterSet)
{
    int expected_x = 5;
    int expected_y = 9;

    Transform p { expected_x, expected_y };

    ASSERT_EQ(p.horizontal, expected_x);
    ASSERT_EQ(p.depth, expected_y);
}

TEST(TransformTest, ComparisonEquals)
{
    int expected_x = 2;
    int expected_y = 3;

    Transform p1 { expected_x, expected_y };
    Transform p2 { expected_x, expected_y };

    ASSERT_EQ(p1, p2);
}

TEST(TransformTest, ComparisonNotEquals)
{
    int expected_x = 2;
    int expected_y = 3;

    Transform p1 { expected_x, expected_y };
    Transform p2 { expected_x + 1, expected_y };

    ASSERT_NE(p1, p2);
}

TEST(TransformTest, StringOperator)
{
    int expected_x = 2;
    int expected_y = 3;

    Transform p { expected_x, expected_y };

    std::stringstream str;
    str << "(" << expected_x << ", " << expected_y << ")";

    ASSERT_EQ(toString(p), str.str());
}
