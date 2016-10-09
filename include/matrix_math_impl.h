//-----------------------------------------------------------------------------
// Math
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Unary minus
//-----------------------------------------------------------------------------
template<class T>
matrix<T> operator-( const matrix<T>& m1 ){
  matrix<T> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = -m1[r][c];
    }
  }
  return mr;
}

//-----------------------------------------------------------------------------
// Addition
//-----------------------------------------------------------------------------
template<class T1, class T2>
auto operator+( const matrix<T1>& m1, const matrix<T2>& m2 )
  -> matrix<decltype(m1[0][0]*m2[0][0])>{
  if(m1.rows() != m2.rows() || m1.columns() != m2.columns()){
    throw dimension_error(
        "Matrix addition requires same dimensions for both matrices!");
  }
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] + m2[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator+( const C& constant, const matrix<T>& m )
  -> matrix<decltype(constant+m[0][0])>{
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = constant + m[r][c];
    }
  }
  return mr;
}
template<class C,class T>
auto operator+( const matrix<T>& m, const C& constant)
  -> matrix<decltype(constant+m[0][0])>{
  return operator+( constant, m );
}

//-----------------------------------------------------------------------------
// Subtraction
//-----------------------------------------------------------------------------
template<class T1, class T2>
auto operator-( const matrix<T1>& m1, const matrix<T2>& m2 )
  -> matrix<decltype(m1[0][0]*m2[0][0])>{
  if(m1.rows() != m2.rows() || m1.columns() != m2.columns()){
    throw dimension_error(
        "Matrix subtraction requires same dimensions for both matrices!");
  }
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] - m2[r][c];
    }
  }
  return mr;
}

template<class C,class T>
auto operator-( const C& constant, const matrix<T>& m )
  -> matrix<decltype(constant-m[0][0])>{
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = constant - m[r][c];
    }
  }
  return mr;
}
template<class C,class T>
auto operator-( const matrix<T>& m, const C& constant)
  -> matrix<decltype(constant-m[0][0])>{
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = m[r][c] - constant;
    }
  }
  return mr;
}

//-----------------------------------------------------------------------------
// Multiplication
//-----------------------------------------------------------------------------
template<class T1, class T2>
auto operator*( const matrix<T1>& m1, const matrix<T2>& m2 )
  -> matrix<decltype(m1[0][0]*m2[0][0])>{
  if(m1.columns() != m2.rows() ){
    throw dimension_error(
        "Matrix multiplication requires number of rows and columns to match!");
  }
  std::size_t length = m1.columns();
  matrix<decltype(m1[0][0]*m2[0][0])> mr(m1.rows(),m2.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      decltype(m1[0][0]*m2[0][0]) elem{};
      for(std::size_t i=0; i < length; ++i){
        elem += m1[r][i]*m2[i][c];
      }
      mr[r][c] = elem;
    }
  }
  return mr;
}

template<class C,class T>
matrix<T> operator*( const C& constant, const matrix<T>& m ){
  matrix<T> mr(m.rows(),m.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = constant * m[r][c];
    }
  }
  return mr;
}
template<class C,class T>
matrix<T> operator*( const matrix<T>& m, const C& constant){
  return operator*( constant, m );
}
//-----------------------------------------------------------------------------
// Transpose
//-----------------------------------------------------------------------------
template<class T>
matrix<T> matrix<T>::transpose() const {
  matrix<T> mr(columns(),rows());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = (*this)[c][r];
    }
  }
  return mr;
}
//-----------------------------------------------------------------------------
// Determinant
//-----------------------------------------------------------------------------
template<class T>
template<class DT>
DT matrix<T>::determinant() const{
  if(columns() != rows() ){
    throw dimension_error(
        "Determinant can only be calculated for square matrices!");
  }
  // TODO
  return 0;
}
//-----------------------------------------------------------------------------
// Inverse
//-----------------------------------------------------------------------------
template<class T>
matrix<T> matrix<T>::inverse() const {
  if(columns() != rows() ){
    throw dimension_error(
        "The inverse can only be calculated for square matrices!");
  }
  // TODO
  return *this;
}
