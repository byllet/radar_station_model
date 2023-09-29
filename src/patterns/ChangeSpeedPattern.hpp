#pragma once

#include "AbstractAirModelPattern.hpp"

class ChangeSpeedPattern: public AbstractAirModelPattern {
public:
    ChangeSpeedPattern(): AbstractAirModelPattern() {}
    ~ChangeSpeedPattern() {}
};