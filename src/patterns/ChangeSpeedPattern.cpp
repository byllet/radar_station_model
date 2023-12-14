#include "../src/patterns/ChangeSpeedPattern.hpp"
#include "../src/math/Calculating.hpp"

#include <cmath>

ChangeSpeedPattern::ChangeSpeedPattern(double desired_speed) : AbstractAirModelPattern(), desired_speed{desired_speed} {}

ChangeSpeedPattern::~ChangeSpeedPattern() {}

Vec3 ChangeSpeedPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
{
    return RotateVec3ForTheFlat(velocity);
}

Vec3 ChangeSpeedPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration)
{
    double a = 9.81 * 1.2;
    Vec3 new_acceleration = velocity.Normalization() * a * (velocity.Length() < desired_speed ? 1 : -1);
    return new_acceleration;
}

void ChangeSpeedPattern::CalculateDuration(Vec3 velocity, Vec3 acceleration) 
{
    if (duration == SHOULD_BE_CALC) {
        duration = std::abs(desired_speed - velocity.Length()) / acceleration.Length();
    }
}
 
