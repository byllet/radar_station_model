#include "Signal.hpp"

Signal::Signal(Vec3 start_position, Vec3 direction, double speed, double duration) : position{start_position}, direction{direction}, velocity{velocity}, duration{duration} {}

Signal::Signal() : position{Vec3{0., 0., 0.}} , direction{1., 1., 1.}, velocity{1.} {}

void Signal::Reflection()
{
    direction = -1 * direction;
}

void Signal::Update(double dt)
{
    position += direction * SIGNALSPEED;
}
