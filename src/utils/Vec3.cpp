#include "Vec3.hpp"

Vec3::Vec3()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vec3::Vec3(double xx, double yy, double zz)
{
    x = xx;
    y = yy;
    z = zz;
}
Vec3::Vec3(const Vec3& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

void Vec3::setCoord(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vec3::length()
{
    return std::sqrt(x*x + y*y + z*z);
}

double Vec3::X() const {return x;}
double Vec3::Y() const {return y;}
double Vec3::Z() const {return z;}

Vec3& Vec3::operator= (const Vec3& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

bool Vec3::operator== (const Vec3& vec)
{
    if (x == vec.X() && y == vec.Y() && z == vec.Z())
        return true;
    return false;
}

bool Vec3::operator !=(const Vec3& vec)
{ return !(*this == vec); }

Vec3& Vec3::operator*= (double a)
{
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

Vec3 operator* (const Vec3& vec, double a)
{
    Vec3 copy = vec;
    copy *= a;
    return copy;
}

Vec3 operator* (double a, const Vec3& vec)
{
    Vec3 copy = vec;
    copy *= a;
    return copy;
}

Vec3& Vec3::operator+= (const Vec3& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vec3 Vec3::operator+ (const Vec3& vec)
{
    Vec3 copy = *this;
    copy += vec;
    return copy;
}

Vec3& Vec3::operator-= (const Vec3& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

Vec3 Vec3::operator- (const Vec3& vec)
{
    Vec3 copy = *this;
    copy += vec;
    return copy;
}

Vec3& Vec3::operator*= (const Vec3& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
}

Vec3 Vec3::operator* (const Vec3& vec)
{
    Vec3 copy = *this;
    copy *= vec;
    return copy;
}

std::ostream& operator<< (std::ostream& os, const Vec3& vec)
{
    os << "{" << vec.X() <<  ", " << vec.Y() << ", " << vec.Z() << "} ";  
    return os;
}