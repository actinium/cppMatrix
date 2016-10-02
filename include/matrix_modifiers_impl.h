//-----------------------------------------------------------------------------
// Modifiers
//-----------------------------------------------------------------------------

template<class T>
void matrix<T>::clear(){
  data_.clear();
  rows_ = 0;
  cols_ = 0;
}

template<class T>
void matrix<T>::resize( std::size_t rows, std::size_t cols ){
  // TODO
}
