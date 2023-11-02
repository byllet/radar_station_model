#pragma once

#include <vector>
#include "../utils/Vec3.hpp"
#include "../Signal.hpp"

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