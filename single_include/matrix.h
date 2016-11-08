//==============================================================================
//
//                                cppMatrix
//
//------------------------------------------------------------------------------
//
//               THIS FILE WAS GENERATED BY MERGING MULTIPLE FILES.
//                      PLEASE DON'T EDIT IT DIRECTLY!
//
//==============================================================================
//
// The MIT License (MIT)
// 
// Copyright (c) 2016 Andreas Cederholm
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//==============================================================================
#ifndef ACTINIUM_MAT_MATRIX_H
#define ACTINIUM_MAT_MATRIX_H

//==============================================================================
//
// Included from: matrix.h
//
//==============================================================================

#line 1 "matrix.h"
#include <vector>
#include <stdexcept>

namespace mat{

template<class T>
class matrix{
 public:
  class matrix_row_iterator;
 private:
  class matrix_row;
  friend class matrix_row;
  //----------------------------------------------------------------------------
  // Types
  //----------------------------------------------------------------------------
 public:
  using value_type             = typename std::vector<T>::value_type;
  using size_type              = typename std::vector<T>::size_type;
  using difference_type        = typename std::vector<T>::difference_type;
  using reference              = typename std::vector<T>::reference;
  using const_reference        = typename std::vector<T>::const_reference;
  using iterator               = typename matrix<T>::matrix_row_iterator;
  using const_iterator         = typename matrix<T>::matrix_row_iterator const;
  using reverse_iterator       = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  //----------------------------------------------------------------------------
  // Constructors and assignments
  //----------------------------------------------------------------------------
 public:
  matrix();
  matrix( size_type, size_type );
  matrix( std::initializer_list<std::initializer_list<T>> );
  static matrix identity( size_type );
  matrix( const matrix& ) = default;
  matrix( matrix&& ) = default;

  matrix& operator=( std::initializer_list<std::initializer_list<T>> );
  matrix& operator=( const matrix& ) = default;
  matrix& operator=( matrix&& ) = default;

  ~matrix() = default;

  //----------------------------------------------------------------------------
  // Element Access
  //----------------------------------------------------------------------------
 public:
  T& at( size_type, size_type );
  const T& at( size_type, size_type ) const;
  matrix_row operator[]( size_type );
  const matrix_row operator[]( size_type ) const;

  //----------------------------------------------------------------------------
  // Iterators
  //----------------------------------------------------------------------------
 public:
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  const_iterator cbegin() const;
  const_iterator cend() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  //----------------------------------------------------------------------------
  // Size
  //----------------------------------------------------------------------------
 public:
  size_type rows() const { return rows_;}
  size_type columns() const {return cols_;}

  //----------------------------------------------------------------------------
  // Modifiers
  //----------------------------------------------------------------------------
 public:
  void resize( size_type, size_type );
  void fill( const T& );
  void swap( matrix& );
  friend void swap( matrix& m1, matrix& m2){
    using std::swap;
    // swap m1 and m2
  }

  //----------------------------------------------------------------------------
  // Comparison
  //----------------------------------------------------------------------------
 public:
  bool operator==( const matrix<T>& other ) const;
  bool operator!=( const matrix<T>& other ) const;

  //----------------------------------------------------------------------------
  // Maths
  //----------------------------------------------------------------------------
 public:
  matrix transpose() const;
  template<class DT=T>
  DT determinant() const;
  matrix inverse() const;

  //----------------------------------------------------------------------------
  // Row Class
  //----------------------------------------------------------------------------
 private:
  class matrix_row{
    // Types
   public:
    using iterator               = typename std::vector<T>::iterator;
    using const_iterator         = typename std::vector<T>::const_iterator;
    using reverse_iterator       = typename std::vector<T>::reverse_iterator;
    using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;
    // Constructor
   public:
    matrix_row( matrix*, size_type );
    // Element Access
   public:
    T& operator[]( size_type );
    const T& operator[]( size_type ) const;
    // Iterators
   public:
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
   private:
    matrix<T>* matrix_;
    size_type row_;
  };

  //----------------------------------------------------------------------------
  // Row Iterator Class
  //----------------------------------------------------------------------------
 public:
  class matrix_row_iterator{
    // Constructor
   public:
    matrix_row_iterator( matrix*, size_type );
   private:
    matrix<T>* matrix_;
    size_type row_;
  };

  //----------------------------------------------------------------------------
  // Helper functions
  //----------------------------------------------------------------------------
 private:
  std::vector<T> make_vector(std::initializer_list<std::initializer_list<T>>);
  size_type rc2i( size_type, size_type );

