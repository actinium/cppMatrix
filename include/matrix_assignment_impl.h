//-----------------------------------------------------------------------------
// Assignments
//-----------------------------------------------------------------------------

template<class T>
matrix<T>& matrix<T>::operator=(
    std::initializer_list<std::initializer_list<T>> init_list){
  data_ = make_vector(init_list);
  return this;
}

