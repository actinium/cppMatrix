#include "catch.hpp"
#include "matrix.h"

//-----------------------------------------------------------------------------
// Unary Minus
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix unary minus", "[matrix][math]" ) {
  SECTION("Add two empty matrices"){
    matrix<int> m1 = {};
    matrix<int> mr = {};
    REQUIRE( mr == -m1 );
  }
  SECTION("Add two 2x2 matrices"){
    matrix<int> m1 = {{1,-1},{0,8}};
    matrix<int> mr = {{-1,1},{0,-8  }};
    REQUIRE( mr == -m1 );
  }
}

//-----------------------------------------------------------------------------
// Addition
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix addition", "[matrix][math]" ) {
  SECTION("Add two empty matrices"){
    matrix<int> m1 = {};
    matrix<int> m2 = {};
    matrix<int> mr = {};
    REQUIRE( mr == m1 + m2 );
  }
  SECTION("Add two 2x2 matrices"){
    matrix<int> m1 = {{1,1},{0,8}};
    matrix<int> m2 = {{2,0},{5,-1}};
    matrix<int> mr = {{3,1},{5,7}};
    REQUIRE( mr == m1 + m2 );
  }
  SECTION("Try adding two matrices of different dimensions"){
    matrix<int> m1 = {{1,1},{0,8}};
    matrix<int> m2 = {{2,0},{5,1},{1,2}};
    REQUIRE_THROWS_AS( m1 + m2, dimension_error );
  }
}

//-----------------------------------------------------------------------------
// Scalar Addition
//-----------------------------------------------------------------------------
TEST_CASE( "Test scalar matrix addition", "[matrix][math]" ) {
  SECTION("Add a constant to a 2x3 matrix"){
    matrix<int> m  = {{1,2,3},{0,-1,-2}};
    matrix<int> mr = {{3,4,5},{2, 1, 0}};
    REQUIRE( mr == 2 + m );
  }
  SECTION("Add a constant to a 2x3 matrix"){
    matrix<int> m  = {{1,2,3},{0,-1,-2}};
    matrix<int> mr = {{3,4,5},{2, 1, 0}};
    REQUIRE( mr == m + 2 );
  }
}

//-----------------------------------------------------------------------------
// Subtraction
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix subtraction", "[matrix][math]" ) {
  SECTION("Subtract two empty matrices"){
    matrix<int> m1 = {};
    matrix<int> m2 = {};
    matrix<int> mr = {};
    REQUIRE( mr == m1 - m2 );
  }
  SECTION("Subtract two 2x3 matrices"){
    matrix<int> m1 = {{2,2, 0},{-2, 3,-4}};
    matrix<int> m2 = {{1,0, 3},{ 3,-2,-2}};
    matrix<int> mr = {{1,2,-3},{-5, 5,-2}};
    REQUIRE( mr == m1 - m2 );
  }
  SECTION("Try subtracting two matrices of different dimensions"){
    matrix<int> m1 = {{1,1},{0,8}};
    matrix<int> m2 = {{2,0},{5,1},{1,2}};
    REQUIRE_THROWS_AS( m1 - m2, dimension_error );
  }
}

//-----------------------------------------------------------------------------
// Scalar Subtraction
//-----------------------------------------------------------------------------
TEST_CASE( "Test scalar matrix subtraction", "[matrix][math]" ) {
  SECTION("Subtract a constant to a 2x3 matrix"){
    matrix<int> m  = {{1,2, 3},{0,-1,-2}};
    matrix<int> mr = {{1,0,-1},{2, 3, 4}};
    REQUIRE( mr == 2 - m );
  }
  SECTION("Subtract a constant to a 2x3 matrix"){
    matrix<int> m  = {{ 1,2,3},{ 0,-1,-2}};
    matrix<int> mr = {{-1,0,1},{-2,-3,-4}};
    REQUIRE( mr == m - 2 );
  }
}

//-----------------------------------------------------------------------------
// Multiplication
//-----------------------------------------------------------------------------
TEST_CASE( "Test matrix multiplication", "[matrix][math]" ) {
  SECTION("Multiply two empty matrices"){
    matrix<int> m1 = {};
    matrix<int> m2 = {};
    matrix<int> mr = {};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Multiply two matrices"){
    matrix<int> m1 = {{1,2,3},{4,5,6}};
    matrix<int> m2 = {{7,8},{9,10},{11,12}};
    matrix<int> mr = {{58,64},{139,154}};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Multiply two matrices"){
    matrix<int> m1 = {{3,4,2}};
    matrix<int> m2 = {{13, 9, 7,15},
                      { 8, 7, 4, 6},
                      { 6, 4, 0, 3}};
    matrix<int> mr = {{83,63,37,75}};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Multiply two matrices"){
    matrix<int> m1 = {{3,4,2}};
    matrix<int> m2 = {{1},
                      {8},
                      {6}};
    matrix<int> mr = {{47}};
    REQUIRE( mr == m1 * m2 );
  }
  SECTION("Try multiplying two matrices of wrong dimensions"){
    matrix<int> m1 = {{1,1},{0,8}};
    matrix<int> m2 = {{2,0},{5,1},{1,2}};
    REQUIRE_THROWS_AS( m1 * m2, dimension_error );
  }
  SECTION("Try multiplying two matrices of wrong dimensions"){
    matrix<int> m1 = {{1,1}};
    matrix<int> m2 = {};
    REQUIRE_THROWS_AS( m1 * m2, dimension_error );
  }
}

//-----------------------------------------------------------------------------
// Scalar Multiplication
//-----------------------------------------------------------------------------
TEST_CASE( "Test scalar matrix multiplication", "[matrix][math]" ) {
  SECTION("Multiply a 2x3 matrix by a constant"){
    matrix<int> m  = {{2,2,0},{-2, 3,-4}};
    matrix<int> mr = {{4,4,0},{-4, 6,-8}};
    REQUIRE( mr == 2 * m );
  }
  SECTION("Multiply a 2x3 matrix by a constant"){
    matrix<int> m  = {{2,2,0},{-2, 3,-4}};
    matrix<int> mr = {{4,4,0},{-4, 6,-8}};
    REQUIRE( mr == m * 2 );
  }
}
