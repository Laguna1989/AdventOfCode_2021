#include "calculate_rates.hpp"
#include <bitset>
#include <gtest/gtest.h>

class CalculateRateParameterizedTestFixture
    : public ::testing::TestWithParam<
          std::pair<std::vector<Diagnostic_input_type<5>>, unsigned long>> {
};

using CalculateGammaRateParameterizedTestFixture = CalculateRateParameterizedTestFixture;

TEST_P(CalculateGammaRateParameterizedTestFixture, CorrectGammaRate)
{
    auto [gamma_rate, epsilon_rate] = calculate_rates<5>(GetParam().first);
    ASSERT_EQ(gamma_rate, GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(CalculateGammaRateParameterizedTest,
    CalculateGammaRateParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b10010, 0b10010 }, 0b10010),
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b00100, 0b11110, 0b10110, 0b10111,
                           0b10101, 0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 },
            0b10110)));

using CalculateEpsilonRateParameterizedTestFixture = CalculateRateParameterizedTestFixture;

TEST_P(CalculateEpsilonRateParameterizedTestFixture, CorrectEpsilonRate)
{
    auto [gamma_rate, epsilon_rate] = calculate_rates<5>(GetParam().first);
    ASSERT_EQ(epsilon_rate, GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(CalculateEpsilonRateParameterizedTest,
    CalculateEpsilonRateParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b10010, 0b10010 }, 0b01101),
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b00100, 0b11110, 0b10110, 0b10111,
                           0b10101, 0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 },
            0b01001)));

TEST(CalculateGammaRateParameterizedTestFixture, CorrectGammaRate6)
{
    auto [gamma_rate, epsilon_rate]
        = calculate_rates<7>(std::vector<Diagnostic_input_type<7>> { 0b0010010, 0b0010010 });
    ASSERT_EQ(gamma_rate, 0b0010010);
}
