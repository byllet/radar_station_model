#include "ReversalPattern.hpp"

ReversalPattern::ReversalPattern() : AbstractAirModelPattern() {}

ReversalPattern::~ReversalPattern() {}

void ReversalPattern::ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt)
{
    position = ChangePosition(position, velocity, acceleration, dt);
    velocity = ChangeVelocity(velocity, acceleration, dt);
    acceleration = ChangeAcceleration(velocity, acceleration, dt);
}

Vec3 ReversalPattern::ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) 
{
    return position + velocity * dt;
}

Vec3 ReversalPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) 
{
    if (!done) {
        return -1 * velocity;
    } else {
        return velocity;
    }
}

Vec3 ReversalPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) 
{
    return {0., 0., 0.};
}