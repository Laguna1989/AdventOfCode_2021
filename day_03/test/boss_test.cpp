#include "calculate_rates.hpp"
#include "parser.hpp"
#include "test_input.hpp"
#include <gtest/gtest.h>

TEST(BossTest, InputKerim)
{
    auto const input = parse(input_kerim);
    auto const converted_input = convert<12>(input);
    auto const [gamma_rate, epsilon_rate] = calculate_rates<12>(converted_input);
    ASSERT_EQ(gamma_rate * epsilon_rate, 1131506);
}
