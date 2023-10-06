#pragma once

#include "../utils/Vec3.hpp"

class Aim {
public:
    Aim() {}
    void GetExpectedData();

private:
    Vec3 ExpectedPosition;
    Vec3 ExpectedVelocity;
    Vec3 ExpectedAcceleration;
};