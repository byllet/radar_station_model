#pragma once

#include "AbstractAirModelPattern.hpp"

class ChangeHeightPattern: public AbstractAirModelPattern {
public:
    ChangeHeightPattern(double h);
    void ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt) override;
    ~ChangeHeightPattern();

private:
    Vec3 ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) override;
    double height;
};