#pragma once

#include <vector>

using Matrix = std::vector<std::vector<double>>;    // MATRIX OBJECT

Matrix createMatrix(int rows, int cols);                        // THIS FUNCTION CREATES A MATRIX OBJECT AND THROWS AN ERROR UPON INVALID DIMENSIONS
Matrix addMatrices(const Matrix& m1, const Matrix& m2);         // THIS FUNCTION ADDS MATRICES AND RETURNS THE SUM OR THROWS AN ERROR UPON INVALID DIMENSIONS
Matrix subtractMatrices(const Matrix& m1, const Matrix& m2);    // THIS FUNCTION SUBTRACTS MATRICES AND RETURNS THE DIFFERENCE OR THROWS AN ERROR UPON INVALID DIMENSIONS
Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2);    // THIS FUNCTION MULTIPLIES MATRICES AND RETURNS THE PRODUCT OR THROWS AN ERROR UPON INVALID DIMENSIONS
