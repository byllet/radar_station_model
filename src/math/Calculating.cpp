#include "../src/math/Calculating.hpp"
#include "../src/utils/Matrix.hpp"

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
    std::vector <double> vec_matrix = {cos(beta)*cos(gamma),                                     -sin(gamma)*cos(beta),                                     sin(beta),
                                        sin(alpha)*sin(beta)*cos(gamma) + sin(gamma)*cos(alpha), -sin(alpha)*sin(beta)*sin(gamma) + cos(alpha)*cos(gamma), -sin(alpha)*cos(beta),
                                        sin(alpha)*sin(gamma) - sin(beta)*cos(alpha)*cos(gamma), sin(alpha)*cos(gamma) + sin(beta)*sin(gamma)*cos(alpha), cos(alpha)*cos(beta)};
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
