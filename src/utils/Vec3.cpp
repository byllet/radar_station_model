#include "Vec3.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Vec3::Vec3(double x0, double y0, double z0): x{x0}, y{y0}, z{z0} {}
Vec3::Vec3(): x{0.}, y{0.}, z{0.} {}

std::ostream& operator<< (std::ostream& os, Vec3& v)
{
    os << "{" << v.x <<  ", " << v.y << ", " << v.z << "} ";  
    return os;
}

Vec3& Vec3::operator+= (const Vec3& vec)  
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vec3& Vec3::operator*= (double k)
{
    x *= k;
    y *= k;
    z *= k;
    return *this;
}

Vec3& Vec3::operator= (const Vec3& rhs)
{
    if (this == &rhs) {
        return *this;
    }

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Vec3& Vec3::Normalization()
{
    double length = Length();
    if (length != 0) {
        double inv_length = 1. / Length();
        return (*this * inv_length);
    }
    return *this;
}

double Vec3::Length()
{
    return std::sqrt(x*x + y*y + z*z);
}

Vec3& operator* (Vec3& vec, double k)
{
    vec *= k;
    return vec;
}

Vec3& operator* (double k, Vec3& vec)
{
    vec *= k;
    return vec;
}

Vec3 operator+ (const Vec3& lhs, const Vec3& rhs)
{
    Vec3 res = lhs;
    res += rhs;
    return res;
}