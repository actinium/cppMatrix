//------------------------------------------------------------------------------
// Matrix Output
//------------------------------------------------------------------------------

namespace mat{

template<class T>
std::ostream& operator<<( std::ostream& os, const matrix<T>& m ){
  os << "[";
  for( int r=0; r < m.rows(); ++r ){
    os << "[";
    for( int c=0; c < m.columns(); ++c ){
      os << m[r][c];
      if( c != m.columns() - 1 ){
        os << ",";
      }
    }
    os << "]";
    if( r != m.rows() - 1 ){
      os << ",";
    }
  }
  os << "]";
  return os;
}

}
