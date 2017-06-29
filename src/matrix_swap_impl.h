//------------------------------------------------------------------------------
// Swap
//------------------------------------------------------------------------------

namespace mat{

template<class T>
void matrix<T>::swap( matrix<T>& other ){
  using std::swap;
  swap( data_, other.data_ );
  swap( rows_, other.rows_ );
  swap( cols_, other.cols_ );
}

template<class T>
void swap( matrix<T>& m1, matrix<T>& m2 ){
  m1.swap( m2 );
}

}
