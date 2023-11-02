#include <iostream>

#include "Matrix.hpp"

Matrix::Matrix()
{
    a = nullptr;
    n = 0;
    m = 0;
}

Matrix::Matrix(const std::vector<double>& vec, int nn, int mm)
{
    n = nn;
    m = mm;
    if(a) delete[] a;
    a = new double[n * m];
    memcpy(a, vec.data(), n * m * sizeof(double));
}

Matrix::Matrix(const Matrix& matr)
{
    n = matr.N();
    m = matr.M();
    if(a) delete[] a;
    a = new double[n * m];
    memcpy(a, matr.pointer(), n * m * sizeof(double));
}

Matrix::~Matrix()
{
    if (a)
        delete[] a;
}

void Matrix::printMatrix() const
{
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
            std::cout << a[y * m + x] << ' ';
        std::cout << std::endl;
    }
}

void Matrix::set(const std::vector<double>& vec, int nn, int mm)
{
    if (a) delete[] a;
    n = nn;
    m = mm;
    a = new double[n * m];
    memcpy(a, vec.data(), n * m * sizeof(double));
}

int Matrix::size()
{
    return n * m;
}

int Matrix::N() const
{
    return n;
}

int Matrix::M() const
{
    return m;
}

double* Matrix::pointer() const
{
    return a;
}

double* Matrix::operator[](int t) const
{
    return a + m * t;
}

Matrix& Matrix::operator*= (double num)
{
    for (int i = 0; i < n * m; ++i)
        a[i] *= num;
    return *this;
}

Matrix Matrix::operator* (double num)
{
    Matrix copy = *this;
    copy *= num;
    return copy;
}

void Matrix::operator =(const Matrix& matr)
{
    n = matr.N();
    m = matr.M();
    if(a) delete[] a;
    a = new double[n * m];
    memcpy(a, matr.pointer(), n * m * sizeof(double));
}

Vec3 Matrix::operator* (const Vec3& vec)
{
    Vec3 copy((*this)[0][0] * vec.x + (*this)[0][1] * vec.y + (*this)[0][2] * vec.z,
                  (*this)[1][0] * vec.x + (*this)[1][1] * vec.y + (*this)[1][2] * vec.z,
                  (*this)[2][0] * vec.x + (*this)[2][1] * vec.y + (*this)[2][2] * vec.z);
    return copy;
}

Vec3 operator* (const Vec3& vec, const Matrix& matr)
{
    Vec3 copy(matr[0][0] * vec.x + matr[0][1] * vec.y + matr[0][2] * vec.z,
                  matr[1][0] * vec.x + matr[1][1] * vec.y + matr[1][2] * vec.z,
                  matr[2][0] * vec.x + matr[2][1] * vec.y + matr[2][2] * vec.z);
    return copy;
}