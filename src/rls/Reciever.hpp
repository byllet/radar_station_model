#pragma once

#include "../tracker/Tracker.hpp"
#include "../Signal.hpp"
#include <vector>

class Reciever {
public:
    Reciever();
    Reciever(Vec3 position);
    void TakeSignal(std::vector<Signal>& signals_vec, double dt);
    Tracker& GetTracker();
    
private:
    void SendSignalToTracker(std::vector<Signal>& signals_vec, double dt);
    Vec3 position;
    Tracker tracker;
};
