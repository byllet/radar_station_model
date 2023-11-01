#include "Aim.hpp"

Aim::Aim(Vec3 exp_position, double time) : expected_position{exp_position}, 
                                update_time{time},
                                expected_vecolcity{},
                                expected_acceleration{} {}

Vec3 Aim::GetExpectedPoisiton()
{
    return expected_position;
}

void Aim::SetExpectedPosition(Vec3 new_positon)
{
    expected_position = new_positon; 
}

double Aim::GetUpdateTime()
{
    return update_time;
}

void Aim::SetUpdateTime(double time)
{
    update_time = time;
}