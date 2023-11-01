#pragma once

#include "AbstractAirModelPattern.hpp"

class ChangeHeightPattern: public AbstractAirModelPattern {
public:
    ChangeHeightPattern(double h);
    ~ChangeHeightPattern();

private:
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) override;
    void CalculateDuration(Vec3 velocity, Vec3 acceleration) override;
    double height;
};
