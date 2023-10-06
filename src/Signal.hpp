#pragma once

#include "utils/Vec3.hpp"

const double SIGNALSPEED = 3000.;

class Signal {
public:
    Signal(Vec3 start_position, Vec3 direction, double velocity, double duration);
    Signal();
    void Reflection();
    void Update(double dt);
    
public:
    double lifetime = 0;
    unsigned int power;
    unsigned int duration;
    Vec3 position;
    Vec3 direction;
    double velocity;
};
