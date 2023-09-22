#include "Vec3.hpp"
#include <iostream>
#include <ostream>

Vec3::Vec3(double x0, double y0, double z0): x{x0}, y{y0}, z{z0} {}
Vec3::Vec3(): x{0.}, y{0.}, z{0.} {}

std::ostream& operator<< (std::ostream& os, Vec3& v)
{
    os << "{" <<v.x <<  ", " << v.y << ", " << v.z << "} ";  
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

Vec3 Vec3::operator= (Vec3& lhs)
{
    x = lhs.x;
    y = lhs.y;
    z = lhs.z;
    return *this;
}

Vec3 operator* (Vec3& vec, double k)
{
    vec *= k;
    return vec;
}

Vec3 operator* (double k, Vec3& vec)
{
    vec *= k;
    return vec;
}

Vec3 operator+ (Vec3& lhs, Vec3& rhs)
{
    Vec3 res = lhs;
    res += rhs;
    return res;
}