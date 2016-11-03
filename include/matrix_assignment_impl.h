//-----------------------------------------------------------------------------
// Assignments
//-----------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T>& matrix<T>::operator=(
    std::initializer_list<std::initializer_list<T>> init_list){
  data_ = make_vector(init_list);
  rows_ = init_list.size();
  cols_ = (init_list.size() > 0) ? init_list.begin()->size() : 0;
  return this;
}

}
