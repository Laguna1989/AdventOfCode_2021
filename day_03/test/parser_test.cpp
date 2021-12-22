#include "parser.hpp"
#include <gtest/gtest.h>

TEST(ParserTest, SmallExampleParsedCorrectly)
{
    constexpr auto input = R"(00100
11110
10110
10111
10101
01111
00111
11100
10000
11001
00010
01010)";

    std::vector<std::string> result = parse(input);

    std::vector<std::string> expectedInput { "00100", "11110", "10110", "10111", "10101", "01111",
        "00111", "11100", "10000", "11001", "00010", "01010" };

    ASSERT_EQ(expectedInput, result);
}

TEST(ParserTest, OneLine)
{
    constexpr auto input = "00100";

    std::vector<std::string> result = parse(input);

    std::vector<std::string> expectedInput { "00100" };

    ASSERT_EQ(expectedInput, result);
}
