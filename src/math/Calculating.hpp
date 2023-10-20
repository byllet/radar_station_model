#pragma once

#include "../utils/Vec3.hpp"

#include <vector>

Vec3 GetAvg(std::vector<Vec3>& vec)
{
    Vec3 avg;
    for (auto v: vec) {
        avg += v;
    }
    return avg * (1 / (double)vec.size());
}
