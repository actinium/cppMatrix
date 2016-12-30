#include "catch.hpp"
#include "matrix.h"

TEST_CASE( "Test matrix_row begin and end", "[matrix][iterators]" ) {
  mat::matrix<int> m = {{11,12,13},
                        {21,22,23},
                        {31,32,33}};
  SECTION("Iterate over first row"){
    auto b = m[0].begin();
    auto e = m[0].end();
    for(int i=0; b < e; ++b){
      REQUIRE( m[0][i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over second row"){
    auto b = m[1].begin();
    auto e = m[1].end();
    for(int i=0; b < e; ++b){
      REQUIRE( m[1][i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over third row"){
    auto b = m[2].begin();
    auto e = m[2].end();
    for(int i=0; b < e; ++b){
      REQUIRE( m[2][i] == *b );
      ++i;
    }
  }
}

TEST_CASE( "Test const matrix_row begin and end", "[matrix][iterators]" ) {
  const mat::matrix<int> m = {{11,12,13},
                             {21,22,23},
                             {31,32,33}};
  SECTION("Iterate over first row"){
    auto b = m[0].begin();
    auto e = m[0].end();
    for(int i=0; b < e; ++b){
      REQUIRE( m[0][i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over second row"){
    auto b = m[1].begin();
    auto e = m[1].end();
    for(int i=0; b < e; ++b){
      REQUIRE( m[1][i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over third row"){
    auto b = m[2].begin();
    auto e = m[2].end();
    for(int i=0; b < e; ++b){
      REQUIRE( m[2][i] == *b );
      ++i;
    }
  }
}

TEST_CASE( "Test matrix_row cbegin and cend", "[matrix][iterators]" ) {
  mat::matrix<int> m = {{11,12,13},
                        {21,22,23},
                        {31,32,33}};
  SECTION("Iterate over first row"){
    auto b = m[0].cbegin();
    auto e = m[0].cend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[0][i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over second row"){
    auto b = m[1].cbegin();
    auto e = m[1].cend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[1][i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over third row"){
    auto b = m[2].cbegin();
    auto e = m[2].cend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[2][i] == *b );
      ++i;
    }
  }
}

TEST_CASE( "Test matrix_row rbegin and rend", "[matrix][iterators]" ) {
  mat::matrix<int> m = {{11,12,13},
                        {21,22,23},
                        {31,32,33}};
  SECTION("Iterate over first row"){
    auto b = m[0].rbegin();
    auto e = m[0].rend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[0][2-i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over second row"){
    auto b = m[1].rbegin();
    auto e = m[1].rend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[1][2-i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over third row"){
    auto b = m[2].rbegin();
    auto e = m[2].rend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[2][2-i] == *b );
      ++i;
    }
  }
}

TEST_CASE( "Test const matrix_row rbegin and rend", "[matrix][iterators]" ) {
  const mat::matrix<int> m = {{11,12,13},
                              {21,22,23},
                              {31,32,33}};
  SECTION("Iterate over first row"){
    auto b = m[0].rbegin();
    auto e = m[0].rend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[0][2-i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over second row"){
    auto b = m[1].rbegin();
    auto e = m[1].rend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[1][2-i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over third row"){
    auto b = m[2].rbegin();
    auto e = m[2].rend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[2][2-i] == *b );
      ++i;
    }
  }
}

TEST_CASE( "Test matrix_row crbegin and crend", "[matrix][iterators]" ) {
  mat::matrix<int> m = {{11,12,13},
                        {21,22,23},
                        {31,32,33}};
  SECTION("Iterate over first row"){
    auto b = m[0].crbegin();
    auto e = m[0].crend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[0][2-i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over second row"){
    auto b = m[1].crbegin();
    auto e = m[1].crend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[1][2-i] == *b );
      ++i;
    }
  }
  SECTION("Iterate over third row"){
    auto b = m[2].crbegin();
    auto e = m[2].crend();
    for(int i=0; b < e; ++b){
      REQUIRE( m[2][2-i] == *b );
      ++i;
    }
  }
}

TEST_CASE( "Test matrix begin and end", "[matrix][iterators]" ) {
  mat::matrix<int> m = {{11,12,13},
                        {21,22,23},
                        {31,32,33}};
  auto b = m.begin();
  auto e = m.end();
  SECTION("Test dereferencing"){
    auto row = *b;
    auto elem = *row.begin();
    REQUIRE( elem == m[0][0] );
  }
  SECTION("Test dereferencing"){
    auto elem = *((*b).begin());
    REQUIRE( elem == m[0][0] );
  }
  SECTION("Test operator[]"){
    REQUIRE( b[0][0] == m[0][0] );
    REQUIRE( b[1][0] == m[1][0] );
    REQUIRE( b[2][1] == m[2][1] );
  }
}

TEST_CASE( "Test matrix begin and end increment and decrement", "[matrix][iterators]" ) {
  mat::matrix<int> m = {{11,12,13},
                        {21,22,23},
                        {31,32,33}};
  auto b = m.begin();
  auto e = m.end();
  SECTION("Test increment"){
    ++b;
    auto row = *b;
    auto elem = *(row.begin());
    REQUIRE( elem == m[1][0] );
  }
  SECTION("Test post increment"){
    b++;
    auto row = *b;
    auto elem = *(row.begin());
    REQUIRE( elem == m[1][0] );
  }
  SECTION("Test post increment in expression"){
    auto row = *b++;
    auto elem = *(row.begin());
    REQUIRE( elem == m[0][0] );
    auto row2 = *b;
    auto elem2 = *(row2.begin());
    REQUIRE( elem2 == m[1][0] );
  }
  SECTION("Test decrement"){
    --e;
    auto row = *e;
    auto elem = *(row.begin());
    REQUIRE( elem == m[2][0] );
  }
  SECTION("Test post decrement"){
    e--;
    auto row = *e;
    auto elem = *(row.begin());
    REQUIRE( elem == m[2][0] );
  }
  SECTION("Test post decrement in expression"){
    e--;
    auto row = *e--;
    auto elem = *(row.begin());
    REQUIRE( elem == m[2][0] );
    auto row2 = *e;
    auto elem2 = *(row2.begin());
    REQUIRE( elem2 == m[1][0] );
  }
}
