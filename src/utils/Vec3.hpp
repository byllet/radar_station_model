#pragma once

#include <ostream>

class Vec3 {
public:
    Vec3(double x0, double y0, double z0);
    Vec3(const Vec3& another);
    Vec3();
    Vec3& operator+= (const Vec3& vec);
    Vec3& operator-= (const Vec3& vec);
    Vec3& operator*= (double k);
    Vec3& operator/= (double k);
    Vec3& operator= (const Vec3& lhs);
    Vec3& Normalization();
    double Length();
    
public:
    double x;
    double y;
    double z;
};

Vec3 operator* (const Vec3& vec, double k);
Vec3 operator* (double k, const Vec3& vec);

Vec3 operator/ (const Vec3& vec, double k);
Vec3 operator/ (double k, const Vec3& vec);

Vec3 operator+ (const Vec3& lhs, const Vec3& rhs);
Vec3 operator- (const Vec3& lhs, const Vec3& rhs);

bool operator==(const Vec3& lhs, const Vec3& rhs);
bool operator!=(const Vec3& lhs, const Vec3& rhs);

std::ostream& operator<< (std::ostream& os, Vec3& v);
