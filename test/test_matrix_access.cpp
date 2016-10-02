#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix access out of range", "[matrix][access]" ) {
  SECTION("Try accessing an empty matrix"){
    matrix<int> m = {};
    REQUIRE_THROWS_AS( m.at(0,0), std::out_of_range );
  }
  SECTION("Try access out of range column"){
    matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(1,3), std::out_of_range );
  }
  SECTION("Try access out of range row"){
    matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(2,2), std::out_of_range );
  }
}

TEST_CASE( "Test changing elements", "[matrix][access]" ) {
  SECTION("Try changing a value in an empty matrix"){
    matrix<int> m = {};
    REQUIRE_THROWS_AS( m.at(0,0) = 1, std::out_of_range );
  }
  SECTION("Try changing a value in an out of range column"){
    matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(1,3) = 1, std::out_of_range );
  }
  SECTION("Try changing a value in an out of range row"){
    matrix<int> m(2,3);
    REQUIRE_THROWS_AS( m.at(2,2) = 1, std::out_of_range );
  }
}
