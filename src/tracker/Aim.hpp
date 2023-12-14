#pragma once

#include "../src/utils/Vec3.hpp"

class Aim {
public:
    Aim(Vec3 exp_position, double time);

    Vec3 filtered_position;
    Vec3 filtered_velocity;
    Vec3 filtered_acceleration;

    Vec3 extrapolated_position;
    Vec3 extrapolated_velocity;

    double update_time;
    double k;
};
