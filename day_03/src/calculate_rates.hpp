#ifndef CODE_KATA_CALCULATE_RATES_HPP
#define CODE_KATA_CALCULATE_RATES_HPP

#include "types.hpp"
#include <bitset>
#include <tuple>
#include <vector>

template <int N>
std::pair<unsigned long, unsigned long> calculate_rates(std::vector<Diagnostic_input_type<N>> input)
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
    return std::pair<unsigned long, unsigned long> { gamma_rate.to_ulong(),
        gamma_rate.flip().to_ulong() };
}

#endif // CODE_KATA_CALCULATE_RATES_HPP
