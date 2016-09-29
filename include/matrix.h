#ifndef ACTINIUM_MATRIX_H
#define ACTINIUM_MATRIX_H

#include <vector>

template<class T>
class matrix{
  class matrix_row;
  //---------------------------------------------------------------------------
  // Constructors and assignments
  //---------------------------------------------------------------------------
 public:
  matrix();
  matrix( std::size_t, std::size_t );
  matrix( std::initializer_list<std::initializer_list<T>> );
  matrix( const matrix& );
  matrix( matrix&& );

  matrix& operator=( const matrix& );
  matrix& operator=( matrix&& );
  matrix& operator=( std::initializer_list<std::initializer_list<T>> );

  ~matrix(){}

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
  matrix_row begin();
  matrix_row end();
  const matrix_row begin() const;
  const matrix_row end() const;
  const matrix_row cbegin() const;
  const matrix_row cend() const;

  //---------------------------------------------------------------------------
  // Size
  //---------------------------------------------------------------------------
 public:
  std::pair<std::size_t,std::size_t> size();
  std::size_t rows(){ return rows_;}
  std::size_t columns(){return cols_;}

  //---------------------------------------------------------------------------
  // Modifiers
  //---------------------------------------------------------------------------
 public:
  void clear();
  void resize( std::size_t, std::size_t );
  void swap( matrix& );
  friend void swap( matrix& m1, matrix& m2){
    using std::swap;
    // swap m1 and m2
  }
 private:
  std::vector<T> data_;
  std::size_t rows_;
  std::size_t cols_;
 private:
  //---------------------------------------------------------------------------
  // Row Class
  //---------------------------------------------------------------------------
  class matrix_row{
   public:
    // Constructor
    matrix_row(std::size_t);
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
};


#include "matrix_constructors_impl.h"
#include "matrix_assignment_impl.h"
#include "matrix_access_impl.h"
#include "matrix_modifires_impl.h"
#include "matrix_comparison_impl.h"

#endif
