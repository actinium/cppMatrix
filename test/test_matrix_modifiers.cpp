#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix resize", "[matrix][modifiers]" ) {
  SECTION("Compare empty matrixes"){
    matrix<int> m = {{1,2},{3,4}};
    REQUIRE( m.rows() == 2);
    REQUIRE( m.columns() == 2);
  }
}
