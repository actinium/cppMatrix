//------------------------------------------------------------------------------
// Modifiers
//------------------------------------------------------------------------------

namespace mat{

template<class T>
void matrix<T>::resize( std::size_t rows, std::size_t cols ){
  std::size_t old_rows = this->rows();
  std::size_t old_cols = this->columns();
  std::vector<T> new_data( rows * cols );
  for(std::size_t r=0; r < old_rows; ++r){
    for(std::size_t c=0; c < old_cols; ++c){
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
