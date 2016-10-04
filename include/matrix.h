#ifndef ACTINIUM_MATRIX_H
#define ACTINIUM_MATRIX_H

#include <vector>
#include <stdexcept>

template<class T>
class matrix{
  class matrix_row;
  //---------------------------------------------------------------------------
  // Types
  //---------------------------------------------------------------------------
 public:
  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
  //---------------------------------------------------------------------------
  // Constructors and assignments
  //---------------------------------------------------------------------------
 public:
  matrix();
  matrix( std::size_t, std::size_t );
  matrix( std::initializer_list<std::initializer_list<T>> );
  matrix( const matrix& ) = default;
  matrix( matrix&& ) = default;

  matrix& operator=( std::initializer_list<std::initializer_list<T>> );
  matrix& operator=( const matrix& ) = default;
  matrix& operator=( matrix&& ) = default;

  ~matrix() = default;

  //---------------------------------------------------------------------------
  // Element Access
  //---------------------------------------------------------------------------
 public:
  T& at( std::size_t, std::size_t );
  const T& at( std::size_t, std::size_t ) const;
  matrix_row operator[]( std::size_t );
  const matrix_row operator[]( std::size_t ) const;

  //---------------------------------------------------------------------------
  // Iterators
  //---------------------------------------------------------------------------
 public:
  /*
  matrix_row begin();
  matrix_row end();
  const matrix_row begin() const;
  const matrix_row end() const;
  const matrix_row cbegin() const;
  const matrix_row cend() const;
  */

  //---------------------------------------------------------------------------
  // Size
  //---------------------------------------------------------------------------
 public:
  std::size_t rows() const { return rows_;}
  std::size_t columns() const {return cols_;}

  //---------------------------------------------------------------------------
  // Modifiers
  //---------------------------------------------------------------------------
 public:
  void resize( std::size_t, std::size_t );
  void swap( matrix& );
  friend void swap( matrix& m1, matrix& m2){
    using std::swap;
    // swap m1 and m2
  }
  //---------------------------------------------------------------------------
  // Comparison
  //---------------------------------------------------------------------------
 public:
  bool operator==( const matrix<T>& other ) const;
  bool operator!=( const matrix<T>& other ) const;

  //---------------------------------------------------------------------------
  // Row Class
  //---------------------------------------------------------------------------
 private:
  class matrix_row{
   public:
    // Constructor
    matrix_row(matrix*,std::size_t);
    // Element Access
    T& operator[](std::size_t);
    const T& operator[](std::size_t) const;
    // Iterators
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
    const T* cbegin() const;
    const T* cend() const;
    // Modifiers
   private:
    matrix<T>* matrix_;
    std::size_t row_;
  };
  //---------------------------------------------------------------------------
  // Helper functions
  //---------------------------------------------------------------------------
 private:
  std::vector<T> make_vector(std::initializer_list<std::initializer_list<T>>);
  std::size_t rc2i(std::size_t row,std::size_t col);

  //---------------------------------------------------------------------------
  // Member Variables
  //---------------------------------------------------------------------------
 private:
  std::vector<T> data_;
  std::size_t rows_;
  std::size_t cols_;
};

//-----------------------------------------------------------------------------
// Dimension Exception
//-----------------------------------------------------------------------------
class dimension_error: public std::exception {
 public:
  explicit dimension_error( const char* what_arg ):msg_(what_arg) {}
  virtual const char* what() const throw(){
    return msg_.c_str();
  }
 private:
  std::string msg_;
};

#include "matrix_constructors_impl.h"
#include "matrix_assignment_impl.h"
#include "matrix_access_impl.h"
#include "matrix_math_impl.h"
#include "matrix_modifiers_impl.h"
#include "matrix_iterators_impl.h"
#include "matrix_comparison_impl.h"
#include "matrix_helper_functions_impl.h"

#endif
