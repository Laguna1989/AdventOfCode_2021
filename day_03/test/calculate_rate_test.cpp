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
    auto const gamma_rate = calculate_gamma_rate<5>(GetParam().first);
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
    auto const epsilon_rate = calculate_epsilon_rate<5>(GetParam().first);
    ASSERT_EQ(epsilon_rate, GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(CalculateEpsilonRateParameterizedTest,
    CalculateEpsilonRateParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b10010, 0b10010 }, 0b01101),
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b00100, 0b11110, 0b10110, 0b10111,
                           0b10101, 0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 },
            0b01001)));

TEST(CalculateGammaRateParameterizedTestFixture, CorrectGammaRate7)
{
    auto const gamma_rate
        = calculate_gamma_rate<7>(std::vector<Diagnostic_input_type<7>> { 0b0010010, 0b0010010 });
    ASSERT_EQ(gamma_rate, 0b0010010);
}

using CalculateOxygenGeneratorRateParameterizedTestFixture = CalculateRateParameterizedTestFixture;

TEST_P(CalculateOxygenGeneratorRateParameterizedTestFixture, CorrectOxygenGeneratorRate)
{
    auto const oxygen_generator_rate = calculate_oxygen_generator_rate<5>(GetParam().first);
    ASSERT_EQ(oxygen_generator_rate, GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(CalculateOxygenGeneratorRateParameterizedTest,
    CalculateOxygenGeneratorRateParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b10010, 0b10010 }, 0b10010),
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b00100, 0b11110, 0b10110, 0b10111,
                           0b10101, 0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 },
            0b10111)));

using CalculateCo2ScrubberRateParameterizedTestFixture = CalculateRateParameterizedTestFixture;

TEST_P(CalculateCo2ScrubberRateParameterizedTestFixture, CorrectCo2ScrubberRate)
{
    auto const co2_scrubber_rate = calculate_co2_scrubber_rate<5>(GetParam().first);
    ASSERT_EQ(co2_scrubber_rate, GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(CalculateCo2ScrubberRateParameterizedTest,
    CalculateCo2ScrubberRateParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(std::vector<Diagnostic_input_type<5>> { 0b00100, 0b11110, 0b10110, 0b10111,
                           0b10101, 0b01111, 0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010 },
            0b01010)));
