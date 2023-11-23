#pragma once

#include "utils/Vec3.hpp"

const double SIGNALSPEED = 50.;

class Signal {
public:
    Signal(Vec3 start_position, Vec3 direction, double power);
    Signal();
    
    void Reflection(/*double EPR*/);
    void Update(double dt);

    Vec3& GetPosition();
    Vec3& GetDirection();
    bool IsAlive();

public:
    bool alive = true;
    Vec3 position;
    Vec3 direction;
    double velocity = SIGNALSPEED;
    double lifetime;
    double power;
};
