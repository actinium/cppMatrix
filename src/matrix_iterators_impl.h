//------------------------------------------------------------------------------
// Iterators
//------------------------------------------------------------------------------

namespace mat{
//------------------------------------------------------------------------------
// Matrix Row Iterator
//------------------------------------------------------------------------------
template<class T>
typename matrix<T>::matrix_row matrix<T>::matrix_row_iterator::operator*(){
  return matrix_row( matrix_, row_ );
}

template<class T>
typename matrix<T>::matrix_row_pointer matrix<T>::matrix_row_iterator::operator->(){
  return matrix_row_pointer( matrix_, row_ );
}

template<class T>
typename matrix<T>::matrix_row
  matrix<T>::matrix_row_iterator::operator[]( size_type index ){
  return matrix_row( matrix_, row_ + index );
}

template<class T>
typename matrix<T>::matrix_row_iterator&
  matrix<T>::matrix_row_iterator::operator++(){
  ++row_;
  return *this;
}

template<class T>
typename matrix<T>::matrix_row_iterator
  matrix<T>::matrix_row_iterator::operator++(int){
  matrix_row_iterator mri = *this;
  ++row_;
  return mri;
}

template<class T>
typename matrix<T>::matrix_row_iterator&
  matrix<T>::matrix_row_iterator::operator--(){
  --row_;
  return *this;
}

template<class T>
typename matrix<T>::matrix_row_iterator
  matrix<T>::matrix_row_iterator::operator--(int){
  matrix_row_iterator mri = *this;
  --row_;
  return mri;
}

template<class T>
bool matrix<T>::matrix_row_iterator::operator==(const matrix_row_iterator& m_other){
  return matrix_ == m_other.matrix_ && row_ == m_other.row_;
}

template<class T>
bool matrix<T>::matrix_row_iterator::operator!=(const matrix_row_iterator& m_other){
  return !operator==(m_other);
}
//------------------------------------------------------------------------------
// Iterators over rows of a matrix
//------------------------------------------------------------------------------
// Normal iterators
template<class T>
typename matrix<T>::iterator matrix<T>::begin(){
  return matrix_row_iterator(this,0);
}

template<class T>
typename matrix<T>::iterator matrix<T>::end(){
  return matrix_row_iterator(this,rows());
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::begin() const{
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::end() const{
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::cbegin() const{
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::cend() const{
}

// Reverse iterators
template<class T>
typename matrix<T>::reverse_iterator matrix<T>::rbegin(){
}

template<class T>
typename matrix<T>::reverse_iterator matrix<T>::rend(){
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::rbegin() const{
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::rend() const{
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::crbegin() const{
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::crend() const{
}

//------------------------------------------------------------------------------
// Iterators over elements of a row
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
  return matrix_->data_.cbegin() + matrix_->rc2i(row_,0);
}

template<class T>
typename matrix<T>::matrix_row::const_iterator
  matrix<T>::matrix_row::end() const{
  return matrix_->data_.cbegin() + matrix_->rc2i(row_,matrix_->columns());
}

template<class T>
typename matrix<T>::matrix_row::const_iterator
  matrix<T>::matrix_row::cbegin() const{
  return matrix_->data_.cbegin() + matrix_->rc2i(row_,0);
}

template<class T>
typename matrix<T>::matrix_row::const_iterator
  matrix<T>::matrix_row::cend() const{
  return matrix_->data_.cbegin() + matrix_->rc2i(row_,matrix_->columns());
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
  return const_reverse_iterator(cend());
}

template<class T>
typename matrix<T>::matrix_row::const_reverse_iterator
  matrix<T>::matrix_row::rend() const{
  return const_reverse_iterator(cbegin());
}

template<class T>
typename matrix<T>::matrix_row::const_reverse_iterator
  matrix<T>::matrix_row::crbegin() const{
  return const_reverse_iterator(cend());
}

template<class T>
typename matrix<T>::matrix_row::const_reverse_iterator
  matrix<T>::matrix_row::crend() const{
  return const_reverse_iterator(cbegin());
}

}