  //----------------------------------------------------------------------------
  // Member Variables
  //----------------------------------------------------------------------------
 private:
  std::vector<T> data_;
  size_type rows_;
  size_type cols_;
};

//------------------------------------------------------------------------------
// Dimension Exception
//------------------------------------------------------------------------------
class dimension_error: public std::exception {
 public:
  explicit dimension_error( const char* what_arg ):msg_(what_arg) {}
  virtual const char* what() const throw(){
    return msg_.c_str();
  }
 private:
  std::string msg_;
};

}

//==============================================================================
//
// Included from: matrix_constructors_impl.h
//
//==============================================================================

#line 1 "matrix_constructors_impl.h"
//------------------------------------------------------------------------------
// Constructors
//------------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T>::matrix():
    data_(),
    rows_(0),
    cols_(0) {}

template<class T>
matrix<T>::matrix( size_type rows, size_type cols ):
    data_(rows*cols),
    rows_(rows),
    cols_(cols) {}

template<class T>
matrix<T>::matrix( std::initializer_list<std::initializer_list<T>> init_list ):
    data_( make_vector(init_list) ),
    rows_(init_list.size()),
    cols_( (init_list.size() > 0) ? init_list.begin()->size() : 0 ) {
  if(rows() == 0 || columns() == 0){
    rows_ = 0;
    cols_ = 0;
  }
}

template<class T>
matrix<T> matrix<T>::identity( size_type size ){
  matrix<T> ret(size,size);
  for(int i=0; i<size; ++i){
    ret[i][i] = 1;
  }
  return ret;
}

}

//------------------------------------------------------------------------------
// Row Class Constructor
//------------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T>::matrix_row::matrix_row( matrix<T>* mp, size_type row ):
    matrix_(mp), row_(row){}

}

//==============================================================================
//
// Included from: matrix_assignment_impl.h
//
//==============================================================================

#line 1 "matrix_assignment_impl.h"
//------------------------------------------------------------------------------
// Assignments
//------------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T>& matrix<T>::operator=(
    std::initializer_list<std::initializer_list<T>> init_list){
  data_ = make_vector(init_list);
  rows_ = init_list.size();
  cols_ = (init_list.size() > 0) ? init_list.begin()->size() : 0;
  return this;
}

}

//==============================================================================
//
// Included from: matrix_access_impl.h
//
//==============================================================================

#line 1 "matrix_access_impl.h"
//------------------------------------------------------------------------------
// Element Access
//------------------------------------------------------------------------------

namespace mat{

template<class T>
T& matrix<T>::at( size_type row, size_type col ){
  if(row >= rows()){
    throw std::out_of_range("row >= this->rows()!");
  }
  if(col >= columns()){
    throw std::out_of_range("col >= this->columns()!");
  }
  return data_.at(rc2i(row,col));
}

template<class T>
const T& matrix<T>::at( size_type row, size_type col ) const{
  if(row >= rows()){
    throw std::out_of_range("row >= this->rows()!");
  }
  if(col >= columns()){
    throw std::out_of_range("col >= this->columns()!");
  }
  return data_.at(rc2i(row,col));
}

template<class T>
typename matrix<T>::matrix_row matrix<T>::operator[]( size_type row ){
  return matrix_row(this,row);
}

template<class T>
const typename matrix<T>::matrix_row matrix<T>::operator[](
    size_type row ) const{
  return matrix_row(const_cast<matrix<T>*>(this),row);
}

}

//------------------------------------------------------------------------------
// Row class element Access
//------------------------------------------------------------------------------

namespace mat{

template<class T>
T& matrix<T>::matrix_row::operator[]( size_type col ){
  return matrix_->data_[matrix_->rc2i(row_,col)];
}

template<class T>
const T& matrix<T>::matrix_row::operator[]( size_type col ) const{
  return matrix_->data_[matrix_->rc2i(row_,col)];
}

}

//==============================================================================
//
// Included from: matrix_math_impl.h
//
//==============================================================================

#line 1 "matrix_math_impl.h"
//------------------------------------------------------------------------------
// Math
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Unary minus
//------------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T> operator-( const matrix<T>& m1 ){
  using size_type = typename matrix<T>::size_type;
  matrix<T> mr(m1.rows(),m1.columns());
  for(size_type r=0; r < mr.rows(); ++r){
    for(size_type c=0; c < mr.columns(); ++c){
      mr[r][c] = -m1[r][c];
    }
  }
  return mr;
}

}

//------------------------------------------------------------------------------
// Addition
//------------------------------------------------------------------------------

