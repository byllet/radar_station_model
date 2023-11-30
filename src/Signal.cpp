#include "Signal.hpp"

const double MIN_POWER = 0.;

Signal::Signal(Vec3 start_position, Vec3 direction, double power) : position{start_position}, 
                                                                    direction{direction}, 
                                                                    power{power} {}

Signal::Signal() : position{Vec3{0., 0., 0.}} , direction{Vec3{1., 1., 1}}, power{30.} {}

void Signal::Reflection(/*double EPR*/)
{
    reflected = true;
    direction = -1 * direction;
    //power *= EPR;
}

void Signal::Update(double dt)
{
    power -= 1;
    lifetime += dt;
    if (power > MIN_POWER) {
        position += direction * SIGNALSPEED;
    } else {
        alive = false;
    }
}

bool Signal::IsReflected()
{
    return reflected;
}
