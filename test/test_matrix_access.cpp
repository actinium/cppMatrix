#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix access out of range", "[matrix][access]" ) {
  SECTION("Try accessing an empty matrix"){
    mat::matrix<int> m = {};
    REQUIRE_THROWS_AS( m.at(0,0), std::out_of_range );
  }
  SECTION("Try access out of range column"){
    mat::matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(1,3), std::out_of_range );
  }
  SECTION("Try access out of range row"){
    mat::matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(2,2), std::out_of_range );
  }
}

TEST_CASE( "Test changing elements", "[matrix][access]" ) {
  SECTION("Test changing an element in a 1x1 matrix using at()"){
    mat::matrix<int> m(1,1);
    REQUIRE( m.at(0,0) == 0 );
    m.at(0,0) = 1;
    REQUIRE( m.at(0,0) == 1 );
  }
  SECTION("Test changing an element in a 1x1 matrix using square brackets"){
    mat::matrix<int> m(1,1);
    REQUIRE( m.at(0,0) == 0 );
    m[0][0] = 1;
    REQUIRE( m.at(0,0) == 1 );
  }
  SECTION("Test changing an element using another element"){
    mat::matrix<int> m = {{1,2},{3,4}};
    m[0][1] = m[1][0];
    REQUIRE( m.at(0,0) == 1 );
    REQUIRE( m.at(0,1) == 3 );
    REQUIRE( m.at(1,0) == 3 );
    REQUIRE( m.at(1,1) == 4 );
  }
  SECTION("Test changing an element using the same element"){
    mat::matrix<int> m = {{1,2},{3,4}};
    m[0][1] = m[0][1] + 4;
    REQUIRE( m.at(0,0) == 1 );
    REQUIRE( m.at(0,1) == 6 );
    REQUIRE( m.at(1,0) == 3 );
    REQUIRE( m.at(1,1) == 4 );
  }
}

TEST_CASE( "Test changing elements out of range", "[matrix][access]" ) {
  SECTION("Try changing a value in an empty matrix"){
    mat::matrix<int> m = {};
    REQUIRE_THROWS_AS( m.at(0,0) = 1, std::out_of_range );
  }
  SECTION("Try changing a value in an out of range column"){
    mat::matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(1,3) = 1, std::out_of_range );
  }
  SECTION("Try changing a value in an out of range row"){
    mat::matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(2,2) = 1, std::out_of_range );
  }
}

TEST_CASE( "Test boolean values", "[matrix][access]" ) {
  SECTION("Test at and [] in 2x2 matrix"){
    mat::matrix<bool> m = {{true,false},
                           {false,true}};
    REQUIRE( m[0][0] == true);
    REQUIRE( m[0][1] == false);
    REQUIRE( m[1][0] == false);
    REQUIRE( m[1][1] == true);
    REQUIRE( m.at(0,0) == m[0][0]);
    REQUIRE( m.at(0,1) == m[0][1]);
    REQUIRE( m.at(1,0) == m[1][0]);
    REQUIRE( m.at(1,1) == m[1][1]);
  }
}
