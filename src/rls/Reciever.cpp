#include "Reciever.hpp"

#include <math.h>
#include <vector>

Reciever::Reciever() {}

Reciever::Reciever(Vec3 position) : position{position} {}

void Reciever::TakeSignal(std::vector<Signal>& signals_vec, double dt)
{
    SendSignalToTracker(signals_vec, dt);
}

void Reciever::SendSignalToTracker(std::vector<Signal>& signals_vec, double dt)
{ 
    std::vector<Vec3> predicted_positions;
    for (auto signal : signals_vec) {
        predicted_positions.push_back(-1 * signal.direction * (signal.lifetime / 2 / dt) * SIGNALSPEED);
    }
    tracker.TakeRawData(predicted_positions);
}

Tracker& Reciever::GetTracker()
{
    return tracker;
}