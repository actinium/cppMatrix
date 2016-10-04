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
