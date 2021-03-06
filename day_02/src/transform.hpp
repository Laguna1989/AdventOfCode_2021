#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

struct Transform {
    int horizontal { 0 };
    int depth { 0 };
    int aim { 0 };
};

bool operator==(Transform const& lhs, Transform const& rhs);

bool operator!=(Transform const& lhs, Transform const& rhs);

std::string to_string(Transform const& p);

void PrintTo(Transform const& t, std::ostream* os);

#endif /*POSITION_HPP*/
