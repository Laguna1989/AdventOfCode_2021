#include "transform.hpp"
#include <sstream>

bool operator==(Transform const& lhs, Transform const& rhs)
{
    return lhs.horizontal == rhs.horizontal && lhs.depth == rhs.depth;
}

bool operator!=(Transform const& lhs, Transform const& rhs) { return !(lhs == rhs); }

std::string toString(Transform const& p)
{
    std::stringstream str;
    str << "(" << p.horizontal << ", " << p.depth << ")";
    return str.str();
};
