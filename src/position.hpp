#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

struct Position {
    int x { 0 };
    int y { 0 };
};

bool operator==(Position const& lhs, Position const& rhs);

bool operator!=(Position const& lhs, Position const& rhs);

std::string toString(Position const& p);

#endif /*POSITION_HPP*/
