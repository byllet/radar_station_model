#include "ChangeSpeedPattern.hpp"

ChangeSpeedPattern::ChangeSpeedPattern(Vec3 a) : AbstractAirModelPattern(), acceleration{a} {}

ChangeSpeedPattern::~ChangeSpeedPattern() {}

void ChangeSpeedPattern::ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt)
{
    position = ChangePosition(position, velocity, acceleration, dt);
    velocity = ChangeVelocity(velocity, acceleration, dt);
    acceleration = ChangeAcceleration(velocity, acceleration, dt);
}

Vec3 ChangeSpeedPattern::ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) 
{
    return position + velocity * dt + acceleration * (dt * dt / 2);
}

Vec3 ChangeSpeedPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) 
{
    return velocity + acceleration * dt;
}

Vec3 ChangeSpeedPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) 
{
    return {0, 0, 0};
}
 