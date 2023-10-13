#include "Plane.hpp"
#include "AbstractAirObject.hpp"

#include <iostream>

Plane::Plane(Vec3 start_pos, Vec3 v, Vec3 a) : AbstractAirObject{start_pos, v, a} {} 

Plane::~Plane() {}

void Plane::Update(double dt)
{
    velocity += acceleration * dt;
    position +=  velocity + acceleration * (dt * dt / 2.); 
    pattern->UpdateAcceleration(acceleration, dt); 
    
    // std::cout << "Plane position:: " << position;
    // std::cout << " speed:: " << velocity;
    // std::cout << " acceleration:: " << acceleration << std::endl;
    std::cout << position << ' ';
}
