#pragma once

#include <ostream>

class Vec3 {
public:
    Vec3(double x0, double y0, double z0);
    Vec3();
    Vec3& operator+= (const Vec3& vec);
    Vec3& operator*= (double k);
    void operator= (const Vec3& lhs);
    
public:
    double x;
    double y;
    double z;
};

Vec3 operator* (Vec3& vec, double k);
Vec3 operator* (double k, Vec3& vec);
Vec3 operator+ (const Vec3& lhs, const Vec3& rhs);

std::ostream& operator<< (std::ostream& os, Vec3& v);