#pragma once

#include "../Vec3.hpp"

class Aim {
public:
    Aim() {}
    void GetExpectedData();

private:
    Vec3 ExpectedPosition;
    Vec3 ExpectedVecolcity;
    Vec3 ExpectedAcceleration;
};