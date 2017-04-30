#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix begin and end", "[matrix][iterators]" ) {
  SECTION("Iterate over elements in 3x3 matrix"){
    mat::matrix<int> m = {{11,12,13},
                          {21,22,23},
                          {31,32,33}};
    auto b = m.begin();
    auto e = m.end();
    for(int i=0; b < e; ++b){
      int r = i / m.columns();
      int c = i % m.columns();
      REQUIRE( m[r][c] == *b );
      ++i;
    }
  }
  SECTION("Iterate over elements in 1x3 matrix"){
    mat::matrix<bool> m = {{true,false,false}};
    auto b = m.begin();
    auto e = m.end();
    for(int i=0; b < e; ++b){
      int r = i / m.columns();
      int c = i % m.columns();
      REQUIRE( m[r][c] == *b );
      ++i;
    }
  }
}

TEST_CASE( "Test matrix rbegin and rend", "[matrix][iterators]" ) {
  SECTION("Iterate over elements in 3x3 matrix"){
    mat::matrix<int> m = {{11,12,13},
                          {21,22,23},
                          {31,32,33}};
    auto b = m.rbegin();
    auto e = m.rend();
    for(int i = m.rows() * m.columns() - 1; b < e; ++b){
      int r = i / m.columns();
      int c = i % m.columns();
      REQUIRE( m[r][c] == *b );
      --i;
    }
  }
}

TEST_CASE( "Test empty matrix iterators", "[matrix][iterators]" ) {
  SECTION( "Empty begin and end" ){
    mat::matrix<int> m;
    REQUIRE( m.begin() == m.end() );
  }
  
  SECTION( "Empty const begin and end" ){
    const mat::matrix<int> m;
    REQUIRE( m.begin() == m.end() );
  }
  
  SECTION( "Empty cbegin and cend" ){
    mat::matrix<int> m;
    REQUIRE( m.cbegin() == m.cend() );
  }
  
  SECTION( "Empty rbegin and rend" ){
    mat::matrix<int> m;
    REQUIRE( m.rbegin() == m.rend() );
  }
  
  SECTION( "Empty const rbegin and rend" ){
    const mat::matrix<int> m;
    REQUIRE( m.rbegin() == m.rend() );
  }

  SECTION( "Empty crbegin and crend" ){
    mat::matrix<int> m;
    REQUIRE( m.crbegin() == m.crend() );
  }
}
