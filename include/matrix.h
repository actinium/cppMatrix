#ifndef ACTINIUM_MATRIX_H
#define ACTINIUM_MATRIX_H

#include <vector>

template<class T>
class matrix{
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
  //reference       operator[]( std::size_t );
  //const_reference operator[]( std::size_t ) const;

  //---------------------------------------------------------------------------
  // Iterators
  //---------------------------------------------------------------------------
 public:

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
};

//-----------------------------------------------------------------------------
// Constructors and assignments
//-----------------------------------------------------------------------------
template<class T>
matrix<T>::matrix():data_(),rows_(0),cols_(0){}
template<class T>
matrix<T>::matrix( std::size_t rows, std::size_t cols ):
    data_(rows*cols),rows_(rows),cols_(cols){}
template<class T>
matrix<T>::matrix( std::initializer_list<std::initializer_list<T>> init_list):
    data_( init_list.size() * init_list.begin()->size() ),
    rows_(init_list.size()),cols_( init_list.begin()->size() ){
  // TODO: copy values
}
/*
template<class T>
matrix<T>::matrix( const matrix& );
template<class T>
matrix<T>::matrix( matrix&& );

template<class T>
matrix& matrix<T>::operator=( const matrix& );
template<class T>
matrix& matrix<T>::operator=( matrix&& );
template<class T>
matrix& matrix<T>::operator=( std::initializer_list<std::initializer_list<T>> );

template<class T>
matrix<T>::~matrix(){}
*/
//-----------------------------------------------------------------------------
// Comparison
//-----------------------------------------------------------------------------

template< class T >
bool operator==( const matrix<T>& lhs, const matrix<T>& rhs );

template< class T >
bool operator!=( const matrix<T>& lhs, const matrix<T>& rhs );

template< class T >
bool operator<( const matrix<T>& lhs, const matrix<T>& rhs );

template< class T >
bool operator<=( const matrix<T>& lhs, const matrix<T>& rhs );

template< class T >
bool operator>( const matrix<T>& lhs, const matrix<T>& rhs );

template< class T >
bool operator>=( const matrix<T>& lhs, const matrix<T>& rhs );

#endif
