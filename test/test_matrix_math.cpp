#include "catch.hpp"
#include "matrix.h"

//-----------------------------------------------------------------------------
// Unary Minus
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix unary minus", "[matrix][math]" ) {
  SECTION("Add two empty matrices"){
    mat::matrix<int> m1 = {};
    mat::matrix<int> mr = {};
    REQUIRE( mr == -m1 );
  }
  SECTION("Add two 2x2 matrices"){
    mat::matrix<int> m1 = {{1,-1},{0,8}};
    mat::matrix<int> mr = {{-1,1},{0,-8  }};
    REQUIRE( mr == -m1 );
  }
}

//-----------------------------------------------------------------------------
// Addition
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix addition", "[matrix][math]" ) {
  SECTION("Add two empty matrices"){
    mat::matrix<int> m1 = {};
    mat::matrix<int> m2 = {};
    mat::matrix<int> mr = {};
    REQUIRE( mr == m1 + m2 );
  }
  SECTION("Add two 2x2 matrices"){
    mat::matrix<int> m1 = {{1,1},{0,8}};
    mat::matrix<int> m2 = {{2,0},{5,-1}};
    mat::matrix<int> mr = {{3,1},{5,7}};
    REQUIRE( mr == m1 + m2 );
  }
  SECTION("Try adding two matrices of different dimensions"){
    mat::matrix<int> m1 = {{1,1},{0,8}};
    mat::matrix<int> m2 = {{2,0},{5,1},{1,2}};
    REQUIRE_THROWS_AS( m1 + m2, mat::dimension_error );
  }
}

//-----------------------------------------------------------------------------
// Scalar Addition
//-----------------------------------------------------------------------------
TEST_CASE( "Test scalar matrix addition", "[matrix][math]" ) {
  SECTION("Add a constant to a 2x3 matrix"){
    mat::matrix<int> m  = {{1,2,3},{0,-1,-2}};
    mat::matrix<int> mr = {{3,4,5},{2, 1, 0}};
    REQUIRE( mr == 2 + m );
  }
  SECTION("Add a constant to a 2x3 matrix"){
    mat::matrix<int> m  = {{1,2,3},{0,-1,-2}};
    mat::matrix<int> mr = {{3,4,5},{2, 1, 0}};
    REQUIRE( mr == m + 2 );
  }
}

//-----------------------------------------------------------------------------
// Subtraction
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix subtraction", "[matrix][math]" ) {
  SECTION("Subtract two empty matrices"){
    mat::matrix<int> m1 = {};
    mat::matrix<int> m2 = {};
    mat::matrix<int> mr = {};
    REQUIRE( mr == m1 - m2 );
  }
  SECTION("Subtract two 2x3 matrices"){
    mat::matrix<int> m1 = {{2,2, 0},{-2, 3,-4}};
    mat::matrix<int> m2 = {{1,0, 3},{ 3,-2,-2}};
    mat::matrix<int> mr = {{1,2,-3},{-5, 5,-2}};
    REQUIRE( mr == m1 - m2 );
  }
  SECTION("Try subtracting two matrices of different dimensions"){
    mat::matrix<int> m1 = {{1,1},{0,8}};
    mat::matrix<int> m2 = {{2,0},{5,1},{1,2}};
    REQUIRE_THROWS_AS( m1 - m2, mat::dimension_error );
  }
}

//-----------------------------------------------------------------------------
// Scalar Subtraction
//-----------------------------------------------------------------------------
TEST_CASE( "Test scalar matrix subtraction", "[matrix][math]" ) {
  SECTION("Subtract a constant to a 2x3 matrix"){
    mat::matrix<int> m  = {{1,2, 3},{0,-1,-2}};
    mat::matrix<int> mr = {{1,0,-1},{2, 3, 4}};
    REQUIRE( mr == 2 - m );
  }
  SECTION("Subtract a constant to a 2x3 matrix"){
    mat::matrix<int> m  = {{ 1,2,3},{ 0,-1,-2}};
    mat::matrix<int> mr = {{-1,0,1},{-2,-3,-4}};
    REQUIRE( mr == m - 2 );
  }
}

