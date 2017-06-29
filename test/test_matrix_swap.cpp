#include "catch.hpp"
#include "matrix.h"


TEST_CASE( "Test matrix swap free function", "[matrix][swap]" ) {
  SECTION("Swap two empty matrices"){
    mat::matrix<int> m1 = {};
    mat::matrix<int> m2 = {};
    mat::matrix<int> m  = {};
    
    swap( m1, m2 );
    
    REQUIRE( m1 == m );
    REQUIRE( m2 == m );
  }
  SECTION("Swap an empty matrix with a 2x2 matrix"){
    mat::matrix<int> m1  = {};
    mat::matrix<int> m1r = {};
    mat::matrix<int> m2  = {{1,2},{3,4}};
    mat::matrix<int> m2r = {{1,2},{3,4}};
    
    swap( m1, m2 );
    
    REQUIRE( m1 == m2r );
    REQUIRE( m2 == m1r );
  }
  SECTION("Swap a 2x3 matrix with a 3x2 matrix"){
    mat::matrix<int> m1  = {{1,2,3},{4,5,6}};
    mat::matrix<int> m1r = {{1,2,3},{4,5,6}};
    mat::matrix<int> m2  = {{1,2},{3,4},{5,6}};
    mat::matrix<int> m2r = {{1,2},{3,4},{5,6}};
    
    swap( m1, m2 );
    
    REQUIRE( m1 == m2r );
    REQUIRE( m2 == m1r );
  }
}

TEST_CASE( "Test matrix swap member function", "[matrix][swap]" ) {
  SECTION("Swap two empty matrices"){
    mat::matrix<int> m1 = {};
    mat::matrix<int> m2 = {};
    mat::matrix<int> m  = {};
    
    m1.swap( m2 );
    
    REQUIRE( m1 == m );
    REQUIRE( m2 == m );
  }
  SECTION("Swap a 2x2 matrix with an empty matrix"){
    mat::matrix<int> m1  = {{1,2},{3,4}};
    mat::matrix<int> m1r = {{1,2},{3,4}};
    mat::matrix<int> m2  = {};
    mat::matrix<int> m2r = {};
    
    m1.swap( m2 );
    
    REQUIRE( m1 == m2r );
    REQUIRE( m2 == m1r );
  }
  SECTION("Swap a 2x3 matrix with a 3x2 matrix"){
    mat::matrix<int> m1  = {{1,2,3},{4,5,6}};
    mat::matrix<int> m1r = {{1,2,3},{4,5,6}};
    mat::matrix<int> m2  = {{1,2},{3,4},{5,6}};
    mat::matrix<int> m2r = {{1,2},{3,4},{5,6}};
    
    m1.swap( m2 );
    
    REQUIRE( m1 == m2r );
    REQUIRE( m2 == m1r );
  }
}
