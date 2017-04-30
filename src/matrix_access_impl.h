//------------------------------------------------------------------------------
// Element Access
//------------------------------------------------------------------------------

namespace mat{

template<class T>
typename matrix<T>::reference matrix<T>::at( size_type row, size_type col ){
  if(row >= rows()){
    throw std::out_of_range("row >= this->rows()!");
  }
  if(col >= columns()){
    throw std::out_of_range("col >= this->columns()!");
  }
  return data_.at(rc2i(row,col));
}

template<class T>
typename matrix<T>::const_reference matrix<T>::at( size_type row, size_type col ) const{
  if(row >= rows()){
    throw std::out_of_range("row >= this->rows()!");
  }
  if(col >= columns()){
    throw std::out_of_range("col >= this->columns()!");
  }
  return data_.at(rc2i(row,col));
}

template<class T>
typename matrix<T>::matrix_row matrix<T>::operator[]( size_type row ){
  return matrix_row(this,row);
}

template<class T>
const typename matrix<T>::matrix_row matrix<T>::operator[](
    size_type row ) const{
  return matrix_row(const_cast<matrix<T>*>(this),row);
}

}

//------------------------------------------------------------------------------
// Row class element Access
//------------------------------------------------------------------------------

namespace mat{

template<class T>
typename matrix<T>::reference matrix<T>::matrix_row::operator[]( size_type col ){
  return matrix_->data_[matrix_->rc2i(row_,col)];
}

template<class T>
typename matrix<T>::const_reference  matrix<T>::matrix_row::operator[]( size_type col ) const{
  return matrix_->data_[matrix_->rc2i(row_,col)];
}

}
