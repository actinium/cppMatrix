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
  SECTION("Construct an empty matrix"){
    matrix<int> m_init_empty = {{}};
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

TEST_CASE( "Test identity construction", "[matrix][constructors]" ) {
  SECTION("Construct an empty matrix"){
    matrix<int> m = matrix<int>::identity(0);
    REQUIRE( m.rows() == 0 );
    REQUIRE( m.columns() == 0 );
  }
  SECTION("Construct a 3x3 identity matrix"){
    matrix<int> m = matrix<int>::identity(3);
    REQUIRE( m.rows() == 3 );
    REQUIRE( m.columns() == 3 );
    REQUIRE( m.at(0,0) == 1 );
    REQUIRE( m.at(0,1) == 0 );
    REQUIRE( m.at(0,2) == 0 );
    REQUIRE( m.at(1,0) == 0 );
    REQUIRE( m.at(1,1) == 1 );
    REQUIRE( m.at(1,2) == 0 );
    REQUIRE( m.at(2,0) == 0 );
    REQUIRE( m.at(2,1) == 0 );
    REQUIRE( m.at(2,2) == 1 );
  }
}

TEST_CASE( "Test copy constructor", "[matrix][constructors]" ) {
  SECTION("Copy construct an empty matrix"){
    matrix<int> m_init_empty = {};
    matrix<int> m2 = m_init_empty;
    REQUIRE( m2.rows() == 0 );
    REQUIRE( m2.columns() == 0 );
  }
  SECTION("Copy construct a 2x3 matrix with values"){
    matrix<int> m_init = {{1,2,3},{4,5,6}};
    matrix<int> m2 = m_init;
    REQUIRE( m2.rows() == 2 );
    REQUIRE( m2.columns() == 3 );
    REQUIRE( m2.at(0,0) == 1 );
    REQUIRE( m2.at(0,1) == 2 );
    REQUIRE( m2.at(0,2) == 3 );
    REQUIRE( m2.at(1,0) == 4 );
    REQUIRE( m2.at(1,1) == 5 );
    REQUIRE( m2.at(1,2) == 6 );
  }
  SECTION("Copy construct a 2x3 matrix with values from const"){
    const matrix<int> m_init = {{1,2,3},{4,5,6}};
    matrix<int> m2 = m_init;
    REQUIRE( m2.rows() == 2 );
    REQUIRE( m2.columns() == 3 );
    REQUIRE( m2.at(0,0) == 1 );
    REQUIRE( m2.at(0,1) == 2 );
    REQUIRE( m2.at(0,2) == 3 );
    REQUIRE( m2.at(1,0) == 4 );
    REQUIRE( m2.at(1,1) == 5 );
    REQUIRE( m2.at(1,2) == 6 );
  }
}

TEST_CASE( "Test move constructor", "[matrix][constructors]" ) {
  SECTION("Move construct an empty matrix"){
    matrix<int> m_init_empty = {};
    matrix<int> m2 = std::move(m_init_empty);
    REQUIRE( m2.rows() == 0 );
    REQUIRE( m2.columns() == 0 );
  }
  SECTION("Move construct a 2x3 matrix with values"){
    matrix<int> m_init = {{1,2,3},{4,5,6}};
    matrix<int> m2 = std::move(m_init);
    REQUIRE( m2.rows() == 2 );
    REQUIRE( m2.columns() == 3 );
    REQUIRE( m2.at(0,0) == 1 );
    REQUIRE( m2.at(0,1) == 2 );
    REQUIRE( m2.at(0,2) == 3 );
    REQUIRE( m2.at(1,0) == 4 );
    REQUIRE( m2.at(1,1) == 5 );
    REQUIRE( m2.at(1,2) == 6 );
  }
}
