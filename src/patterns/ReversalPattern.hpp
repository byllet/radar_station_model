#pragma once

#include "AbstractAirModelPattern.hpp"

class ReversalPattern: public AbstractAirModelPattern {
public:
    ReversalPattern(double radius);
    ~ReversalPattern();
    void UpdateAcceleration(Vec3& acceleration, double dt) override; 

private:
    Vec3 ChangeVelocity(Vec3 velocity, Vec3 acceleration) override;
    Vec3 ChangeAcceleration(Vec3 velocity, Vec3 acceleration) override;
    double radius;
};