//-----------------------------------------------------------------------------
// Multiplication
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix multiplication", "[matrix][math]" ) {
  SECTION("Multiply two empty matrices"){
    mat::matrix<int> m1 = {};
    mat::matrix<int> m2 = {};
    mat::matrix<int> mr = {};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Multiply two matrices"){
    mat::matrix<int> m1 = {{1,2,3},{4,5,6}};
    mat::matrix<int> m2 = {{7,8},{9,10},{11,12}};
    mat::matrix<int> mr = {{58,64},{139,154}};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Multiply two matrices"){
    mat::matrix<int> m1 = {{3,4,2}};
    mat::matrix<int> m2 = {{13, 9, 7,15},
                      { 8, 7, 4, 6},
                      { 6, 4, 0, 3}};
    mat::matrix<int> mr = {{83,63,37,75}};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Multiply two matrices"){
    mat::matrix<int> m1 = {{3,4,2}};
    mat::matrix<int> m2 = {{1},
                      {8},
                      {6}};
    mat::matrix<int> mr = {{47}};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Try multiplying two matrices of wrong dimensions"){
    mat::matrix<int> m1 = {{1,1},{0,8}};
    mat::matrix<int> m2 = {{2,0},{5,1},{1,2}};
    REQUIRE_THROWS_AS( m1 * m2, mat::dimension_error );
  }
  SECTION("Try multiplying two matrices of wrong dimensions"){
    mat::matrix<int> m1 = {{1,1}};
    mat::matrix<int> m2 = {};
    REQUIRE_THROWS_AS( m1 * m2, mat::dimension_error );
  }
}

//-----------------------------------------------------------------------------
// Scalar Multiplication
//-----------------------------------------------------------------------------
TEST_CASE( "Test scalar matrix multiplication", "[matrix][math]" ) {
  SECTION("Multiply a 2x3 matrix by a constant"){
    mat::matrix<int> m  = {{2,2,0},{-2, 3,-4}};
    mat::matrix<int> mr = {{4,4,0},{-4, 6,-8}};
    REQUIRE( mr == 2 * m );
  }
  SECTION("Multiply a 2x3 matrix by a constant"){
    mat::matrix<int> m  = {{2,2,0},{-2, 3,-4}};
    mat::matrix<int> mr = {{4,4,0},{-4, 6,-8}};
    REQUIRE( mr == m * 2 );
  }
}
//-----------------------------------------------------------------------------
// Transpose
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix transposing", "[matrix][math]" ) {
  SECTION("Transpose an empty matrix"){
    mat::matrix<int> m;
    mat::matrix<int> mt;
    REQUIRE( m.transpose() == mt );
  }
  SECTION("Transpose a 5x5 identity matrix"){
    mat::matrix<int> m = mat::matrix<int>::identity(5);
    REQUIRE( m.transpose() == m );
  }
  SECTION("Transpose a 1x3 matrix"){
    mat::matrix<int> m  = {{1,2,3}};
    mat::matrix<int> mt = {{1},
                      {2},
                      {3}};
    REQUIRE( m.transpose() == mt );
  }
  SECTION("Transpose a 2x2 matrix"){
    mat::matrix<int> m  = {{1,2},
                      {3,4}};
    mat::matrix<int> mt = {{1,3},
                      {2,4}};
    REQUIRE( m.transpose() == mt );
  }
  SECTION("Transpose a 2x3 matrix"){
    mat::matrix<int> m  = {{1,2,3},
                      {4,5,6}};
    mat::matrix<int> mt = {{1,4},
                      {2,5},
                      {3,6}};
    REQUIRE( m.transpose() == mt );
  }
}
