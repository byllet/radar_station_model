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
    bool alive = true;
    double lifetime = 0;
    unsigned int power;
    double duration;
    Vec3 position;
    Vec3 direction;
    double velocity;
};
