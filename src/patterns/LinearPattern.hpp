#pragma once

#include "../utils/Vec3.hpp"
#include "AbstractAirModelPattern.hpp"

class LinearPattern: public AbstractAirModelPattern {
public:
    LinearPattern();
    void ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt) override;
    ~LinearPattern();

private:
    Vec3 ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) override;
};