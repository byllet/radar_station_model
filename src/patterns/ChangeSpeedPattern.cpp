#include <cmath>

#include "ChangeSpeedPattern.hpp"

ChangeSpeedPattern::ChangeSpeedPattern(Vec3 a) : AbstractAirModelPattern(), new_acceleration{a} {}

ChangeSpeedPattern::~ChangeSpeedPattern() {}

void ChangeSpeedPattern::UpdateAcceleration(Vec3& acceleration, double dt) {}

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
    return new_acceleration;
}
 