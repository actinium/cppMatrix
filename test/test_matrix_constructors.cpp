#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test default constructor", "[matrix][constructors]" ) {
  matrix<int> m0;
  REQUIRE( m0.rows() == 0 );
  REQUIRE( m0.columns() == 0 );
}

TEST_CASE( "Test size constructor", "[matrix][constructors]" ) {
  SECTION("Construct an empty matrix"){
    matrix<int> m0_0(0,0);
    REQUIRE( m0_0.rows() == 0 );
    REQUIRE( m0_0.columns() == 0 );
  }
  SECTION("Construct a 3x4 matrix"){
    matrix<int> m3_4(3,4);
    REQUIRE( m3_4.rows() == 3 );
    REQUIRE( m3_4.columns() == 4 );
    for(int r=0; r < m3_4.rows(); ++r){
      for(int c=0; c < m3_4.columns(); ++c){
        REQUIRE( m3_4.at(r,c) == 0 );
      }
    }
  }
}

TEST_CASE( "Test initializer list constructor", "[matrix][constructors]" ) {
  SECTION("Construct an empty matrix"){
    matrix<int> m_init_empty = {};
    REQUIRE( m_init_empty.rows() == 0 );
    REQUIRE( m_init_empty.columns() == 0 );
  }
  SECTION("Construct a 2x3 matrix with values"){
    matrix<int> m_init = {{1,2,3},{4,5,6}};
    REQUIRE( m_init.rows() == 2 );
    REQUIRE( m_init.columns() == 3 );
    REQUIRE( m_init.at(0,0) == 1 );
    REQUIRE( m_init.at(0,1) == 2 );
    REQUIRE( m_init.at(0,2) == 3 );
    REQUIRE( m_init.at(1,0) == 4 );
    REQUIRE( m_init.at(1,1) == 5 );
    REQUIRE( m_init.at(1,2) == 6 );
  }
}
