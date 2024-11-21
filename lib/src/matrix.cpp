#include <src/matrix.h>
#include <iostream>
#include <cmath>

using namespace math;

real& Matrix::operator()(int row, int col)
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: Номер строки за пределами границ" << std::endl;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Matrix: Номер столбца за пределами границ" << std::endl;
    }

    int pos{0};

    pos = cols_*row + col;
    return this->mvec_.at(pos);
}

real Matrix::operator()(int row, int col) const
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: Номер строки за пределами границ" << std::endl;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Matrix: Номер столбца за пределами границ" << std::endl;
    }

    int pos{0};

    pos = cols_*row + col;
    return this->mvec_.at(pos);
}

void Matrix::print() const
{
    for (int i = 0; i < this->rows_; ++i)
    {
        for (int j = 0; j < this->cols_; ++j)
        {
            std::cout << this->mvec_.at(cols_ * i + j) << " ";
        }
        std::cout << std::endl;
    }
}
namespace math
{
    Matrix operator+(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Матрицы не могут быть сложены!" << std::endl;
            return Matrix(0, 0);
        }
        Matrix M(A.cols_, A.rows_);
        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i);
        }
        return M;
    }

    Matrix operator-(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Матрицы не могут быть вычтены!" << std::endl;
            return Matrix(0, 0);
        }
        Matrix M(A.cols_, A.rows_);
        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i);
        }
        return M;
    }
    Matrix operator*(const Matrix &A, const Matrix &B)
    {
        if (A.cols_ != B.rows_)
        {
            std::cerr << "Матрицы не могут быть перемножены!" << std::endl;
            return Matrix(0, 0);
        }
        Matrix M(A.rows_, B.cols_);
        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            int row = (int)std::floor(i / M.cols_);
            int col = i - row * M.cols_;
            for (int k = 0; k < A.cols_; ++k)
            {
                M.mvec_.at(i) += A(row, k) * B(k, col);
            }
        }
        return M;
    }
}