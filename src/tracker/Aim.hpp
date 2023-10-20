#pragma once

#include "../utils/Vec3.hpp"

class Aim {
public:
    Aim(Vec3 exp_position, double time);
    Vec3 GetExpectedPoisiton();
    void SetExpectedPosition(Vec3 new_positon);
    double GetUpdateTime();
    void SetUpdateTime(double time);

private:
    Vec3 expected_position;
    Vec3 expected_vecolcity;
    Vec3 expected_acceleration;
    double update_time;
};