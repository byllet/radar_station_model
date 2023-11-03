#include "Aim.hpp"

Aim::Aim(Vec3 exp_position, double time) : filtered_position{exp_position}, 
                                           update_time{time},
                                           filtered_velocity{},
                                           filtered_acceleration{},
                                           extrapolated_position{},
                                           extrapolated_velocity{},
                                           k{1.} 
{}