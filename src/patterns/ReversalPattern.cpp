#include "ReversalPattern.hpp"
#include "../math/Calculating.hpp"

#include <cmath>

ReversalPattern::ReversalPattern(double radius) : AbstractAirModelPattern(), radius{radius} {}

ReversalPattern::~ReversalPattern() {}

Vec3 ReversalPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
{
    if (pattern_speed == 0.) {
        pattern_speed = velocity.Length();
    }
    velocity.Normalization();
    velocity *= pattern_speed;

    return RotateVec3ForTheFlat(velocity);
}


Vec3 ReversalPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration)
{
    //TODO: fix problem with uncontrolled acceleration 
    Vec3 new_acceleration = {velocity.y, -velocity.x, 0};
    new_acceleration.Normalization();
    double v = velocity.Length();
    new_acceleration *= (v * v / radius);
    return new_acceleration;
}

void ReversalPattern::CalculateDuration(Vec3 velocity, Vec3 acceleration) 
{
    if (duration == SHOULD_BE_CALC) {
        duration = std::acos(-1) * radius / velocity.Length();
    }
}
