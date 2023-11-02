#pragma once

#include "../tracker/Tracker.hpp"
#include "../Signal.hpp"
#include <vector>

class Reciever {
public:
    Reciever();
    Reciever(Vec3 position);
    void TakeSignal(std::vector<Signal>& signals);
    
private:
    void SendSignalToTracker(std::vector<Signal>& signal);
    Vec3 position;
    Tracker tracker;
};
