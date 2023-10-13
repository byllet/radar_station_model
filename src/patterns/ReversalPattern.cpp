#include <atomic>
#include <cmath>
#include <regex>

#include "ReversalPattern.hpp"

ReversalPattern::ReversalPattern(double radius) : AbstractAirModelPattern(), radius{radius} {}

ReversalPattern::~ReversalPattern() {}

void ReversalPattern::UpdateAcceleration(Vec3& acceleration, double dt)
{
    Vec3 new_acceleration;
    double cycle_speed = std::sqrt(acceleration.Length() * radius) / radius;
    double angle = cycle_speed * dt;
    new_acceleration.x = acceleration.x * std::cos(angle) - acceleration.y * std::sin(angle);
    new_acceleration.y = acceleration.x * std::sin(angle) + acceleration.y * std::cos(angle);
    acceleration = new_acceleration;
}

Vec3 ReversalPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
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

Vec3 ReversalPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration)
{
    Vec3 new_acceleration = {velocity.y, -velocity.x, 0};
    new_acceleration = new_acceleration * (1 / new_acceleration.Length());
    new_acceleration *= (velocity.Length() / radius);
    return new_acceleration;
}
