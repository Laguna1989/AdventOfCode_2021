#ifndef CODE_KATA_CALCULATE_RATES_HPP
#define CODE_KATA_CALCULATE_RATES_HPP

#include "types.hpp"
#include <bitset>
#include <tuple>
#include <vector>

template <int N>
Diagnostic_input_type<N> calculate_gamma_rate_raw(std::vector<Diagnostic_input_type<N>> input)
{
    Diagnostic_input_type<N> gamma_rate;
    for (auto position = 0u; position != gamma_rate.size(); ++position) {
        std::size_t count { 0u };
        for (auto const& value : input) {
            if (value[position]) {
                count++;
            }
        }
        if (count >= input.size() / 2) {
            gamma_rate[position] = true;
        }
    }
    return gamma_rate;
}

template <int N>
unsigned long calculate_gamma_rate(std::vector<Diagnostic_input_type<N>> input)
{
    return calculate_gamma_rate_raw(input).to_ulong();
}

template <int N>
unsigned long calculate_epsilon_rate(std::vector<Diagnostic_input_type<N>> input)
{
    return calculate_gamma_rate_raw(input).flip().to_ulong();
}

#endif // CODE_KATA_CALCULATE_RATES_HPP
