#pragma once

#include "utils/Vec3.hpp"

const double SIGNALSPEED = 3000.;

class Signal {
public:
    Signal(Vec3 start_position, Vec3 direction);
    Signal();
    void Reflection();
    void Update(double dt);
    
private:
    unsigned int power;
    unsigned int duration_time;
    Vec3 position;
    Vec3 direction; 
};
