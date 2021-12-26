#ifndef CODE_KATA_CALCULATE_RATES_HPP
#define CODE_KATA_CALCULATE_RATES_HPP

#include "types.hpp"
#include <bitset>
#include <tuple>
#include <vector>

// TODO const& everywhere!

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
    return calculate_gamma_rate_raw<N>(input).to_ulong();
}

template <int N>
unsigned long calculate_epsilon_rate(std::vector<Diagnostic_input_type<N>> input)
{
    return calculate_gamma_rate_raw<N>(input).flip().to_ulong();
}

template <int N>
unsigned long calculate_oxygen_generator_rate(std::vector<Diagnostic_input_type<N>> input)
{
    std::vector<Diagnostic_input_type<N>> remaining { input };
    for (auto position = 0u; position != input.size(); ++position) {
        std::size_t count_one { 0u };
        for (auto const& value : input) {
            if (value[position]) {
                count_one++;
            }
        }
        if (count_one >= input.size() / 2) {
            gamma_rate[position] = true; // TODO
        }
    }
    return 0;
}

#endif // CODE_KATA_CALCULATE_RATES_HPP
