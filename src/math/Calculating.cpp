#include "Calculating.hpp"
#include "../utils/Matrix.hpp"

Vec3 GetAvg(std::vector<Vec3>& vec)
{
    Vec3 avg;
    for (auto v: vec) {
        avg += v;
    }
    return avg * (1 / (double)vec.size());
}

Vec3 VectorRotation(Vec3 vec, double alpha, double beta, double gamma)
{
    std::vector<double> vec_matrix = {std::cos(beta) * std::cos(gamma),-std::sin(gamma)*std::cos(beta), std::sin(beta),
                                      std::sin(alpha) * std::sin(beta) * std::cos(gamma) + std::sin(gamma) * std::cos(alpha), -std::sin(alpha)*std::sin(beta)*std::sin(gamma) + std::cos(alpha)*std::cos(gamma), -std::sin(alpha)*std::cos(beta),
                                      std::sin(alpha) * std::sin(gamma) - std::sin(beta)*std::cos(alpha)*std::cos(gamma), std::sin(alpha)*std::cos(gamma) + std::sin(beta)*std::sin(gamma)*std::cos(alpha), std::cos(alpha)*std::cos(beta)};
    Matrix matrix(vec_matrix, 3, 3);
    vec = matrix * vec;
    return vec;
}

Vec3 RotateVec3ForTheFlat(Vec3 vector)
{
    if (vector.z == 0) {
        return vector;
    } else {
        Vec3 rotated = {vector.x, vector.y, 0};
        rotated.Normalization();
        return rotated * vector.Length();
    }
}