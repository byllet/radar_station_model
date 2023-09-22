#include "Plane.hpp"
#include "AbstractAirObject.hpp"
#include "../patterns/DefaultPattern.hpp"

#include <iostream>

Plane::Plane(Vec3 start_pos, Vec3 v, Vec3 a) : AbstractAirObject{start_pos, v, a} {} 

void Plane::update(float dt)
{
    pattern = new DefaultPattern();
    position += pattern->ChangePosition(velocity, acceleration, dt);
    velocity += pattern->ChangeVelocity(acceleration, dt);
    acceleration += pattern->ChangeAcceleration(dt);

    std::cout << "I'm flying at " << position;
    std::cout << "my speed " << velocity;
    std::cout << "my acceleration " << acceleration << std::endl;

    delete pattern;
    return;
}
