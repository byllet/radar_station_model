#include "Signal.hpp"

Signal::Signal(Vec3 start_position, Vec3 direction, double speed, double duration) : position{start_position}, 
                                                                                     direction{direction}, 
                                                                                     duration{duration} {}

Signal::Signal() : position{Vec3{0., 0., 0.}} , direction{1., 1., 1} {}

void Signal::Reflection()
{
    direction = -1 * direction;
    is_reflected = true;
    collision_position = position;
}

void Signal::Update(double dt)
{
    position += direction * SIGNALSPEED;
    lifetime += dt;
    if (lifetime <= duration) {
        position += direction;
    } else {
        alive = false;
    }
}

Vec3& Signal::GetCollisionPosition()
{
    return collision_position;
}

bool Signal::IsReflected()
{
    return is_reflected;
}
