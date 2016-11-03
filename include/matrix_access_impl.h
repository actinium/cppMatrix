//-----------------------------------------------------------------------------
// Element Access
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
// Row class element Access
//-----------------------------------------------------------------------------

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
