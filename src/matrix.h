#include <vector>
#include <stdexcept>

namespace mat{

template<class T>
class matrix{
  class matrix_row;
  //----------------------------------------------------------------------------
  // Types
  //----------------------------------------------------------------------------
 public:
  using value_type      = typename std::vector<T>::value_type;
  using size_type       = typename std::vector<T>::size_type;
  using difference_type = typename std::vector<T>::difference_type;
  using reference       = typename std::vector<T>::reference;
  using const_reference = typename std::vector<T>::const_reference;

  //----------------------------------------------------------------------------
  // Constructors and assignments
  //----------------------------------------------------------------------------
 public:
  matrix();
  matrix( size_type, size_type );
  matrix( std::initializer_list<std::initializer_list<T>> );
  static matrix identity( size_type );
  matrix( const matrix& ) = default;
  matrix( matrix&& ) = default;

  matrix& operator=( std::initializer_list<std::initializer_list<T>> );
  matrix& operator=( const matrix& ) = default;
  matrix& operator=( matrix&& ) = default;

  ~matrix() = default;

  //----------------------------------------------------------------------------
  // Element Access
  //----------------------------------------------------------------------------
 public:
  T& at( size_type, size_type );
  const T& at( size_type, size_type ) const;
  matrix_row operator[]( size_type );
  const matrix_row operator[]( size_type ) const;

  //----------------------------------------------------------------------------
  // Iterators
  //----------------------------------------------------------------------------
 public:
  /*
  matrix_row begin();
  matrix_row end();
  const matrix_row begin() const;
  const matrix_row end() const;
  const matrix_row cbegin() const;
  const matrix_row cend() const;
  */

  //----------------------------------------------------------------------------
  // Size
  //----------------------------------------------------------------------------
 public:
  size_type rows() const { return rows_;}
  size_type columns() const {return cols_;}

  //----------------------------------------------------------------------------
  // Modifiers
  //----------------------------------------------------------------------------
 public:
  void resize( size_type, size_type );
  void fill( const T& );
  void swap( matrix& );
  friend void swap( matrix& m1, matrix& m2){
    using std::swap;
    // swap m1 and m2
  }

  //----------------------------------------------------------------------------
  // Comparison
  //----------------------------------------------------------------------------
 public:
  bool operator==( const matrix<T>& other ) const;
  bool operator!=( const matrix<T>& other ) const;

  //----------------------------------------------------------------------------
  // Maths
  //----------------------------------------------------------------------------
 public:
  matrix transpose() const;
  template<class DT=T>
  DT determinant() const;
  matrix inverse() const;

  //----------------------------------------------------------------------------
  // Row Class
  //----------------------------------------------------------------------------
 private:
  class matrix_row{
   public:
    // Constructor
    matrix_row( matrix*, size_type );
    // Element Access
    T& operator[]( size_type );
    const T& operator[]( size_type ) const;
    // Iterators
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
    const T* cbegin() const;
    const T* cend() const;
   private:
    matrix<T>* matrix_;
    size_type row_;
  };

  //----------------------------------------------------------------------------
  // Helper functions
  //----------------------------------------------------------------------------
 private:
  std::vector<T> make_vector(std::initializer_list<std::initializer_list<T>>);
  size_type rc2i( size_type, size_type );

  //----------------------------------------------------------------------------
  // Member Variables
  //----------------------------------------------------------------------------
 private:
  std::vector<T> data_;
  size_type rows_;
  size_type cols_;
};

//------------------------------------------------------------------------------
// Dimension Exception
//------------------------------------------------------------------------------
class dimension_error: public std::exception {
 public:
  explicit dimension_error( const char* what_arg ):msg_(what_arg) {}
  virtual const char* what() const throw(){
    return msg_.c_str();
  }
 private:
  std::string msg_;
};

}
