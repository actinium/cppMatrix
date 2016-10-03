#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix resize", "[matrix][modifiers]" ) {
  SECTION("Compare empty matrixes"){
    matrix<int> m1 = {{1,2},{3,4}};
    matrix<int> m2 = {{1,2,0},{3,4,0}};
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 2);
    m1.resize(2,3);
    REQUIRE( m1.rows() == 2);
    REQUIRE( m1.columns() == 3);
    REQUIRE( m1 == m2 );
  }
}
