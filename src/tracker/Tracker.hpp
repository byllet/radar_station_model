#pragma once

#include <vector>
#include "Aim.hpp"
#include "../Signal.hpp"

class Tracker {
public:
    Tracker() {}
    void TakeSignal(Signal* s, double time);
    
private:
    std::vector<Aim> aims;
    void HandleSignal();
    void UpdateAim();
};