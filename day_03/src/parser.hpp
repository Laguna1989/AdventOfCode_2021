#ifndef CODE_KATA_PARSER_HPP
#define CODE_KATA_PARSER_HPP

#include "types.hpp"
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

std::vector<std::string> parse(std::string const& input);

template <int N>
std::vector<Diagnostic_input_type<N>> convert(std::vector<std::string> const& input)
{
    std::vector<Diagnostic_input_type<N>> result;
    result.resize(input.size());
    std::transform(input.cbegin(), input.cend(), result.begin(),
        [](auto const& str) { return Diagnostic_input_type<N> { str }; });
    return result;
}

#endif // CODE_KATA_PARSER_HPP
