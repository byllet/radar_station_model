#pragma once

#include "AbstractAirModelPattern.hpp"

class ChangeSpeedPattern: public AbstractAirModelPattern {
public:
    ChangeSpeedPattern(Vec3 acceleration);
    void ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt) override;
    ~ChangeSpeedPattern();
private:
    Vec3 acceleration;
    Vec3 ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) override;
};