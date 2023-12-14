#include "../src/patterns/AbstractAirModelPattern.hpp"

AbstractAirModelPattern::AbstractAirModelPattern() {}

AbstractAirModelPattern::~AbstractAirModelPattern() {}

void AbstractAirModelPattern::ApplyPattern(Vec3 &position, Vec3 &velocity, Vec3 &acceleration) 
{
    velocity = ChangeVelocity(velocity, acceleration);
    acceleration = ChangeAcceleration(velocity, acceleration);
    CalculateDuration(velocity, acceleration);
}

void AbstractAirModelPattern::SetDuration(double d) {
    if (d <= 0) {
        d = 0;
    }
    duration = d;
}

double AbstractAirModelPattern::GetDuration()
{
    return duration;
}
