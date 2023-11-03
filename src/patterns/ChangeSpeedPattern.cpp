#include "ChangeSpeedPattern.hpp"
#include "../math/Calculating.hpp"

#include <cmath>

ChangeSpeedPattern::ChangeSpeedPattern(double desired_speed) : AbstractAirModelPattern(), desired_speed{desired_speed} {}

ChangeSpeedPattern::~ChangeSpeedPattern() {}

Vec3 ChangeSpeedPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
{
    return RotateVec3ForTheFlat(velocity);
}

Vec3 ChangeSpeedPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration)
{
    Vec3 new_acceleration {1.2 * 9.81, 1.2 * 9.81, 0};
    return new_acceleration;
}

void ChangeSpeedPattern::CalculateDuration(Vec3 velocity, Vec3 acceleration) 
{
    if (duration == SHOULD_BE_CALC) {
        duration = (desired_speed - velocity.Length()) / acceleration.Length();
    }
}
 