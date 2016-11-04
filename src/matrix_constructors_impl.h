//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T>::matrix():
    data_(),
    rows_(0),
    cols_(0) {}

template<class T>
matrix<T>::matrix( std::size_t rows, std::size_t cols ):
    data_(rows*cols),
    rows_(rows),
    cols_(cols) {}

template<class T>
matrix<T>::matrix( std::initializer_list<std::initializer_list<T>> init_list):
    data_( make_vector(init_list) ),
    rows_(init_list.size()),
    cols_( (init_list.size() > 0) ? init_list.begin()->size() : 0 ) {
  if(rows() == 0 || columns() == 0){
    rows_ = 0;
    cols_ = 0;
  }
}

template<class T>
matrix<T> matrix<T>::identity(std::size_t size){
  matrix<T> ret(size,size);
  for(int i=0; i<size; ++i){
    ret[i][i] = 1;
  }
  return ret;
}

}

//-----------------------------------------------------------------------------
// Row Class Constructor
//-----------------------------------------------------------------------------

namespace mat{

template<class T>
matrix<T>::matrix_row::matrix_row( matrix<T>* mp, std::size_t row):
    matrix_(mp), row_(row){}

}
