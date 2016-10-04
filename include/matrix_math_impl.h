//-----------------------------------------------------------------------------
// Math
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

template<class T>
matrix<T> operator+( const matrix<T>& m1, const matrix<T>& m2 ){
  // !!!
  // throw if dimensons missmatch
  // !!!
  matrix<T> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] + m2[r][c];
    }
  }
  return mr;
}

template<class T>
matrix<T> operator-( const matrix<T>& m1, const matrix<T>& m2 ){
  // !!!
  // throw if dimensons missmatch
  // !!!
  matrix<T> mr(m1.rows(),m1.columns());
  for(std::size_t r=0; r < mr.rows(); ++r){
    for(std::size_t c=0; c < mr.columns(); ++c){
      mr[r][c] = m1[r][c] - m2[r][c];
    }
  }
  return mr;
}
