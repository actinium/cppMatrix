//-----------------------------------------------------------------------------
// Element Access
//-----------------------------------------------------------------------------

template<class T>
T& matrix<T>::at( std::size_t row, std::size_t col ){
  return data_.at(row*cols_+col);
}

template<class T>
const T& matrix<T>::at( std::size_t row, std::size_t col ) const{
  return data_.at(row*cols_+col);
}

template<class T>
typename matrix<T>::matrix_row matrix<T>::operator[]( std::size_t row ){
  return 0;
}

template<class T>
const typename matrix<T>::matrix_row matrix<T>::operator[](
    std::size_t row ) const{
  return 0;
}

