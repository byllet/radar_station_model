#pragma once

#include "AbstractAirModelPattern.hpp"

class ChangeHeightPattern: public AbstractAirModelPattern {
public:
    ChangeHeightPattern(double h);
    ~ChangeHeightPattern();
    void UpdateAcceleration(Vec3& acceleration, double dt) override; 

private:
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) override;
    double height;
};
