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
