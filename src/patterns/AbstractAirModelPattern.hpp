#pragma once

#include "../Vec3.hpp"

class AbstractAirObject;

class AbstractAirModelPattern {
public:
    AbstractAirModelPattern() {}
    virtual Vec3 ChangePosition(Vec3 velocity, Vec3 acceleration, double dt) = 0;
    virtual Vec3 ChangeVelocity(Vec3 acceleration, double dt) = 0;
    virtual Vec3 ChangeAcceleration(double dt) = 0;
    virtual ~AbstractAirModelPattern() {};
    
protected:
    int time;
};