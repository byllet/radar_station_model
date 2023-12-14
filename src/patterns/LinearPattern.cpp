#include "../src/patterns/LinearPattern.hpp"
#include "../src/math/Calculating.hpp"

#include <cmath>

LinearPattern::LinearPattern() : AbstractAirModelPattern()
{
    SetDuration(-1);
}

LinearPattern::LinearPattern(double time) : AbstractAirModelPattern{}
{
    SetDuration(time);
}

LinearPattern::~LinearPattern() {}

Vec3 LinearPattern::ChangeVelocity(Vec3 velocity, Vec3 acceleration)
{
    return RotateVec3ForTheFlat(velocity);
}

Vec3 LinearPattern::ChangeAcceleration(Vec3 velocity, Vec3 acceleration)
{
    return {0., 0., 0.};
}

void LinearPattern::CalculateDuration(Vec3 velocity, Vec3 acceleration) {}
