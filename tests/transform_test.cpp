#include "transform.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(TransformTest, InitialValue)
{
    Transform p;
    ASSERT_EQ(p.horizontal, 0);
    ASSERT_EQ(p.depth, 0);
    ASSERT_EQ(p.aim, 0);
}

TEST(TransformTest, ValuesAfterSet)
{
    int expected_horizontal = 5;
    int expected_depth = 9;
    int expected_aim = -4;

    Transform p { expected_horizontal, expected_depth, expected_aim };

    ASSERT_EQ(p.horizontal, expected_horizontal);
    ASSERT_EQ(p.depth, expected_depth);
    ASSERT_EQ(p.aim, expected_aim);
}

TEST(TransformTest, ComparisonEquals)
{
    int expected_horizontal = 2;
    int expected_depth = 3;
    int expected_aim = -7;

    Transform p1 { expected_horizontal, expected_depth, expected_aim };
    Transform p2 { expected_horizontal, expected_depth, expected_aim };

    ASSERT_EQ(p1, p2);
}

TEST(TransformTest, ComparisonNotEqualsHorizontal)
{
    int expected_horizontal = 2;
    int expected_depth = 3;
    int expected_aim = 6;

    Transform p1 { expected_horizontal, expected_depth, expected_aim };
    Transform p2 { expected_horizontal + 1, expected_depth, expected_aim };

    ASSERT_NE(p1, p2);
}

TEST(TransformTest, ComparisonNotEqualsDepth)
{
    int expected_horizontal = 2;
    int expected_depth = 3;
    int expected_aim = 6;

    Transform p1 { expected_horizontal, expected_depth, expected_aim };
    Transform p2 { expected_horizontal, expected_depth + 2, expected_aim };

    ASSERT_NE(p1, p2);
}

TEST(TransformTest, ComparisonNotEqualsAim)
{
    int expected_horizontal = 2;
    int expected_depth = 3;
    int expected_aim = 6;

    Transform p1 { expected_horizontal, expected_depth, expected_aim };
    Transform p2 { expected_horizontal, expected_depth, expected_aim + 3 };

    ASSERT_NE(p1, p2);
}

TEST(TransformTest, StringOperator)
{
    int expected_horizontal = 2;
    int expected_depth = 3;
    int expected_aim = 42;

    Transform p { expected_horizontal, expected_depth, expected_aim };

    std::stringstream str;
    str << "(" << expected_horizontal << ", " << expected_depth << ", " << expected_aim << ")";

    ASSERT_EQ(toString(p), str.str());
}
