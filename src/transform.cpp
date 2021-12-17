#include "transform.hpp"
#include <sstream>

bool operator==(Transform const& lhs, Transform const& rhs)
{
    return lhs.horizontal == rhs.horizontal && lhs.depth == rhs.depth && lhs.aim == rhs.aim;
}

bool operator!=(Transform const& lhs, Transform const& rhs) { return !(lhs == rhs); }

std::string to_string(Transform const& p)
{
    std::stringstream str;
    str << "(" << p.horizontal << ", " << p.depth << ", " << p.aim << ")";
    return str.str();
}

void PrintTo(Transform const& t, std::ostream* os)
{
    *os << to_string(t); // whatever needed to print bar to os
};
