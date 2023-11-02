#include "Reciever.hpp"

#include <math.h>
#include <vector>

Reciever::Reciever() {}

Reciever::Reciever(Vec3 position) : position{position} {}

void Reciever::TakeSignal(std::vector<Signal>& signals)
{
    SendSignalToTracker(signals);
}

void Reciever::SendSignalToTracker(std::vector<Signal>& signals)
{
    std::vector<Vec3> predicted_positions;
    for (auto signal : signals) {
        predicted_positions.push_back((-1) * signal.direction * (signal.duration / 2));
    }
    tracker.TakeRawData(predicted_positions);
}