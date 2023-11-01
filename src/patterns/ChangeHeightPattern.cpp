#include "ChangeHeightPattern.hpp"
#include <cmath>

ChangeHeightPattern::ChangeHeightPattern(double h) : AbstractAirModelPattern(), height{h} {}

ChangeHeightPattern::~ChangeHeightPattern() {}

Vec3 ChangeHeightPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
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

Vec3 ChangeHeightPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration)
{
    return {0., 0., 0.};
}

void ChangeHeightPattern::CalculateDuration(Vec3 velocity, Vec3 acceleration) 
{
    if (duration == SHOULD_BE_CALC) {
        duration = height / velocity.z;
    }
}
