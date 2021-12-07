#include "position.hpp"
#include <sstream>

bool operator==(Position const& lhs, Position const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(Position const& lhs, Position const& rhs) { return !(lhs == rhs); }

std::string toString(Position const& p)
{
    std::stringstream str;
    str << "(" << p.x << ", " << p.y << ")";
    return str.str();
};
