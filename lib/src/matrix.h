#pragma once
#include <vector>

namespace math
{
    typedef double real;

    class Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;

    public:
        Matrix() {};

        Matrix(int rows, int cols): cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};

        real& operator()(int row, int col);

        real operator()(int row, int col) const;

        void print() const;

        friend Matrix operator+(const Matrix& A, const Matrix& B);
        friend Matrix operator-(const Matrix& A, const Matrix& B);
        friend Matrix operator*(const Matrix& A, const Matrix& B);

      //  friend Matrix operator+=(const Matrix& l, const Matrix& r);
       // friend Matrix operator-=(const Matrix& A, const Matrix& B);
       // friend Matrix operator*=(const Matrix& A, const Matrix& B);
    };
} // namespace math