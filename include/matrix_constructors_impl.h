//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

template<class T>
matrix<T>::matrix():data_(),rows_(0),cols_(0){}
template<class T>
matrix<T>::matrix( std::size_t rows, std::size_t cols ):
    data_(rows*cols),rows_(rows),cols_(cols){}
template<class T>
matrix<T>::matrix( std::initializer_list<std::initializer_list<T>> init_list):
    data_( init_list.size() * init_list.begin()->size() ),
    rows_(init_list.size()),cols_( init_list.begin()->size() ){
  // TODO: copy values
  // Or create concat function for init_list and use it to initialize
  // data_ vector.
}

