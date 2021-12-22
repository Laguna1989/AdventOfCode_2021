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
    std::vector<std::string> const result = parse(input);
    std::vector<std::string> const expectedInput { "00100" };

    ASSERT_EQ(expectedInput, result);
}

TEST(ParserTest, ConvertInputToBitset)
{
    std::vector<std::string> const input { "00100", "11110", "10110", "10111", "10101", "01111",
        "00111", "11100", "10000", "11001", "00010", "01010" };
    std::vector<std::bitset<5>> expectedOutput { 0b00100, 0b11110, 0b10110, 0b10111, 0b10101,
        0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 };

    auto const output = convert(input);

    ASSERT_EQ(expectedOutput, output);
}
