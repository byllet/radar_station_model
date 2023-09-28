#include "Plane.hpp"
#include "AbstractAirObject.hpp"

#include <iostream>

Plane::Plane(Vec3 start_pos, Vec3 v, Vec3 a) : AbstractAirObject{start_pos, v, a} {} 

void Plane::Update(float dt)
{
    position += pattern->ChangePosition(velocity, acceleration, dt);
    velocity += pattern->ChangeVelocity(acceleration, dt);
    acceleration += pattern->ChangeAcceleration(dt);
    
    std::cout << "Plane position::" << position;
    std::cout << "speed::" << velocity;
    std::cout << "acceleration::" << acceleration << std::endl;

    return;
}
