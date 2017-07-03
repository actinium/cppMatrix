#include "catch.hpp"
#include "matrix.h"

#include <sstream>

TEST_CASE( "Test matrix output", "[matrix][output]" ) {
  SECTION("Output an empty matrix"){
    mat::matrix<int> m = {};
    std::stringstream ss;

    ss << m;
    
    REQUIRE( ss.str() == "[]" );
  }
  SECTION("Output a 2x2 matrix"){
    mat::matrix<int> m = {{12, 34},
                          {56, 78}};
    std::stringstream ss;

    ss << m;
    
    REQUIRE( ss.str() == "[[12,34],[56,78]]" );
  }
  SECTION("Output a 1x3 matrix"){
    mat::matrix<int> m = {{12, 0, 21}};
    std::stringstream ss;

    ss << m;
    
    REQUIRE( ss.str() == "[[12,0,21]]" );
  }
  SECTION("Output a 3x1 matrix"){
    mat::matrix<int> m = {{555},
                          {55 },
                          {5  }};
    std::stringstream ss;

    ss << m;
    
    REQUIRE( ss.str() == "[[555],[55],[5]]" );
  }
  SECTION("Output a 2x2 bool matrix"){
    mat::matrix<bool> m = {{true, false},
                           {false, true}};
    std::stringstream ss;

    ss << m;
    
    REQUIRE( ss.str() == "[[1,0],[0,1]]" );
  }
  SECTION("Output a 2x2 bool matrix with boolalpha"){
    mat::matrix<bool> m = {{true, false},
                           {false, true}};
    std::stringstream ss;

    ss << std::boolalpha;
    ss << m;
    
    REQUIRE( ss.str() == "[[true,false],[false,true]]" );
  }
  SECTION("Output calculation"){
    mat::matrix<int> m1 = {{2, 3}};
    mat::matrix<int> m2 = {{5},{6}};
    std::stringstream ss;

    ss << m1 << " * " << m2;
    ss << " = " << (m1 * m2) << std::endl;

    REQUIRE( ss.str() == "[[2,3]] * [[5],[6]] = [[28]]\n" );
  }
}

