#include "calculate_rates.hpp"
#include <bitset>
#include <gtest/gtest.h>

class CalculateRateParameterizedTestFixture
    : public ::testing::TestWithParam<
          std::pair<std::vector<Diagnostic_input_type>, unsigned long>> {
};

TEST_P(CalculateRateParameterizedTestFixture, CorrectGammaRate)
{
    auto [gamma_rate, epsilon_rate] = calculate_rates(GetParam().first);

    ASSERT_EQ(gamma_rate, GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(CalculateRateParameterizedTest, CalculateRateParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(std::vector<Diagnostic_input_type> { 0b10010, 0b10010 }, 0b10010),
        std::make_pair(std::vector<Diagnostic_input_type> { 0b00100, 0b11110, 0b10110, 0b10111,
                           0b10101, 0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 },
            0b10110)));

TEST(CalculateRateTest, CorrectEpsilonRate)
{
    std::vector<Diagnostic_input_type> const input { 0b10010, 0b10010 };

    auto [gamma_rate, epsilon_rate] = calculate_rates(input);

    ASSERT_EQ(epsilon_rate, 0b01101);
}

TEST(CalculateRateTest, CorrectEpsilonRate2)
{
    std::vector<Diagnostic_input_type> const input { 0b00100, 0b11110, 0b10110, 0b10111, 0b10101,
        0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 };

    auto [gamma_rate, epsilon_rate] = calculate_rates(input);

    ASSERT_EQ(epsilon_rate, 0b01001);
}
