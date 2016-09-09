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

  ~matrix();

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
  std::size_t rows();
  std::size_t columns();

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
