#include "calculate.hpp"
#include <bitset>
#include <gtest/gtest.h>

TEST(CalculateRateTest, CorrectGammaRate)
{
    // TODO use type alias
    std::vector<std::bitset<5>> const input { 0b10010, 0b10010 };

    auto [gamma_rate, epsilon_rate] = calculate_rates(input);

    ASSERT_EQ(gamma_rate, 0b10010);
}
