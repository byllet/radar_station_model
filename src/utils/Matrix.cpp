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
    Vec3 copy;
    copy.setCoord((*this)[0][0] * vec.X() + (*this)[0][1] * vec.Y() + (*this)[0][2] * vec.Z(),
                  (*this)[1][0] * vec.X() + (*this)[1][1] * vec.Y() + (*this)[1][2] * vec.Z(),
                  (*this)[2][0] * vec.X() + (*this)[2][1] * vec.Y() + (*this)[2][2] * vec.Z());
    return copy;
}

Vec3 operator* (const Vec3& vec, const Matrix& matr)
{
    Vec3 copy;
    copy.setCoord(matr[0][0] * vec.X() + matr[0][1] * vec.Y() + matr[0][2] * vec.Z(),
                  matr[1][0] * vec.X() + matr[1][1] * vec.Y() + matr[1][2] * vec.Z(),
                  matr[2][0] * vec.X() + matr[2][1] * vec.Y() + matr[2][2] * vec.Z());
    return copy;
}