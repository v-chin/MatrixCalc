#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "matrix.h"

TEST_CASE("Testing createMatrix (VALID 1)", "[createMatrix]") {
    REQUIRE(createMatrix(1,1) == Matrix(1, std::vector<double>(1)));
}

TEST_CASE("Testing createMatrix (INVALID 1)", "[createMatrix]") {
    INFO("Invalid Number of Rows");
    REQUIRE_THROWS_AS(createMatrix(0,1), std::invalid_argument);
}

TEST_CASE("Testing createMatrix (INVALID 2)", "[createMatrix]") {
    INFO("Invalid Number of Columns");
    REQUIRE_THROWS_AS(createMatrix(1,0), std::invalid_argument);
}

TEST_CASE("Testing addMatrices (VALID)", "[addMatrices]") {
    Matrix m1 { { 1, 2, 3 } }, m2 { { 1, 2, 3 } }, sum { { 2, 4, 6 }};
    REQUIRE(addMatrices(m1, m2) == sum);
}

TEST_CASE("Testing addMatrices (INVALID 1)", "[addMatrices]") {
    Matrix m1 { { 1, 2, 3 } }, m2 { { 1, 2 } };
    REQUIRE_THROWS_AS(addMatrices(m1, m2), std::invalid_argument);
}

TEST_CASE("Testing addMatrices (INVALID 2)", "[addMatrices]") {
    Matrix m2 { { 1, 2, 3 } }, m1 { { 1, 2 } };
    REQUIRE_THROWS_AS(addMatrices(m1, m2), std::invalid_argument);
}

TEST_CASE("Testing subtractMatrices (VALID 1)", "[subtractMatrices]") {
    Matrix m1 { { 1, 2, 3 } }, m2 { { 1, 2, 3 } }, difference { { 0, 0, 0 }};
    REQUIRE(subtractMatrices(m1, m2) == difference);
}

TEST_CASE("Testing subtractMatrices (VALID 2)", "[subtractMatrices]") {
    Matrix m1 { { -1, -2, -3 } }, m2 { { 1, 2, 3 } }, difference { { -2, -4, -6 }};
    REQUIRE(subtractMatrices(m1, m2) == difference);
}

TEST_CASE("Testing subtractMatrices (INVALID)", "[subtractMatrices]") {
    Matrix m1 { { 1, 2, 3 } }, m2 { { 1, 2 } };
    REQUIRE_THROWS_AS(subtractMatrices(m1, m2), std::invalid_argument);
}

TEST_CASE("Testing multiplyMatrices (VALID)", "[multiplyMatrices]") {
    Matrix m1 { { 1, 2, 3 } }, m2 { { 1 }, { 2 }, { 3 } }, product { { 14 } };
    REQUIRE(multiplyMatrices(m1, m2) == product);
}

TEST_CASE("Testing multiplyMatrices (INVALID 1)", "[multiplyMatrices]") {
    INFO("Mismatching Dimensions");
    Matrix m1 { { 1, 2, 3 } }, m2 { { 1, 2, 3 } };
    REQUIRE_THROWS_AS(multiplyMatrices(m1, m2), std::invalid_argument);
}

TEST_CASE("Testing multiplyMatrices (INVALID 2)", "[multiplyMatrices]") {
    INFO("Multiplying Empty Matrix");
    Matrix m1 { { 1, 2, 3 } }, m2 { {} };
    REQUIRE_THROWS_AS(multiplyMatrices(m1, m2), std::invalid_argument);
}
