//------------------------------------------------------------------------------
// Modifiers
//------------------------------------------------------------------------------

namespace mat{

template<class T>
void matrix<T>::resize( size_type rows, size_type cols ){
  size_type old_rows = this->rows();
  size_type old_cols = this->columns();
  std::vector<T> new_data( rows * cols );
  for(size_type r=0; r < old_rows; ++r){
    for(size_type c=0; c < old_cols; ++c){
      if( r < rows && c < cols ){
        new_data[r*cols+c] = data_[r*old_cols+c];
      }
    }
  }
  rows_ = rows;
  cols_ = cols;
  data_ = new_data;
}

}
