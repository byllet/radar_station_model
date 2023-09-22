#pragma once

#include "../Vec3.hpp"
#include "AbstractAirModelPattern.hpp"

class DefaultPattern: public AbstractAirModelPattern {
public:
    DefaultPattern();
    ~DefaultPattern();
    Vec3 ChangePosition(Vec3 velocity, Vec3 acceleration, double dt) override;
    Vec3 ChangeVelocity(Vec3 acceleration, double dt) override;
    Vec3 ChangeAcceleration(double dt) override;
};