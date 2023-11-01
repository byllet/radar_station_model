#pragma once

#include "AbstractAirModelPattern.hpp"

class ChangeSpeedPattern: public AbstractAirModelPattern {
public:
    ChangeSpeedPattern(double desired_speed);
    ~ChangeSpeedPattern();

private:
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) override;
    void CalculateDuration(Vec3 velocity, Vec3 acceleration) override;
    double desired_speed;
};
