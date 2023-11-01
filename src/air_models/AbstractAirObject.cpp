#include "AbstractAirObject.hpp"

AbstractAirObject::AbstractAirObject(Vec3 start_pos, Vec3 v, Vec3 a) : position{start_pos}, velocity{v}, acceleration{a} {}

AbstractAirObject::~AbstractAirObject() {}

void AbstractAirObject::SetPattern(AbstractAirModelPattern* p)
{
    pattern = p;
    pattern->ApplyPattern(position, velocity, acceleration);
}
