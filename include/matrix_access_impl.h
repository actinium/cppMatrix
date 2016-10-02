//-----------------------------------------------------------------------------
// Element Access
//-----------------------------------------------------------------------------

template<class T>
T& matrix<T>::at( std::size_t row, std::size_t col ){
  // TODO throw if out of bounds
  return data_.at(row*cols_+col);
}

template<class T>
const T& matrix<T>::at( std::size_t row, std::size_t col ) const{
  // TODO throw if out of bounds
  return data_.at(row*cols_+col);
}

template<class T>
typename matrix<T>::matrix_row matrix<T>::operator[]( std::size_t row ){
  return matrix_row(this,row);
}

template<class T>
const typename matrix<T>::matrix_row matrix<T>::operator[](
    std::size_t row ) const{
  return matrix_row(this,row);
}

//-----------------------------------------------------------------------------
// Row class element Access
//-----------------------------------------------------------------------------

template<class T>
T& matrix<T>::matrix_row::operator[](std::size_t col){
  return matrix_->data_[row_*matrix_->cols_+col];
}

template<class T>
const T& matrix<T>::matrix_row::operator[](std::size_t col) const{
  return matrix_->data_[row_*matrix_->cols_+col];
}

