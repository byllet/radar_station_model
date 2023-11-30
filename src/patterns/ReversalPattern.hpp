#pragma once

#include "AbstractAirModelPattern.hpp"

class ReversalPattern: public AbstractAirModelPattern {
public:
    ReversalPattern(double radius);
    ~ReversalPattern();

private:
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) override;
    void CalculateDuration(Vec3 velocity, Vec3 acceleration) override;
    double radius;
    double pattern_speed = 0.;
};
