#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix", "[matrix]" ) {
  matrix<int> m0;
  REQUIRE( m0.rows() == 0 );
  REQUIRE( m0.columns() == 0 );

  matrix<int> m3_4(3,4);
  REQUIRE( m3_4.rows() == 3 );
  REQUIRE( m3_4.columns() == 4 );

  matrix<int> m_init = {{1,2,3},{4,5,6}};
  REQUIRE( m_init.rows() == 2 );
  REQUIRE( m_init.columns() == 3 );
  
  matrix<int> m_init_2 = {};
  REQUIRE( m_init_2.rows() == 0 );
  REQUIRE( m_init_2.columns() == 0 );
}
