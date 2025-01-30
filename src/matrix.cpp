#include <stdexcept>

#include "matrix.h"

Matrix createMatrix(int rows, int cols) {
    return Matrix(rows, std::vector<double>(cols));
} // end createMatrix

Matrix addMatrices(const Matrix& m1, const Matrix& m2) {

    if (m1.size() != m2.size() || m1.empty() || m2.empty()) throw std::invalid_argument("Incompatible Dimensions");

    std::size_t numRows { m1.size() }, numCols{ m1[0].size() };
    Matrix sum { Matrix(numRows, std::vector<double>(numCols)) };

    for (std::size_t i { 0 }; i < numRows; i++) {
        if (m2[i].size() != numCols) throw std::invalid_argument("Incompatible Dimensions");
        for (std::size_t j{ 0 }; j < numCols; j++) {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return sum;

}

Matrix subtractMatrices(const Matrix& m1, const Matrix& m2) {

    if (m1.size() != m2.size() || m1.empty() || m2.empty()) throw std::invalid_argument("Incompatible Dimensions");

    std::size_t numRows { m1.size() }, numCols{ m1[0].size() };
    Matrix difference { Matrix(numRows, std::vector<double>(numCols)) };

    for (std::size_t i { 0 }; i < numRows; i++) {
        if (m2[i].size() != numCols) throw std::invalid_argument("Incompatible Dimensions");
        for (std::size_t j{ 0 }; j < numCols; j++) {
            difference[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return difference;
}

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {

    if (m1.empty() || m2.empty() || m1[0].size() != m2.size()) throw std::invalid_argument("Incompatible Dimensions");

    std::size_t m1Rows { m1.size() }, m2Rows { m2.size() }, m1Cols{m1[0].size()}, m2Cols{m2[0].size()};
    Matrix product { Matrix(m1Rows, std::vector<double>(m2Cols)) };

    double temp {};

    for (std::size_t i{ 0 }; i < m1Rows; i++) {
        if (m1[i].size() != m2Rows) throw std::invalid_argument("Incompatible Dimensions");
        for (std::size_t j { 0 }; j < m2Cols; j++) {
            temp = 0;
            for (std::size_t k{ 0 }; k < m1Cols; k++) {
                temp += m1[i][k] * m2[k][j];
            }
            product[i][j] = temp;
        }
    }

    return product;

}
