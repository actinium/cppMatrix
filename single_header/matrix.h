#ifndef ACTINIUM_MAT_MATRIX_H
#define ACTINIUM_MAT_MATRIX_H

//==============================================================================
//
// matrix.h
//
//==============================================================================

#include <vector>
#include <stdexcept>

namespace mat{

template<class T>
class matrix{
  class matrix_row;
  //----------------------------------------------------------------------------
  // Types
  //----------------------------------------------------------------------------
 public:
  using value_type      = typename std::vector<T>::value_type;
  using size_type       = typename std::vector<T>::size_type;
  using difference_type = typename std::vector<T>::difference_type;
  using reference       = typename std::vector<T>::reference;
  using const_reference = typename std::vector<T>::const_reference;

  //----------------------------------------------------------------------------
  // Constructors and assignments
  //----------------------------------------------------------------------------
 public:
  matrix();
  matrix( std::size_t, std::size_t );
  matrix( std::initializer_list<std::initializer_list<T>> );
  static matrix identity(std::size_t);
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
  T& at( std::size_t, std::size_t );
  const T& at( std::size_t, std::size_t ) const;
  matrix_row operator[]( std::size_t );
  const matrix_row operator[]( std::size_t ) const;

  //----------------------------------------------------------------------------
  // Iterators
  //----------------------------------------------------------------------------
 public:
  /*
  matrix_row begin();
  matrix_row end();
  const matrix_row begin() const;
  const matrix_row end() const;
  const matrix_row cbegin() const;
  const matrix_row cend() const;
  */

  //----------------------------------------------------------------------------
  // Size
  //----------------------------------------------------------------------------
 public:
  std::size_t rows() const { return rows_;}
  std::size_t columns() const {return cols_;}

  //----------------------------------------------------------------------------
  // Modifiers
  //----------------------------------------------------------------------------
 public:
  void resize( std::size_t, std::size_t );
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
   private:
    matrix<T>* matrix_;
    std::size_t row_;
  };

  //----------------------------------------------------------------------------
  // Helper functions
  //----------------------------------------------------------------------------
 private:
  std::vector<T> make_vector(std::initializer_list<std::initializer_list<T>>);
  std::size_t rc2i(std::size_t row,std::size_t col);

  //----------------------------------------------------------------------------
  // Member Variables
  //----------------------------------------------------------------------------
 private:
  std::vector<T> data_;
  std::size_t rows_;
  std::size_t cols_;
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
// matrix_constructors_impl.h
//
//==============================================================================

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
matrix<T>::matrix( std::size_t rows, std::size_t cols ):
    data_(rows*cols),
    rows_(rows),
    cols_(cols) {}

template<class T>
matrix<T>::matrix( std::initializer_list<std::initializer_list<T>> init_list):
    data_( make_vector(init_list) ),
    rows_(init_list.size()),
    cols_( (init_list.size() > 0) ? init_list.begin()->size() : 0 ) {
  if(rows() == 0 || columns() == 0){
    rows_ = 0;
    cols_ = 0;
  }
}

template<class T>
matrix<T> matrix<T>::identity(std::size_t size){
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
matrix<T>::matrix_row::matrix_row( matrix<T>* mp, std::size_t row):
    matrix_(mp), row_(row){}

}

//==============================================================================
//
// matrix_assignment_impl.h
//
//==============================================================================

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
// matrix_access_impl.h
//
//==============================================================================

//------------------------------------------------------------------------------
// Element Access
//------------------------------------------------------------------------------

namespace mat{

template<class T>
T& matrix<T>::at( std::size_t row, std::size_t col ){
  if(row >= rows()){
    throw std::out_of_range("row >= this->rows()!");
  }
  if(col >= columns()){
    throw std::out_of_range("col >= this->columns()!");
  }
  return data_.at(rc2i(row,col));
}

template<class T>
const T& matrix<T>::at( std::size_t row, std::size_t col ) const{
  if(row >= rows()){
    throw std::out_of_range("row >= this->rows()!");
  }
  if(col >= columns()){
    throw std::out_of_range("col >= this->columns()!");
  }
  return data_.at(rc2i(row,col));
}

template<class T>
typename matrix<T>::matrix_row matrix<T>::operator[]( std::size_t row ){
  return matrix_row(this,row);
}

template<class T>
const typename matrix<T>::matrix_row matrix<T>::operator[](
    std::size_t row ) const{
  return matrix_row(const_cast<matrix<T>*>(this),row);
}

}

//------------------------------------------------------------------------------
// Row class element Access
//------------------------------------------------------------------------------

namespace mat{

template<class T>
T& matrix<T>::matrix_row::operator[](std::size_t col){
  return matrix_->data_[matrix_->rc2i(row_,col)];
}

template<class T>
const T& matrix<T>::matrix_row::operator[](std::size_t col) const{
  return matrix_->data_[matrix_->rc2i(row_,col)];
}

}

//==============================================================================
//
// matrix_math_impl.h
//
//==============================================================================

//------------------------------------------------------------------------------
// Math
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Unary minus
//------------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T> operator-( const matrix<T>& m1 ){
  matrix<T> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
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
  if(m1.rows() != m2.rows() || m1.columns() != m2.columns()){
    throw dimension_error(
        "Matrix addition requires same dimensions for both matrices!");
  }
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] + m2[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator+( const C& constant, const matrix<T>& m )
  -> matrix<decltype(constant+m[0][0])>{
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
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
  if(m1.rows() != m2.rows() || m1.columns() != m2.columns()){
    throw dimension_error(
        "Matrix subtraction requires same dimensions for both matrices!");
  }
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] - m2[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator-( const C& constant, const matrix<T>& m )
  -> matrix<decltype(constant-m[0][0])>{
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = constant - m[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator-( const matrix<T>& m, const C& constant)
  -> matrix<decltype(constant-m[0][0])>{
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
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
// matrix_modifiers_impl.h
//
//==============================================================================

//------------------------------------------------------------------------------
// Modifiers
//------------------------------------------------------------------------------

namespace mat{

template<class T>
void matrix<T>::resize( std::size_t rows, std::size_t cols ){
  std::size_t old_rows = this->rows();
  std::size_t old_cols = this->columns();
  std::vector<T> new_data( rows * cols );
  for(std::size_t r=0; r < old_rows; ++r){
    for(std::size_t c=0; c < old_cols; ++c){
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
// matrix_iterators_impl.h
//
//==============================================================================

//------------------------------------------------------------------------------
// Iterators
//------------------------------------------------------------------------------

namespace mat{

}

//==============================================================================
//
// matrix_comparison_impl.h
//
//==============================================================================

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
// matrix_helper_functions_impl.h
//
//==============================================================================

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

template<class T>
std::size_t matrix<T>::rc2i(std::size_t row,std::size_t col){
  return row*cols_+col;
}

}

#endif
