#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix resize", "[matrix][modifiers]" ) {
  SECTION("Add column to matrix"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,2,0},{3,4,0}};
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 2);
    m1.resize(2,3);
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 3);
    REQUIRE( m1 == m2 );
  }
  SECTION("Add row to matrix"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,2},{3,4},{0,0}};
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 2);
    m1.resize(3,2);
    REQUIRE( m1.rows() == 3);
    REQUIRE( m1.columns() == 2);
    REQUIRE( m1 == m2 );
  }
  SECTION("Add row and column to matrix"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,2,0},{3,4,0},{0,0,0}};
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 2);
    m1.resize(3,3);
    REQUIRE( m1.rows() == 3);
    REQUIRE( m1.columns() == 3);
    REQUIRE( m1 == m2 );
  }
  SECTION("Remove column from matrix"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1},{3}};
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 2);
    m1.resize(2,1);
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 1);
    REQUIRE( m1 == m2 );
  }
  SECTION("Remove row from matrix"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,2}};
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 2);
    m1.resize(1,2);
    REQUIRE( m1.rows() == 1);
    REQUIRE( m1.columns() == 2);
    REQUIRE( m1 == m2 );
  }
  SECTION("Remove row and column to matrix"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1}};
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 2);
    m1.resize(1,1);
    REQUIRE( m1.rows() == 1);
    REQUIRE( m1.columns() == 1);
    REQUIRE( m1 == m2 );
  }
  SECTION("Add row and remove column to matrix"){
    matrix<int> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    matrix<int> m2 = {{1,2},{4,5},{7,8},{0,0}};
    REQUIRE( m1.rows() == 3);
    REQUIRE( m1.columns() == 3);
    m1.resize(4,2);
    REQUIRE( m1.rows() == 4);
    REQUIRE( m1.columns() == 2);
    REQUIRE( m1 == m2 );
  }
}
