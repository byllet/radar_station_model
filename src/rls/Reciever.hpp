#pragma once

#include "../tracker/Tracker.hpp"
#include "../Signal.hpp"

class Reciever {
public:
    Reciever();
    void TakeSignal(Signal* s);
    
private:
    Tracker tracker;
};
