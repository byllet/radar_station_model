#include <atomic>
#include <cmath>
#include <regex>

#include "ReversalPattern.hpp"

ReversalPattern::ReversalPattern(double radius) : AbstractAirModelPattern(), radius{radius} {}

ReversalPattern::~ReversalPattern() {}

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
    //TODO: fix problem with uncontrolled acceleration 
    // if (constspeed == 0.) {
    //     constspeed = velocity.Length();
    // }
    // velocity = velocity.Normalization() * constspeed;
    // 
    Vec3 new_acceleration = {velocity.y, -velocity.x, 0};
    new_acceleration = new_acceleration / new_acceleration.Length();
    double v = velocity.Length();
    new_acceleration *= (v * v / radius);
    return new_acceleration;
}
