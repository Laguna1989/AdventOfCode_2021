#include "calculate_rates.hpp"

std::pair<unsigned long, unsigned long> calculate_rates(std::vector<Diagnostic_input_type> input)
{
    // TODO use dynamic type
    Diagnostic_input_type gamma_rate;
    for (auto position = 0u; position != 5; ++position) {
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
