#include "Reciever.hpp"

double const EPS = 1.;

Reciever::Reciever() {}

Reciever::Reciever(Vec3 position) : position{position} {}

void Reciever::TakeSignal(Signal signal)
{
    if (std::sqrt(
    std::pow((signal.position.x - position.x), 2) +
    std::pow((signal.position.y - position.y), 2) + 
    std::pow((signal.position.z - position.z), 2)
    ) < EPS)
    {
       SendSignalToTracker(signal);
    }
}

void Reciever::SendSignalToTracker(Signal signal)
{
    Vec3 predict_position;
    predict_position = (-1) * signal.direction * (signal.duration / 2);
    //send to tracker 
}