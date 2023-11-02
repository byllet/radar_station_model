#pragma once

#include "../tracker/Tracker.hpp"
#include "../Signal.hpp"

class Reciever {
public:
    Reciever();
    Reciever(Vec3 position);
    void TakeSignal(Signal signal);
    void SendSignalToTracker(Signal signal);
    
private:
    Vec3 position;
    Tracker tracker;
};
