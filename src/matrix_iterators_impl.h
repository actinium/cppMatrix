//------------------------------------------------------------------------------
// Iterators
//------------------------------------------------------------------------------

namespace mat{

template<class T>
typename matrix<T>::iterator matrix<T>::begin(){
  return data_.begin();
}

template<class T>
typename matrix<T>::iterator matrix<T>::end(){
  return data_.end();
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::begin() const{
  return data_.begin();
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::end() const{
  return data_.end();
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::cbegin() const{
  return data_.cbegin();
}

template<class T>
typename matrix<T>::const_iterator matrix<T>::cend() const{
  return data_.cend();
}

template<class T>
typename matrix<T>::reverse_iterator matrix<T>::rbegin(){
  return data_.rbegin();
}

template<class T>
typename matrix<T>::reverse_iterator matrix<T>::rend(){
  return data_.rend();
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::rbegin() const{
  return data_.rbegin();
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::rend() const{
  return data_.rend();
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::crbegin() const{
  return data_.crbegin();
}

template<class T>
typename matrix<T>::const_reverse_iterator matrix<T>::crend() const{
  return data_.crend();
}

}
