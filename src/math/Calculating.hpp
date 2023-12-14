#pragma once

#include "../src/utils/Vec3.hpp"

#include <vector>
#include <cmath>

Vec3 GetAvg(std::vector<Vec3>& vec);

Vec3 VectorRotation(Vec3 vec, double alpha, double beta, double gamma);

Vec3 RotateVec3ForTheFlat(Vec3 vector);