namespace mat{

template<class T1, class T2>
auto operator+( const matrix<T1>& m1, const matrix<T2>& m2 )
  -> matrix<decltype(m1[0][0]*m2[0][0])>{
  using size_type = typename matrix<T1>::size_type;
  if(m1.rows() != m2.rows() || m1.columns() != m2.columns()){
    throw dimension_error(
        "Matrix addition requires same dimensions for both matrices!");
  }
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m1.columns());
  for(size_type r=0; r < mr.rows(); ++r){
    for(size_type c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] + m2[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator+( const C& constant, const matrix<T>& m )
  -> matrix<decltype(constant+m[0][0])>{
  using size_type = typename matrix<T>::size_type;
  matrix<T> mr(m.rows(),m.columns());
  for(size_type r=0; r < mr.rows(); ++r){
    for(size_type c=0; c < mr.columns(); ++c){
      mr[r][c] = constant + m[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator+( const matrix<T>& m, const C& constant)
  -> matrix<decltype(constant+m[0][0])>{
  return operator+( constant, m );
}

}

//------------------------------------------------------------------------------
// Subtraction
//------------------------------------------------------------------------------

namespace mat{

template<class T1, class T2>
auto operator-( const matrix<T1>& m1, const matrix<T2>& m2 )
  -> matrix<decltype(m1[0][0]*m2[0][0])>{
  using size_type = typename matrix<T1>::size_type;
  if(m1.rows() != m2.rows() || m1.columns() != m2.columns()){
    throw dimension_error(
        "Matrix subtraction requires same dimensions for both matrices!");
  }
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m1.columns());
  for(size_type r=0; r < mr.rows(); ++r){
    for(size_type c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] - m2[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator-( const C& constant, const matrix<T>& m )
  -> matrix<decltype(constant-m[0][0])>{
  using size_type = typename matrix<T>::size_type;
  matrix<T> mr(m.rows(),m.columns());
  for(size_type r=0; r < mr.rows(); ++r){
    for(size_type c=0; c < mr.columns(); ++c){
      mr[r][c] = constant - m[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator-( const matrix<T>& m, const C& constant)
  -> matrix<decltype(constant-m[0][0])>{
  using size_type = typename matrix<T>::size_type;
  matrix<T> mr(m.rows(),m.columns());
  for(size_type r=0; r < mr.rows(); ++r){
    for(size_type c=0; c < mr.columns(); ++c){
      mr[r][c] = m[r][c] - constant;
    }
  }
  return mr;
}

}

//------------------------------------------------------------------------------
// Multiplication
//------------------------------------------------------------------------------

namespace mat{

template<class T1, class T2>
auto operator*( const matrix<T1>& m1, const matrix<T2>& m2 )
  -> matrix<decltype(m1[0][0]*m2[0][0])>{
  if(m1.columns() != m2.rows() ){
    throw dimension_error(
        "Matrix multiplication requires number of rows and columns to match!");
  }
  std::size_t length = m1.columns();
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m2.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      decltype(m1[0][0]*m2[0][0]) elem{};
      for(std::size_t i=0; i < length; ++i){
        elem += m1[r][i]*m2[i][c];
      }
      mr[r][c] = elem;
    }
  }
  return mr;
}

template<class C,class T>
matrix<T> operator*( const C& constant, const matrix<T>& m ){
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = constant * m[r][c];
    }
  }
  return mr;
}

template<class C,class T>
matrix<T> operator*( const matrix<T>& m, const C& constant){
  return operator*( constant, m );
}

}

//------------------------------------------------------------------------------
// Transpose
//------------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T> matrix<T>::transpose() const {
  matrix<T> mr(columns(),rows());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = (*this)[c][r];
    }
  }
  return mr;
}

}

//------------------------------------------------------------------------------
// Determinant
//------------------------------------------------------------------------------

namespace mat{

template<class T>
template<class DT>
DT matrix<T>::determinant() const{
  if(columns() != rows() ){
    throw dimension_error(
        "Determinant can only be calculated for square matrices!");
  }
  // TODO
  return 0;
}

}
//------------------------------------------------------------------------------
// Inverse
//------------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T> matrix<T>::inverse() const {
  if(columns() != rows() ){
    throw dimension_error(
        "The inverse can only be calculated for square matrices!");
  }
  // TODO
  return *this;
}

}

//==============================================================================
//
// Included from: matrix_modifiers_impl.h
//
//==============================================================================

#line 1 "matrix_modifiers_impl.h"
//------------------------------------------------------------------------------
// Modifiers
//------------------------------------------------------------------------------

namespace mat{

template<class T>
void matrix<T>::resize( size_type rows, size_type cols ){
  size_type old_rows = this->rows();
  size_type old_cols = this->columns();
  std::vector<T> new_data( rows * cols );
  for(size_type r=0; r < old_rows; ++r){
    for(size_type c=0; c < old_cols; ++c){
      if( r < rows && c < cols ){
        new_data[r*cols+c] = data_[r*old_cols+c];
      }
    }
  }
  rows_ = rows;
  cols_ = cols;
  data_ = new_data;
}

}

//==============================================================================
//
// Included from: matrix_iterators_impl.h
//
//==============================================================================

#line 1 "matrix_iterators_impl.h"
//------------------------------------------------------------------------------
// Iterators
//------------------------------------------------------------------------------

namespace mat{
//------------------------------------------------------------------------------
// Iterations over rows of a matrix
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Iterations over elements of a row
//------------------------------------------------------------------------------
// Normal iterators
template<class T>
typename matrix<T>::matrix_row::iterator matrix<T>::matrix_row::begin(){
  return matrix_->data_.begin() + matrix_->rc2i(row_,0);
}

template<class T>
typename matrix<T>::matrix_row::iterator matrix<T>::matrix_row::end(){
  return matrix_->data_.begin() + matrix_->rc2i(row_,matrix_->columns());
}

template<class T>
typename matrix<T>::matrix_row::const_iterator
  matrix<T>::matrix_row::begin() const{
  return matrix_->data_.begin() + matrix_->rc2i(row_,0);
}

template<class T>
typename matrix<T>::matrix_row::const_iterator
  matrix<T>::matrix_row::end() const{
  return matrix_->data_.begin() + matrix_->rc2i(row_,matrix_->columns());
}

template<class T>
typename matrix<T>::matrix_row::const_iterator
  matrix<T>::matrix_row::cbegin() const{
  return matrix_->data_.begin() + matrix_->rc2i(row_,0);
}

template<class T>
typename matrix<T>::matrix_row::const_iterator
  matrix<T>::matrix_row::cend() const{
  return matrix_->data_.begin() + matrix_->rc2i(row_,matrix_->columns());
}

// Reverse iterators
template<class T>
typename matrix<T>::matrix_row::reverse_iterator
  matrix<T>::matrix_row::rbegin(){
  return reverse_iterator(end());
}

template<class T>
typename matrix<T>::matrix_row::reverse_iterator
  matrix<T>::matrix_row::rend(){
  return reverse_iterator(begin());
}

template<class T>
typename matrix<T>::matrix_row::const_reverse_iterator
  matrix<T>::matrix_row::rbegin() const{
  return const_reverse_iterator(end());
}

template<class T>
typename matrix<T>::matrix_row::const_reverse_iterator
  matrix<T>::matrix_row::rend() const{
  return const_reverse_iterator(begin());
}

template<class T>
typename matrix<T>::matrix_row::const_reverse_iterator
  matrix<T>::matrix_row::crbegin() const{
  return const_reverse_iterator(end());
}

template<class T>
typename matrix<T>::matrix_row::const_reverse_iterator
  matrix<T>::matrix_row::crend() const{
  return const_reverse_iterator(begin());
}

}

//==============================================================================
//
// Included from: matrix_comparison_impl.h
//
//==============================================================================

#line 1 "matrix_comparison_impl.h"
//------------------------------------------------------------------------------
// Comparison
//------------------------------------------------------------------------------

namespace mat{

template< class T >
bool matrix<T>::operator==( const matrix<T>& other ) const {
  if( rows() != other.rows() ){
    return false;
  }
  if( columns() != other.columns() ){
    return false;
  }
  return data_ == other.data_;
}

template< class T >
bool matrix<T>::operator!=( const matrix<T>& other ) const {
  return !operator==(other);
}

}

//==============================================================================
//
// Included from: matrix_helper_functions_impl.h
//
//==============================================================================

#line 1 "matrix_helper_functions_impl.h"
//------------------------------------------------------------------------------
// Helper functions
//------------------------------------------------------------------------------

namespace mat{

template<class T>
std::vector<T> matrix<T>::make_vector(
    std::initializer_list<std::initializer_list<T>> init_list){
  std::vector<T> vec;
  for(auto& row: init_list){
    vec.insert(vec.end(),row);
  }
  return vec;
}

/**
 * rc2i - Matrix (r)ow and (c)olumn to Vector (i)ndex conversion
 */
template<class T>
typename matrix<T>::size_type matrix<T>::rc2i( size_type row, size_type col ){
  return row*cols_+col;
}

}

#endif
