#include "Signal.hpp"

const double MIN_POWER = 1.;

Signal::Signal(Vec3 start_position, Vec3 direction, double power) : position{start_position}, 
                                                                    direction{direction}, 
                                                                    power{power} {}

Signal::Signal() : position{Vec3{0., 0., 0.}} , direction{Vec3{1., 1., 1}}, power{30.} {}

void Signal::Reflection(double EPR)
{
    direction = -1 * direction;
    power *= EPR;
}

void Signal::Update(double dt)
{
    power *= nu;
    position += direction * SIGNALSPEED;
    lifetime += dt;
    if (power > MIN_POWER)
        position += direction;
    else
        alive = false;
}
