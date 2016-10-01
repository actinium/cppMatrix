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

