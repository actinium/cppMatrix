#include <vector>
#include <stdexcept>

namespace mat{

template<class T>
class matrix{
 private:
  class matrix_row;
  friend class matrix_row;
  //----------------------------------------------------------------------------
  // Types
  //----------------------------------------------------------------------------
 public:
  using value_type             = typename std::vector<T>::value_type;
  using size_type              = typename std::vector<T>::size_type;
  using difference_type        = typename std::vector<T>::difference_type;
  using reference              = typename std::vector<T>::reference;
  using const_reference        = typename std::vector<T>::const_reference;
  using iterator               = typename std::vector<T>::iterator;
  using const_iterator         = typename std::vector<T>::const_iterator;
  using reverse_iterator       = typename std::vector<T>::reverse_iterator;
  using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

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
  reference at( size_type, size_type );
  const_reference at( size_type, size_type ) const;
  matrix_row operator[]( size_type );
  const matrix_row operator[]( size_type ) const;

  //----------------------------------------------------------------------------
  // Iterators
  //----------------------------------------------------------------------------
 public:
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  const_iterator cbegin() const;
  const_iterator cend() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

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
    // Types
   public:
    using iterator               = typename std::vector<T>::iterator;
    using const_iterator         = typename std::vector<T>::const_iterator;
    using reverse_iterator       = typename std::vector<T>::reverse_iterator;
    using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;
    // Constructor
   public:
    matrix_row( matrix*, size_type );
    // Element Access
   public:
    matrix<T>::reference operator[]( size_type );
    matrix<T>::const_reference operator[]( size_type ) const;
    // Iterators
   public:
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
   private:
    matrix<T>* matrix_;
    size_type row_;
  };
 private:
  class matrix_row_pointer{
   public:
    matrix_row_pointer( matrix* m, size_type r):matrix_row_(m,r){}
    matrix_row operator*(){ return matrix_row_; }
    matrix_row* operator->(){ return &matrix_row_; }
   private:
    matrix_row matrix_row_;
  };

  //----------------------------------------------------------------------------
  // Helper functions
  //----------------------------------------------------------------------------
 private:
  std::vector<T> make_vector(std::initializer_list<std::initializer_list<T>>);
  size_type rc2i( size_type, size_type ) const;

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
