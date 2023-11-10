#pragma once

#include <vector>
#include "../src/Signal.hpp"
#include "../src/utils/Matrix.hpp"
#include <cmath>
#include "../src/math/Calculating.hpp"

class Emitter {
public:
    Emitter();
    Emitter(Vec3 position);
    std::vector<Signal> SendSignals(size_t beams_count,
                                    Vec3 direction, 
                                    double solid_angle, 
                                    double duration);
private:
    Vec3 position;
};
