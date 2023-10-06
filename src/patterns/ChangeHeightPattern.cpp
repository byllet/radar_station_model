#include "ChangeHeightPattern.hpp"
#include <cmath>

ChangeHeightPattern::ChangeHeightPattern(double h) : AbstractAirModelPattern(), height{h} {}

ChangeHeightPattern::~ChangeHeightPattern() {}

void ChangeHeightPattern::ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt)
{
    position = ChangePosition(position, velocity, acceleration, dt);
    velocity = ChangeVelocity(velocity, acceleration, dt);
    acceleration = ChangeAcceleration(velocity, acceleration, dt);
}

Vec3 ChangeHeightPattern::ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) 
{
    return position + velocity * dt;
}

Vec3 ChangeHeightPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) 
{
    if (velocity.z == 0) {
        Vec3 new_velocity{velocity};
        new_velocity.z =  velocity.Length();
        new_velocity = new_velocity * (1 / std::sqrt(2));
        return new_velocity;
    } else {
        return velocity;
    }
}

Vec3 ChangeHeightPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt)
{
    return {0., 0., 0.};
}
