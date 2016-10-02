//-----------------------------------------------------------------------------
// Helper functions
//-----------------------------------------------------------------------------
template<class T>
std::vector<T> matrix<T>::make_vector(
    std::initializer_list<std::initializer_list<T>> init_list){
  std::vector<T> vec;
  for(auto& row: init_list){
    vec.insert(vec.end(),row);
  }
  return vec;
}

template<class T>
std::size_t matrix<T>::rc2i(std::size_t row,std::size_t col){
  return row*cols_+col;
}
