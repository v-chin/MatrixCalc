#include <stdexcept>

#include "matrix.h"

Matrix createMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) throw std::invalid_argument("Incompatible Dimensions"); // CHECK: NON-ZERO DIMENSIONS
    return Matrix(rows, std::vector<double>(cols));     // CREATE THE MATRIX OBJECT
} // end createMatrix

Matrix addMatrices(const Matrix& m1, const Matrix& m2) {

    ///////////////////////////// CHECK: EQUAL ROWS AND COLUMNS AND NON-EMPTY MATRIX //////////////////////////////
    if (m1.size() != m2.size() || m1.empty() || m2.empty()) throw std::invalid_argument("Incompatible Dimensions");


    std::size_t numRows { m1.size() }, numCols{ m1[0].size() };     // INITIALIZATION: DIMENSIONS OF MATRICES OF M1 AND M2
    Matrix sum { Matrix(numRows, std::vector<double>(numCols)) };   // INITIALIZATION: MATRIX OF SUM OF M1 AND M2

    /////////// ADD MATRICES BY TRAVERSING EACH MATRIX VIA EACH COLUMN IN A ROW ////////////
    for (std::size_t i { 0 }; i < numRows; i++) {
        if (m2[i].size() != numCols) throw std::invalid_argument("Incompatible Dimensions");    // CHECK: EQUAL ROWS AND COLUMNS
        for (std::size_t j{ 0 }; j < numCols; j++) {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return sum;

} // end addMatrices

Matrix subtractMatrices(const Matrix& m1, const Matrix& m2) {

    ///////////////////////////// CHECK: EQUAL ROWS AND COLUMNS AND NON-EMPTY MATRIX //////////////////////////////
    if (m1.size() != m2.size() || m1.empty() || m2.empty()) throw std::invalid_argument("Incompatible Dimensions");

    std::size_t numRows { m1.size() }, numCols{ m1[0].size() };             // INITIALIZATION: DIMENSIONS OF MATRICES M1 AND M2
    Matrix difference { Matrix(numRows, std::vector<double>(numCols)) };    // INITIALIZATION: MATRIX OF DIFFERENCE OF M1 AND M2

    ///////// SUBTRACT MATRICES BY TRAVERSING EACH MATRIX VIA EACH COLUMN IN A ROW /////////
    for (std::size_t i { 0 }; i < numRows; i++) {
        if (m2[i].size() != numCols) throw std::invalid_argument("Incompatible Dimensions");    // CHECK: EQUAL ROWS AND COLUMNS
        for (std::size_t j{ 0 }; j < numCols; j++) {
            difference[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return difference;

} //end subtractMatrices

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {

    /////////// CHECK: NON-EMPTY MATRICES AND NUMBER OF COLUMNS OF M1 IS EQUAL TO THE NUMBER OF ROWS OF M2 ///////////
    if (m1.empty() || m2.empty() || m1[0].size() != m2.size()) throw std::invalid_argument("Incompatible Dimensions");

    std::size_t m1Rows { m1.size() }, m2Rows { m2.size() }, m1Cols{m1[0].size()}, m2Cols{m2[0].size()}; // INITIALIZATION: DIMENSIONS OF MATRICES M1 AND M2
    Matrix product { Matrix(m1Rows, std::vector<double>(m2Cols)) };                                     // INITIALIZATION: MATRIX OF PRODUCT OF M1 AND M2

    double temp {}; // INITIALIZATION: TEMPORARY ELEMENT TO HELP CALCULATE PRODUCT

    ////////////////////////////////// MULTIPLY MATRICES //////////////////////////////////
    for (std::size_t i{ 0 }; i < m1Rows; i++) {
        if (m1[i].size() != m2Rows) throw std::invalid_argument("Incompatible Dimensions"); // CHECK: M1 COLUMNS EQUALS M2 ROWS
        for (std::size_t j { 0 }; j < m2Cols; j++) {
            temp = 0;
            for (std::size_t k{ 0 }; k < m1Cols; k++) {
                temp += m1[i][k] * m2[k][j];
            }
            product[i][j] = temp;
        }
    }

    return product;

} // end multiplyMatrices
