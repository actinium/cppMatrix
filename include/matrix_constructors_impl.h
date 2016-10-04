//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
// Row Class Constructor
//-----------------------------------------------------------------------------

template<class T>
matrix<T>::matrix_row::matrix_row( matrix<T>* mp, std::size_t row):
    matrix_(mp), row_(row){}
