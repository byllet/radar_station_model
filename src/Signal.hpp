#pragma once

#include "utils/Vec3.hpp"

const double SIGNALSPEED = 100.;

class Signal {
public:
    Signal(Vec3 start_position, Vec3 direction, double velocity, double duration);
    Signal();
    void Reflection();
    void Update(double dt);
    Vec3& GetPosition();
    Vec3& GetDirection();
    bool IsAlive();
    

public:
    bool alive = true;
    bool is_reflected = false;
    double lifetime = 0;
    Vec3 position;
    Vec3 direction;
    double duration;
};
