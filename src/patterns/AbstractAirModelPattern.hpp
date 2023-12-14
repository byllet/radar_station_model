#pragma once

#include "../src/utils/Vec3.hpp"

const double SHOULD_BE_CALC = 1000031.1;

class AbstractAirModelPattern {
public:
    AbstractAirModelPattern();
    virtual ~AbstractAirModelPattern();

    void ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration);
    void SetDuration(double duration);
    double GetDuration();
       
protected:
    virtual Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) = 0;
    virtual Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) = 0;
    virtual void CalculateDuration(Vec3 velocity, Vec3 acceleration) = 0;
    double duration = SHOULD_BE_CALC;
};
