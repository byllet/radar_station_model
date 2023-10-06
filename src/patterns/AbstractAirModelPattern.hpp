#pragma once

#include "../utils/Vec3.hpp"

class AbstractAirObject;

class AbstractAirModelPattern {
public:
    AbstractAirModelPattern() {};
    virtual void ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt) = 0;
    virtual ~AbstractAirModelPattern() {};
    
protected:
    virtual Vec3 ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) = 0;
    virtual Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) = 0;
    virtual Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) = 0;
    double duration;
};