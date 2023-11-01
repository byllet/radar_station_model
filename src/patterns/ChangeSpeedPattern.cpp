#include <cmath>

#include "ChangeSpeedPattern.hpp"

ChangeSpeedPattern::ChangeSpeedPattern(double desired_speed) : AbstractAirModelPattern(), desired_speed{desired_speed} {}

ChangeSpeedPattern::~ChangeSpeedPattern() {}

Vec3 ChangeSpeedPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
{
    if (velocity.z == 0) {
        return velocity;
    } else {
        double alpha = std::atan(velocity.y / velocity.x);
        double length = velocity.Length();
        Vec3 new_velocity(length * std::cos(alpha), length * std::sin(alpha), 0);
        return new_velocity;
    }
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
 