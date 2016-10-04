#include "catch.hpp"
#include "matrix.h"

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

TEST_CASE( "Test scalar matrix addition", "[matrix][math]" ) {
  SECTION("Multiply a 2x3 matrix by a constant"){
    matrix<int> m  = {{1,2,3},{0,-1,-2}};
    matrix<int> mr = {{3,4,5},{2, 1, 0}};
    REQUIRE( mr == 2 + m );
  }
  SECTION("Multiply a 2x3 matrix by a constant"){
    matrix<int> m  = {{1,2,3},{0,-1,-2}};
    matrix<int> mr = {{3,4,5},{2, 1, 0}};
    REQUIRE( mr == m + 2 );
  }
}

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

TEST_CASE( "Test scalar matrix subtraction", "[matrix][math]" ) {
  SECTION("Multiply a 2x3 matrix by a constant"){
    matrix<int> m  = {{1,2, 3},{0,-1,-2}};
    matrix<int> mr = {{1,0,-1},{2, 3, 4}};
    REQUIRE( mr == 2 - m );
  }
  SECTION("Multiply a 2x3 matrix by a constant"){
    matrix<int> m  = {{ 1,2,3},{ 0,-1,-2}};
    matrix<int> mr = {{-1,0,1},{-2,-3,-4}};
    REQUIRE( mr == m - 2 );
  }
}

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
