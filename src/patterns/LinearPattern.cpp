#include "LinearPattern.hpp"
#include <cmath>

LinearPattern::LinearPattern() : AbstractAirModelPattern() {}

LinearPattern::~LinearPattern() {}

void LinearPattern::ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt)
{
    position = ChangePosition(position, velocity, acceleration, dt);
    velocity = ChangeVelocity(velocity, acceleration, dt);
    acceleration = ChangeAcceleration(velocity, acceleration, dt);
}

Vec3 LinearPattern::ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) 
{
    return position + velocity * dt;
}

Vec3 LinearPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) 
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

Vec3 LinearPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) 
{
    return {0., 0., 0.};
}
