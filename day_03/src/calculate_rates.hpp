#ifndef CODE_KATA_CALCULATE_RATES_HPP
#define CODE_KATA_CALCULATE_RATES_HPP

#include "types.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <tuple>
#include <vector>

template <int N>
Diagnostic_input_type<N> calculate_gamma_rate_raw(
    std::vector<Diagnostic_input_type<N>> const& input)
{
    Diagnostic_input_type<N> gamma_rate;
    for (auto position = 0u; position != gamma_rate.size(); ++position) {
        std::size_t count { 0u };
        for (auto const& value : input) {
            if (value[position]) {
                count++;
            }
        }
        bool const has_equal_number_of_true_and_false
            = input.size() % 2 == 0 && count == input.size() / 2;
        if (has_equal_number_of_true_and_false) {
            gamma_rate[position] = true;
        } else {
            gamma_rate[position] = (count > input.size() / 2);
        }
    }
    return gamma_rate;
}

template <int N>
unsigned long calculate_gamma_rate(std::vector<Diagnostic_input_type<N>> const& input)
{
    return calculate_gamma_rate_raw<N>(input).to_ulong();
}

template <int N>
unsigned long calculate_epsilon_rate(std::vector<Diagnostic_input_type<N>> const& input)
{
    return calculate_gamma_rate_raw<N>(input).flip().to_ulong();
}

template <int N>
unsigned long calculate_oxygen_generator_rate(std::vector<Diagnostic_input_type<N>> const& input)
{
    std::vector<Diagnostic_input_type<N>> remaining { input };
    remaining.erase(std::unique(remaining.begin(), remaining.end()), remaining.end());

    for (auto bit_position = N - 1; bit_position >= 0; --bit_position) {
        auto const gamma_rate_raw = calculate_gamma_rate_raw<N>(remaining);
        auto const current_most_common_bit = gamma_rate_raw[bit_position];

        remaining.erase(std::remove_if(remaining.begin(), remaining.end(),
                            [&current_most_common_bit, &bit_position](
                                auto& v) { return v[bit_position] != current_most_common_bit; }),
            remaining.end());

        if (remaining.size() == 1) {
            return remaining.at(0).to_ulong();
        }
    }
    // Never reach this line :D
    assert(false);
}

template <int N>
unsigned long calculate_co2_scrubber_rate(std::vector<Diagnostic_input_type<N>> const& input)
{
    std::vector<Diagnostic_input_type<N>> remaining { input };
    remaining.erase(std::unique(remaining.begin(), remaining.end()), remaining.end());

    for (auto bit_position = N - 1; bit_position >= 0; --bit_position) {
        auto const gamma_rate_raw = calculate_gamma_rate_raw<N>(remaining);
        auto const current_most_common_bit = gamma_rate_raw[bit_position];

        remaining.erase(std::remove_if(remaining.begin(), remaining.end(),
                            [&current_most_common_bit, &bit_position](
                                auto& v) { return v[bit_position] == current_most_common_bit; }),
            remaining.end());

        if (remaining.size() == 1) {
            return remaining.at(0).to_ulong();
        }
    }
    // Never reach this line :D
    assert(false);
}

#endif // CODE_KATA_CALCULATE_RATES_HPP
