#pragma once

#include "AbstractAirModelPattern.hpp"

class ReversalPattern: public AbstractAirModelPattern {
public:
    ReversalPattern();
    void ApplyPattern(Vec3& position, Vec3& velocity, Vec3& acceleration, double dt) override;
    ~ReversalPattern();

private:
    bool done = 0;
    Vec3 ChangePosition(Vec3 position, Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration, double dt) override;
};