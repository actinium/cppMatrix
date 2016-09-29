template<class T>
T& matrix<T>::at( std::size_t, std::size_t ){
  return 0;
}

template<class T>
const T& matrix<T>::at( std::size_t, std::size_t ) const{
  return 0;
}

template<class T>
typename matrix<T>::matrix_row matrix<T>::operator[]( std::size_t ){
  return 0;
}

template<class T>
const typename matrix<T>::matrix_row matrix<T>::operator[]( std::size_t ) const{
  return 0;
}

