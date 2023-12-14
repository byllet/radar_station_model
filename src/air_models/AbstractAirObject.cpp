#include "../src/air_models/AbstractAirObject.hpp"

AbstractAirObject::AbstractAirObject(Vec3 start_pos, Vec3 v, Vec3 a) : position{start_pos}, velocity{v}, acceleration{a} {}

AbstractAirObject::~AbstractAirObject() {}

Vec3& AbstractAirObject::GetPosition()
{
    return position;
}

Vec3& AbstractAirObject::GetVelocity()
{
    return velocity;
}

Vec3& AbstractAirObject::GetAcceleretion()
{
    return acceleration;
}

double AbstractAirObject::GetEPR()
{
    return EPR;
}

void AbstractAirObject::SetPattern(AbstractAirModelPattern* p)
{
    pattern = p;
    pattern->ApplyPattern(position, velocity, acceleration);
}

AbstractAirModelPattern* AbstractAirObject::GetPattern()
{
    return pattern;
}

double AbstractAirObject::GetDetectionSize()
{
    return detection_size;
}
