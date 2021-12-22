#ifndef UPDATE_POSITION_HPP
#define UPDATE_POSITION_HPP

#include "transform.hpp"
#include "transform_command.hpp"
#include <vector>

Transform update_transform(Transform const& transform, TransformCommand command);

Transform update_transform_consecutive(std::vector<TransformCommand> const& move_commands);

#endif // UPDATE_POSITION_HPP
