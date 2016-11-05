//------------------------------------------------------------------------------
// Helper functions
//------------------------------------------------------------------------------

namespace mat{

template<class T>
std::vector<T> matrix<T>::make_vector(
    std::initializer_list<std::initializer_list<T>> init_list){
  std::vector<T> vec;
  for(auto& row: init_list){
    vec.insert(vec.end(),row);
  }
  return vec;
}

/**
 * rc2i - Matrix (r)ow and (c)olumn to Vector (i)ndex conversion
 */
template<class T>
typename matrix<T>::size_type matrix<T>::rc2i( size_type row, size_type col ){
  return row*cols_+col;
}

}
