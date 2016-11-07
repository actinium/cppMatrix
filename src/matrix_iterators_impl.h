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
