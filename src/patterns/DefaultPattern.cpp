#include "DefaultPattern.hpp"

DefaultPattern::DefaultPattern() : AbstractAirModelPattern() {}
DefaultPattern::~DefaultPattern() {}

Vec3 DefaultPattern::ChangePosition(Vec3 velocity, Vec3 acceleration, double dt) 
{
    return velocity * dt;
}

Vec3 DefaultPattern::ChangeVelocity(Vec3 velocity, double dt) 
{
    return {0., 0., 0.};
}

Vec3 DefaultPattern::ChangeAcceleration(double dt) 
{
    return {0., 0., 0.};
}
