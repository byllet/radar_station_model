#include "LinearPattern.hpp"
#include <cmath>

LinearPattern::LinearPattern() : AbstractAirModelPattern() {}

LinearPattern::~LinearPattern() {}

Vec3 LinearPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
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

Vec3 LinearPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration)
{
    return {0., 0., 0.};
}
