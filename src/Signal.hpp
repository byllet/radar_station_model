#pragma once

#include "Vec3.hpp"

class Signal {
public:
    Signal();
    void Reflection();
    void Update(float dt);
    
private:
    unsigned int power;
    Vec3 direction;
    Vec3 position;
    int time;
    int duration_time;
};