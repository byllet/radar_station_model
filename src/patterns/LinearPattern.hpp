#pragma once

#include "../utils/Vec3.hpp"
#include "AbstractAirModelPattern.hpp"

class LinearPattern: public AbstractAirModelPattern {
public:
    LinearPattern();
    ~LinearPattern();

private:
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) override;
};
