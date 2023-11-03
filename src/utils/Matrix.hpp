#pragma once

#include <vector>
#include <cstring>
#include "Vec3.hpp"

class Matrix
{
private:
    double *a = nullptr;                                            // указатель на область данных
    int n = 0;                                                      // размер n - по вертикали
    int m = 0;                                                      // размер m - по горизонтали
public:
    Matrix();                                                       // конструктор по умолчанию
    Matrix(const std::vector<double>& vec, int nn, int mm);         // конструктор от вектора
    Matrix(const Matrix& matr);                                     // конструктор от матрицы
    ~Matrix();

    void printMatrix() const;                                       // печать матрицы
    void set(const std::vector<double>& vec, int nn, int mm); // инициализация массивом
    int size();                                                     // размер матрицы
    int N() const;                                                  // размер n - по вертикали
    int M() const;                                                  // размер m - по горизонтали
    double* pointer() const;                                        // указатель на первый элемент матрицы

    double* operator[](int t) const;                                // обращение к элементу
    Matrix& operator*= (double num);                                // умножение матрицы на число *=
    Matrix operator* (double num);                                  // умножение матрицы на число *

    Vec3 operator* (const Vec3& vec);                       // матрицу умножить на Vec3

    void operator= (const Matrix& matrix);                          // оператор копирования
};

Vec3 operator* (const Vec3& vec, const Matrix& matr);       // Vec3 умножить на матрицу

