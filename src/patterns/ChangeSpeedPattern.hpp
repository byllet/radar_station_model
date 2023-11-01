#pragma once

#include "AbstractAirModelPattern.hpp"

class ChangeSpeedPattern: public AbstractAirModelPattern {
public:
    ChangeSpeedPattern(Vec3 acceleration);
    ~ChangeSpeedPattern();

private:
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) override;
    Vec3 new_acceleration;
};
