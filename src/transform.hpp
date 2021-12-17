#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

struct Transform {
    int horizontal { 0 };
    int depth { 0 };
};

bool operator==(Transform const& lhs, Transform const& rhs);

bool operator!=(Transform const& lhs, Transform const& rhs);

std::string toString(Transform const& p);

#endif /*POSITION_HPP*/
