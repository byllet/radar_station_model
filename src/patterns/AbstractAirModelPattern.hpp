#pragma once

#include "../utils/Vec3.hpp"

class AbstractAirObject;

class AbstractAirModelPattern {
public:
    AbstractAirModelPattern();
    virtual ~AbstractAirModelPattern();
    virtual void UpdateAcceleration(Vec3& acceleration, double dt) = 0; 

    void ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration);
    void SetDuration(double duration);
    double GetDuration();
       
protected:
    virtual Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) = 0;
    virtual Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) = 0;
    double duration;
};
