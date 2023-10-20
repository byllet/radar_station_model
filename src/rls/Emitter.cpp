#include "Emitter.hpp"

const double PI = 3.14159265359;
const double SIGNALSPEED = 1.;

Emitter::Emitter() {}

Emitter::Emitter(Vec3 position) : position{position} {}

std::vector<Signal> Emitter::SendSignals(size_t beams_count, Vec3 start_position, Vec3 direction, double solid_angle, double duration)
{
    solid_angle = solid_angle < 4*PI ? solid_angle : 4*PI;



    std::vector<Signal> vec_signals(beams_count);
    for (int i = 0; i < beams_count; ++i)
    {
        vec_signals[i] = Signal(start_position, direction, SIGNALSPEED, duration);
    }

    return vec_signals;
}