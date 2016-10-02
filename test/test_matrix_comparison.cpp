#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix comparison", "[matrix][comparison]" ) {
  SECTION("Compare empty matrixes"){
    matrix<int> m1 = {};
    matrix<int> m2 = {};
    REQUIRE( m1 == m2 );
  }
  SECTION("Compare 1x1 matrixes"){
    matrix<int> m1 = {{0}};
    matrix<int> m2(1,1);
    REQUIRE( m1 == m2 );
  }
  SECTION("Compare 2x2 matrixes"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,2},{3,4}};
    REQUIRE( m1 == m2 );
  }
  SECTION("Compare different 2x2 matrixes"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,1},{2,2}};
    REQUIRE( m1 != m2 );
  }
  SECTION("Compare 2x2 matrix with 2x3 matrix"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,2,3},{4,5,6}};
    REQUIRE( m1 != m2 );
  }
  SECTION("Compare 3x2 matrix with 2x3 matrix"){
    matrix<int> m1 = {{1,2},{3,4},{5,6}};
    matrix<int> m2 = {{1,2,3},{4,5,6}};
    REQUIRE( m1 != m2 );
  }
}
