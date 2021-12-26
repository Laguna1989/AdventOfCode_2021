#include "calculate_rates.hpp"
#include "parser.hpp"
#include "test_input.hpp"
#include <gtest/gtest.h>

TEST(BossTest, InputKerimPart1)
{
    auto const input = parse(input_kerim);
    auto const converted_input = convert<12>(input);
    auto const gamma_rate = calculate_gamma_rate<12>(converted_input);
    auto const epsilon_rate = calculate_epsilon_rate<12>(converted_input);
    ASSERT_EQ(gamma_rate * epsilon_rate, 1131506);
}

TEST(BossTest, InputSimonPart1)
{
    auto const input = parse(input_simon);
    auto const converted_input = convert<12>(input);
    auto const gamma_rate = calculate_gamma_rate<12>(converted_input);
    auto const epsilon_rate = calculate_epsilon_rate<12>(converted_input);
    ASSERT_EQ(gamma_rate * epsilon_rate, 741950);
}

TEST(BossTest, InputKerimPart2)
{
    auto const input = parse(input_kerim);
    auto const converted_input = convert<12>(input);
    auto const oxygen_generator = calculate_oxygen_generator_rate<12>(converted_input);
    auto const co2_scrubber_rate = calculate_co2_scrubber_rate<12>(converted_input);
    ASSERT_EQ(oxygen_generator * co2_scrubber_rate, 7863147);
}

TEST(BossTest, InputSimonPart2)
{
    auto const input = parse(input_simon);
    auto const converted_input = convert<12>(input);
    auto const oxygen_generator = calculate_oxygen_generator_rate<12>(converted_input);
    auto const co2_scrubber_rate = calculate_co2_scrubber_rate<12>(converted_input);
    ASSERT_EQ(oxygen_generator * co2_scrubber_rate, 903810);
}
