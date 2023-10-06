#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

class Vec3
{
public:
    double x;
    double y;
    double z;
public:
    Vec3();                                    // конструктор по умолчанию
    Vec3(double xx, double yy, double zz);     // конструктор от трех координат
    Vec3(const Vec3& vec);                     // конструктор от вектора 3D

    void setCoord(double x, double y, double z);  // установка координат
    double length();                                // длина вектора

    double X() const;                             // x
    double Y() const;                             // y
    double Z() const;                             // z

    Vec3& operator= (const Vec3& vec);

    Vec3& operator*= (double a);               // умножение вектора 3D на число *=

    Vec3& operator+= (const Vec3& vec);   // сложение вектора 3D c вектором 3D +=
    Vec3 operator+ (const Vec3& vec);     // сложение вектора 3D c вектором 3D +

    Vec3& operator-= (const Vec3& vec);   // вычитание вектора 3D с вектором 3D -=
    Vec3 operator- (const Vec3& vec);     // вычитание вектора 3D с вектором 3D -

    Vec3& operator*= (const Vec3& vec);   // умножение вектора 3D на вектор 3D *=
    Vec3 operator* (const Vec3& vec);     // умножение вектора 3D на вектор 3D *

    bool operator== (const Vec3& vec);
    bool operator!= (const Vec3& vec);
};

Vec3 operator* (const Vec3& vec, double a); // умножение вектора 3D на число *
Vec3 operator* (double a, const Vec3& vec); // умножение числа на вектор 3D *

std::ostream& operator<< (std::ostream& os, Vec3& v);

#endif // VEC_H