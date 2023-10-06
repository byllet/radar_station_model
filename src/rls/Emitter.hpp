#pragma once

#include <vector>
#include "../utils/Vec3.hpp"
#include "../Signal.hpp"

class Emitter {
public:
    Emitter() {}
    std::vector<Signal*> SendSignals(size_t beams_count, Vec3 direction, size_t duration);
};