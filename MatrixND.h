//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_MATRIXND_H
#define PHYSICSFORMULA_MATRIXND_H
#include <algorithm> // for std::swap
#include <cstddef>
#include <cassert>
#include <vector>
#include <iostream>
#include <iomanip>
#include "VectorND.h"

using namespace std;
// Matrix traits: This describes how a matrix is accessed. By
// externalizing this information into a traits class, the same code
// can be used both with native arrays and matrix classes. To use the
// default implementation of the traits class, a matrix type has to
// provide the following definitions as members:
//
// * typedef ... index_type;
//   - The type used for indexing (e.g. size_t)
// * typedef ... value_type;
//   - The element type of the matrix (e.g. double)
// * index_type min_row() const;
//   - returns the minimal allowed row index
// * index_type max_row() const;
//   - returns the maximal allowed row index
// * index_type min_column() const;
//   - returns the minimal allowed column index
// * index_type max_column() const;
//   - returns the maximal allowed column index
// * value_type& operator()(index_type i, index_type k)
//   - returns a reference to the element i,k, where
//     min_row() <= i <= max_row()
//     min_column() <= k <= max_column()
// * value_type operator()(index_type i, index_type k) const
//   - returns the value of element i,k
//
// Note that the functions are all inline and simple, so the compiler
// should completely optimize them away.
template<typename MatrixType> struct matrix_traits
{
    typedef typename MatrixType::index_type index_type;
    typedef typename MatrixType::value_type value_type;
    static index_type min_row(MatrixType const& A)
    { return A.min_row(); }
    static index_type max_row(MatrixType const& A)
    { return A.max_row(); }
    static index_type min_column(MatrixType const& A)
    { return A.min_column(); }
    static index_type max_column(MatrixType const& A)
    { return A.max_column(); }
    static value_type& element(MatrixType& A, index_type i, index_type k)
    { return A(i,k); }
    static value_type element(MatrixType const& A, index_type i, index_type k)
    { return A(i,k); }
};

// specialization of the matrix traits for built-in two-dimensional
// arrays
template<typename T, std::size_t rows, std::size_t columns>
struct matrix_traits<T[rows][columns]>
{
    typedef std::size_t index_type;
    typedef T value_type;
    static index_type min_row(T const (&)[rows][columns])
    { return 0; }
    static index_type max_row(T const (&)[rows][columns])
    { return rows-1; }
    static index_type min_column(T const (&)[rows][columns])
    { return 0; }
    static index_type max_column(T const (&)[rows][columns])
    { return columns-1; }
    static value_type& element(T (&A)[rows][columns],
                               index_type i, index_type k)
    { return A[i][k]; }
    static value_type element(T const (&A)[rows][columns],
                              index_type i, index_type k)
    { return A[i][k]; }
};

// Swap rows i and k of a matrix A
// Note that due to the reference, both dimensions are preserved for
// built-in arrays
template<typename MatrixType>
void swap_rows(MatrixType& A,
               typename matrix_traits<MatrixType>::index_type i,
               typename matrix_traits<MatrixType>::index_type k)
{
    matrix_traits<MatrixType> mt;
    typedef typename matrix_traits<MatrixType>::index_type index_type;

    // check indices
    assert(mt.min_row(A) <= i);
    assert(i <= mt.max_row(A));

    assert(mt.min_row(A) <= k);
    assert(k <= mt.max_row(A));

    for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
        std::swap(mt.element(A, i, col), mt.element(A, k, col));
}

// divide row i of matrix A by v
template<typename MatrixType>
void divide_row(MatrixType& A,
                typename matrix_traits<MatrixType>::index_type i,
                typename matrix_traits<MatrixType>::value_type v)
{
    matrix_traits<MatrixType> mt;
    typedef typename matrix_traits<MatrixType>::index_type index_type;

    assert(mt.min_row(A) <= i);
    assert(i <= mt.max_row(A));

    assert(v != 0);

    for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
        mt.element(A, i, col) /= v;
}

// in matrix A, add v times row k to row i
template<typename MatrixType>
void add_multiple_row(MatrixType& A,
                      typename matrix_traits<MatrixType>::index_type i,
                      typename matrix_traits<MatrixType>::index_type k,
                      typename matrix_traits<MatrixType>::value_type v)
{
    matrix_traits<MatrixType> mt;
    typedef typename matrix_traits<MatrixType>::index_type index_type;

    assert(mt.min_row(A) <= i);
    assert(i <= mt.max_row(A));

    assert(mt.min_row(A) <= k);
    assert(k <= mt.max_row(A));

    for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
        mt.element(A, i, col) += v * mt.element(A, k, col);
}

// convert A to reduced row echelon form
template<typename MatrixType>
void to_reduced_row_echelon_form(MatrixType& A)
{
    matrix_traits<MatrixType> mt;
    typedef typename matrix_traits<MatrixType>::index_type index_type;

    index_type lead = mt.min_row(A);

    for (index_type row = mt.min_row(A); row <= mt.max_row(A); ++row)
    {
        if (lead > mt.max_column(A))
            return;
        index_type i = row;
        while (mt.element(A, i, lead) == 0)
        {
            ++i;
            if (i > mt.max_row(A))
            {
                i = row;
                ++lead;
                if (lead > mt.max_column(A))
                    return;
            }
        }
        swap_rows(A, i, row);
        divide_row(A, row, mt.element(A, row, lead));
        for (i = mt.min_row(A); i <= mt.max_row(A); ++i)
        {
            if (i != row)
                add_multiple_row(A, i, row, -mt.element(A, i, lead));
        }
    }
}

template<typename MatrixType>
void print_matrix(MatrixType m, int rows, int cols)
{
    std::cout << right << setprecision(4) << std::endl;
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
        {
            std::cout<<setw(7)<<right << m[r][c] << '\t';
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}





template<typename T>
class MatrixND
{

    // turns a single index into a row and column and returns the value at that index
    int getAt(int index);
    // sets the value at the given index
    void setAt(int index, int value);

public:
    int rows{};
    int cols{};
    std::vector<T> data;
    MatrixND();

    template<typename ... Args>
    explicit MatrixND(const int& r_, const int& c_, const T& first, const Args&... args);
    MatrixND(int r, int c);
    MatrixND(std::vector<T>, int rows, int cols);
    MatrixND(T* data, int rows, int cols);

    MatrixND(const MatrixND& other); // copy constructor
    MatrixND(MatrixND&& other) noexcept; // move constructor
    MatrixND& operator=(const MatrixND& other); // copy assignment
    MatrixND& operator=(MatrixND&& other) noexcept ; // move assignment

    void set(std::vector<T>, int rows, int cols);
    template<typename  ... Args>
    void set(const T& first, const Args&... args);
    void setAt(int row, int col, T value);
    // method to test if matrix is square
    bool isSquare() const; // returns true if matrix is square
    bool isZero() const; // returns true if matrix is zero
    bool isIdentity() const; // returns true if matrix is identity
    bool isDiagonal() const; // returns true if matrix is diagonal
    bool isSymmetric() const; // returns true if matrix is symmetric
    bool isSkewSymmetric() const; // returns true if matrix is skew symmetric
    bool isUpperTriangular() const; // returns true if matrix is upper triangular
    bool isLowerTriangular() const; // returns true if matrix is lower triangular
    bool isTridiagonal() const; // returns true if matrix is tridiagonal


    void print();
    MatrixND<T> transpose();
    MatrixND<T> inverse();
    float determinant();
    // method to create an identity matrix of a square matrix
    MatrixND<T> identity();
    // method to create a zero matrix of a square matrix
    MatrixND<T> zero();
    // method to calculate the rank of a matrix
    int rank();
    // method to put matrix into reduced row echelon form
    MatrixND<T> rref();
    // method to determine if matrix is in reduced row echelon form
    bool IsRowEchelon();
    MatrixND<T> dot(const MatrixND<T> &);
    MatrixND<T> cross(const MatrixND<T>&);
    MatrixND<T> add(const MatrixND<T> &);
    MatrixND<T> sub(const MatrixND<T> &);
    MatrixND<T> mult(const MatrixND<T> &);
    MatrixND<T> mult(const T &);
    bool isEqual(const MatrixND<T> &);
    MatrixND<T> concat(const MatrixND<T> &); // concatenate two matrices
    MatrixND<T> stack(const MatrixND<T> &); // stack vertically
    MatrixND<T> kronecker(const MatrixND<T> &); // kronecker product
    // method to vind the eignenvectors of the matrix
    MatrixND<T> eigenvectors();
    // method to return a vector of eigenvalues of the matrix
    std::vector<T> eigenvalues();
    // method to take the mean of the matrix
    double mean();
    // method to take the standard deviation of the matrix
    double std();
    // method to take the covariance of the matrix
    double cov();
    // method to take the correlation of the matrix
    double corr();
    // method to take the sum of the matrix elements
    double sum();

    int getRows()const; // returns the number of rows
    int getCols()const; // returns the number of columns
    // method to return the top number of specified rows of the matrix
    MatrixND<T> topRows(int rows);
    // method to return the bottom number of specified rows of the matrix
    MatrixND<T> bottomRows(int rows);
    // method to return the left number of specified columns of the matrix
    MatrixND<T> leftCols(int cols);
    // method to return the right number of specified columns of the matrix
    MatrixND<T> rightCols(int cols);
    // method to return the top left number of specified rows and columns of the matrix
    MatrixND<T> topLeft(int rows, int cols);
    // method to return the top right number of specified rows and columns of the matrix
    MatrixND<T> topRight(int rows, int cols);
    // method to return the bottom left number of specified rows and columns of the matrix
    MatrixND<T> bottomLeft(int rows, int cols);
    // method to return the bottom right number of specified rows and columns of the matrix
    MatrixND<T> bottomRight(int rows, int cols);
    // method to ruturn the colwise mean of the matrix
    double colwiseMean(int col);
    // method to ruturn the rowwise mean of the matrix
    double rowwiseMean(int row);
    // method to ruturn the colwise standard deviation of the matrix
    double colwiseStd(int col);
    // method to ruturn the rowwise standard deviation of the matrix
    double rowwiseStd(int row);
    // method to ruturn the colwise covariance of the matrix
    double colwiseCov(int col);
    // method to ruturn the rowwise covariance of the matrix
    double rowwiseCov(int row);
    // method to ruturn the colwise correlation of the matrix
    double colwiseCorr(int col);
    // method to ruturn the rowwise correlation of the matrix
    double rowwiseCorr(int row);
    // method to ruturn the colwise sum of the matrix
    double colwiseSum(int col);
    // method to ruturn the rowwise sum of the matrix
    double rowwiseSum(int row);
    // method to ruturn the colwise top number of specified rows of the matrix
    MatrixND<T> colwiseTopRows(int rows);
    // method to ruturn the rowwise top number of specified rows of the matrix
    MatrixND<T> rowwiseTopRows(int rows);
    // method to ruturn the colwise bottom number of specified rows of the matrix
    MatrixND<T> colwiseBottomRows(int rows);
    // method to ruturn the rowwise bottom number of specified rows of the matrix
    MatrixND<T> rowwiseBottomRows(int rows);
    // colwise to return a colwise vector of the matrix
    std::vector<T> colwise(int col);
    // look at the data in a colwise fashion
    MatrixND<T> colwise();
    // rowwise to return a rowwise vector of the matrix
    std::vector<T> rowwise(int row);
    // look at the data in a rowwise fashion
    MatrixND<T> rowwise();
    // method to return the max coefficient of the matrix
    T max();
    // method to return the min coefficient of the matrix
    T min();
    // method to return the max coefficient of a specified row of the matrix
    T maxRow(int row);
    // method to return the min coefficient of a specified row of the matrix
    T minRow(int row);
    // method to return the max coefficient of a specified column of the matrix
    T maxCol(int col);
    // method to return the min coefficient of a specified column of the matrix
    T minCol(int col);


    int get(int row, int col)const;
    // overload the parenthesis operator to get the value at a given row and column
    T& operator()(int row, int col);
    // overload the parenthesis operator to set the value at a given row and column
    void operator()(int row, int col, T value);
    // method to flatten the matrix into a vector
    std::vector<T> flatten();
    // method to reshape the matrix into a new matrix
    MatrixND<T> reshape(int rows, int cols);
    // method to return the diagonal elements of the matrix
    MatrixND<T> diag();
    // method to return the trace of the matrix
    T trace();
    // method to return the sum of the absolute values of the matrix
    T sumAbs();
    // method to turn the matrix into an array
    T* array();

    MatrixND<T> operator+(const MatrixND<T> &);
    VectorND<T> operator+(const VectorND<T> &);
    MatrixND<T> operator-(const MatrixND<T> &);
    VectorND<T> operator-(const VectorND<T> &);
    MatrixND<T> operator*(const MatrixND<T> &);
    VectorND<T> operator*(const VectorND<T> &);
    MatrixND<T> operator*(const T &);
    bool operator==(const MatrixND<T> &);

    template <class U> friend MatrixND<U> operator+ (const MatrixND<U>& lhs, const MatrixND<U>& rhs);
    template <class U> friend MatrixND<U> operator+ (const U& lhs, const MatrixND<U>& rhs);
    template <class U> friend MatrixND<U> operator+ (const MatrixND<U>& lhs, const U& rhs);

    template <class U> friend MatrixND<U> operator- (const MatrixND<U>& lhs, const MatrixND<U>& rhs);
    template <class U> friend MatrixND<U> operator- (const U& lhs, const MatrixND<U>& rhs);
    template <class U> friend MatrixND<U> operator- (const MatrixND<U>& lhs, const U& rhs);

    template <class U> friend MatrixND<U> operator* (const MatrixND<U>& lhs, const MatrixND<U>& rhs);
    template <class U> friend MatrixND<U> operator* (const U& lhs, const MatrixND<U>& rhs);
    template <class U> friend MatrixND<U> operator* (const MatrixND<U>& lhs, const U& rhs);

    template<typename K>
    friend istream& operator>>(istream& is, MatrixND<T>& m);

    template <typename K>
    friend ostream& operator<<(ostream& os, const MatrixND<T>& rhs);


    /*
    MatrixND& operator+=(T a);
    MatrixND& operator-=(T a);
    MatrixND& operator*=(T a);
    MatrixND& operator/=(T a);

    MatrixND& operator+=(MatrixND const& a);
    MatrixND& operator-=(MatrixND const& a);

    MatrixND operator-() const; // unary negation

    // free functions:

    MatrixND<T> operator+(MatrixND<T> const& a, T b);
    MatrixND<T> operator-(MatrixND<T> const& a, T b);
    MatrixND<T> operator*(MatrixND<T> const& a, T b);
    MatrixND<T> operator/(MatrixND<T> const& a, T b);

    MatrixND<T> operator+(T a, MatrixND<T> const& b);
    MatrixND<T> operator-(T a, MatrixND<T> const& b);
    MatrixND<T> operator*(T a, MatrixND<T> const& b);
    MatrixND<T> operator/(T a, MatrixND<T> const& b);

    MatrixND<T> operator+(MatrixND<T> const& a, MatrixND<T> const& b);
    MatrixND<T> operator-(MatrixND<T> const& a, MatrixND<T> const& b);

    MatrixND<T> operator*(MatrixND<T> const& a, MatrixND<T> const& b);

    Vector<T> operator*(MatrixND<T> const& a, Vector<T> const& b);
    Vector<T> operator*(Vector<T> const& a, MatrixND<T> const& b);
    */

    ~MatrixND() = default;

};



#endif //PHYSICSFORMULA_MATRIXND_H
/** Default Constructor

	creates an empty matrix

*/

template <typename T>
MatrixND<T>::MatrixND()
{
    data.clear();
    rows = 0;
    cols = 0;
}


template<typename T>
template<typename ...Args>
MatrixND<T>::MatrixND(const int& r_, const int& c_, const T& first, const Args & ...args)
{
    data.clear();
    rows = r_;
    cols = c_;
    auto total = rows * cols;
    data.push_back(first);
    int dummy[] = { 0, (data.push_back(args), 0)... };
    (void)dummy;
    for (const auto& i : data)
    {
        if(i<=total)
        {
            data.push_back(i);
        }
    }


}

template<typename T>
template<typename ...Args>
inline void MatrixND<T>::set(const T& first, const Args & ...args)
{
    data.clear();
    auto total = rows * cols;
    data.push_back(first);
    int dummy[] = { 0, (data.push_back(args), 0)... };
    (void)dummy;
    for (const auto& i : data)
    {
        if (i <= total)
        {
            data.push_back(i);
        }
    }
}
template<typename T>
void MatrixND<T>::setAt(int row, int col, T value) {
    data[row * col + col] = value;
}
template<typename T>
bool MatrixND<T>::isSquare() const {
    return rows == cols;
}
template<typename T>
bool MatrixND<T>::isZero() const {
    for (const auto& i : data)
    {
        if (i != 0)
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool MatrixND<T>::isIdentity() const {
    if (!isSquare())
        return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i == j && data[i * cols + j] != 1)
                return false;
            else if (i != j && data[i * cols + j] != 0)
                return false;
    return true;
}
template<typename T>
bool MatrixND<T>::isDiagonal() const {
    if (!isSquare())
        return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i != j && data[i * cols + j] != 0)
                return false;
    return true;
}
template<typename T>
bool MatrixND<T>::isSymmetric() const {
    if (!isSquare())
        return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i != j && data[i * cols + j] != data[j * cols + i])
                return false;
    return true;
}
template<typename T>
bool MatrixND<T>::isSkewSymmetric() const {
    if (!isSquare())
        return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i != j && data[i * cols + j] != -data[j * cols + i])
                return false;
    return true;
}
template<typename T>
bool MatrixND<T>::isUpperTriangular() const {
    if (!isSquare())
        return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i > j && data[i * cols + j] != 0)
                return false;
    return true;
}
template<typename T>
bool MatrixND<T>::isLowerTriangular() const {
    if (!isSquare())
        return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i < j && data[i * cols + j] != 0)
                return false;
    return true;
}
template<typename T>
bool MatrixND<T>::isTridiagonal() const {
    if (!isSquare())
        return false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i == j && data[i * cols + j] != 0)
                continue;
            else if (i != j && i + 1 == j && data[i * cols + j] != 0)
                continue;
            else if (i != j && i - 1 == j && data[i * cols + j] != 0)
                continue;
            else
                return false;
    return true;
}


template<typename T>
inline MatrixND<T>::MatrixND(int r, int c)
{
    rows = r;
    cols = c;
    data = vector<T>(r * c);
}

/** Constructor
	creates the matrix as the following:
	@params elements the elements of the matrix in Row-major form
			numRows  the number of rows in the matrix
			numCols  the number of columns in the matrix
*/
template <typename T>
MatrixND<T>::MatrixND(std::vector<T> elm, int numRows, int numCols)
{
    rows = numRows;
    cols = numCols;
    data.clear();
    for(unsigned int i = 0; i < elm.size(); i++) {
        data.push_back(elm[i]);
    }
}

template<typename T>
MatrixND<T>::MatrixND(T *data, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->data = vector<T>(data, data + rows * cols);
}

/** set

	resets the matrix to the input

	@params elements, - the elements of the matrix in Row-major form
			numRows, - the number of rows in the matrix
			numCols; - the number of coumns in the matrix
	@return void; nothing to return

*/

template <typename T>
void MatrixND<T>::set(std::vector<T> elements, int numRows, int numCols)
{
    rows = numRows;
    cols = numCols;
    data.clear();
    for(unsigned int i = 0; i < elements.size(); i++) {
        data.push_back(elements[i]);
    }
}


/** operator+ (add)
	lhs + rhs;
	elementwise adition of rhs to lhs

	@params rhs; the matrix to add
	@return matrix; the sum

*/

template <typename T>
MatrixND<T> MatrixND<T>::operator+(const MatrixND<T> & rhs)
{
    return this->add(rhs);
}
template<typename T>
VectorND<T> MatrixND<T>::operator+(const VectorND<T> & rhs) {
    assert(this->cols == rhs.size() && this->rows == 1);
    VectorND<T> result(this->cols);
    for (int i = 0; i < this->cols; i++) {
        result.setAt(i, this->data[i] + rhs.getAt(i));
    }
    return result;
}

/** operator- (subtract)
	lhs - rhs;
	elementwise subtraction of rhs from lhs

	@params rhs; the matrix to subtract
	@return matrix; the difference

*/

template <typename T>
MatrixND<T> MatrixND<T>::operator-(const MatrixND<T> & rhs)
{
    return this->sub(rhs);
}
template<typename T>
VectorND<T> MatrixND<T>::operator-(const VectorND<T> & rhs) {
    assert(this->cols == rhs.size() && this->rows == 1);
    VectorND<T> result(this->cols);
    for (int i = 0; i < this->cols; i++) {
        result.setAt(i, this->data[i] - rhs.getAt(i));
    }
    return result;
}

/** operator(*) Matrix multiplication
	lhs * rhs;
	calculate A * x = B
	@params rhs; the second matrix
	@return matrix; the transformed product matrix
*/
template <typename T>
MatrixND<T> MatrixND<T>::operator*(const MatrixND<T> & rhs)
{
    return this->mult(rhs);
}

/** operator* (scalar multiplication)
	M<T> * T;
	calculate scalar product of a matrix

	@params rhs; the scalar;
	@return matrix; the transformed product matrix

*/
template <typename T>
MatrixND<T> MatrixND<T>::operator*(const T & t)
{
    return this->mult(t);
}
template<class U>
MatrixND<U> operator+(const MatrixND<U> &lhs, const MatrixND<U> &rhs) {
    int numRows = lhs.getRows();
    int numCols = lhs.getCols();
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i] = lhs.getAt(i) + rhs.getAt(i);

    MatrixND<U> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}
template<class U>
MatrixND<U> operator+(const U &lhs, const MatrixND<U> &rhs) {
    int numRows = rhs.getRows();
    int numCols = rhs.getCols();
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i] = lhs + rhs.getAt(i);

    MatrixND<U> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}
template<class U>
MatrixND<U> operator+(const MatrixND<U> &lhs, const U &rhs) {
    int numRows = lhs.getRows();
    int numCols = lhs.getCols();
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i] = lhs.getAt(i) + rhs;

    MatrixND<U> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}
template<class U>
MatrixND<U> operator-(const MatrixND<U> &lhs, const MatrixND<U> &rhs) {
    int numRows = lhs.getRows();
    int numCols = lhs.getCols();
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i] = lhs.getAt(i) - rhs.getAt(i);

    MatrixND<U> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
} //
template<class U>
MatrixND<U> operator-(const U& lhs, const MatrixND<U>& rhs) {
    int numRows = rhs.getRows();
    int numCols = rhs.getCols();
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i] = lhs - rhs.getAt(i);

    MatrixND<U> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}
template<class U>
MatrixND<U> operator-(const MatrixND<U>& lhs, const U& rhs) {
    int numRows = lhs.getRows();
    int numCols = lhs.getCols();
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i] = lhs.getAt(i) - rhs;

    MatrixND<U> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}
template<class U>
MatrixND<U> operator*(const MatrixND<U> &lhs, const MatrixND<U> &rhs) {
    // Verify the dimensions of the inputs.
    if (lhs.getCols() != rhs.getRows())
        throw std::invalid_argument("Number of columns in matrix must equal number of rows in vector.");

    // Setup the vector for the output.
    MatrixND<U> result(lhs.m_nRows);

    // Loop over rows and columns and perform the multiplication operation element-by-element.
    for (int row=0; row<lhs.getRows(); ++row)
    {
        U cumulativeSum = static_cast<U>(0.0);
        for (int col=0; col<lhs.getCols(); ++col)
        {
            cumulativeSum += (lhs.getAt(row, col) * rhs.getAt(col, row));
        }
        result.setAt(row, cumulativeSum);
    }

    return result;
}
template<class U>
MatrixND<U> operator*(const U &lhs, const MatrixND<U> &rhs) {
    int numRows = rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; ++i)
        tempResult[i] = lhs * rhs.m_matrixData[i];

    MatrixND<U> result(tempResult, numRows, numCols);
    delete[] tempResult;
    return result;
}
template<class U>
MatrixND<U> operator*(const MatrixND<U> &lhs, const U &rhs) {
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;
    U *tempResult = new U[numElements];
    for (int i=0; i<numElements; ++i)
        tempResult[i] = lhs.m_matrixData[i] * rhs;

    MatrixND<U> result(tempResult, numRows, numCols);
    delete[] tempResult;
    return result;
}
/** operator ==

	elemetnwise comparison of two matrices of equal size

	@params rhs; the second matrix
	@return bool; true if same size and elements all equal

*/
template <typename T>
bool MatrixND<T>::operator==(const MatrixND<T> & rhs)
{
    return this->isEqual(rhs);
}

template<typename T>
inline istream& operator>>(istream& is, MatrixND<T>& m)
{
    auto length = m.rows * m.cols;
    std::cout << "enter values of the " << m.rows << " x " << m.cols << " matrix\n>>";
    for (int i = 0; i < length; i++)
    {
        is >> m.data[i];
    }
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const MatrixND<T>& rhs)
{
    auto total = rhs.rows * rhs.cols;
    std::cout << std::setprecision(4);
    for (size_t i = 0; i < total; i++) {
        os << setw(6) << left << rhs.data[i] << "  ";
        if ((i + 1) % rhs.cols == 0)
            os << std::endl;
    }
    return os;
}


/**
 *isEqual
 *
 * element wise comparison of two matrices of equal size
 *
 *@params rhs; the second matrix
 *@return bool; true if same size and elements all equal
*/
template <typename T>
bool MatrixND<T>::isEqual(const MatrixND<T> & rhs)
{


    if(rows != rhs.rows || cols != rhs.cols) {
        return false;
    }

    for(unsigned int i = 0; i < data.size(); i++) {
        if(data[i] != rhs.data[i])
            return false;
    }

    return true;
}

/** add

	elementwise adition of rhs to lhs

	@params rhs; the matrix to add
	@return matrix; the sum

*/

template <typename T>
MatrixND<T> MatrixND<T>::add(const MatrixND<T> & rhs)
{


    if(rows != rhs.rows || cols != rhs.cols) {
        MatrixND<T> matrix;
        return matrix;
    }

    std::vector<T> vec;
    for(unsigned int i = 0; i < data.size(); i++) {
        vec.push_back(data[i] + rhs.data[i]);
    }

    return MatrixND<T>(vec,rows,cols);
}

template <typename T>
MatrixND<T> MatrixND<T>::dot(const MatrixND<T> & rhs)
{
    if(rows != rhs.rows && cols != rhs.cols) {
        std::cout << "Error! Can not resolve dot product on these matrices!"
                  << std::endl;
        return *this;
    }

    std::vector<T> vec(this->cols);
    MatrixND<T> result(vec, 1, rhs.cols);
    T sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < rhs.cols; j++) {
            sum += data[j * this->cols + i] * rhs.data[j * this->cols + i];
        }
        result.data[i] = sum;
        sum = 0;
    }

    return result;
}

template <typename T>
MatrixND<T> MatrixND<T>::cross(const MatrixND<T>& rhs)
{
    assert(this->rows == 3 && this->cols == 3 && rhs.rows == 3 && rhs.cols == 3);
    T a, b, c, d, e, f, g, h, i;
    a = b = c = d = e = f = g = h = i = 0.0;
    a = this->data[3] * rhs.data[6] - this->data[6] * rhs.data[3];
    b = this->data[4] * rhs.data[7] - this->data[7] * rhs.data[4];
    c = this->data[5] * rhs.data[8] - this->data[8] * rhs.data[5];
    d = this->data[6] * rhs.data[0] - this->data[0] * rhs.data[6];
    e = this->data[7] * rhs.data[1] - this->data[1] * rhs.data[7];
    f = this->data[8] * rhs.data[2] - this->data[2] * rhs.data[8];
    g = this->data[0] * rhs.data[3] - this->data[3] * rhs.data[0];
    h = this->data[1] * rhs.data[4] - this->data[4] * rhs.data[1];
    i = this->data[2] * rhs.data[5] - this->data[5] * rhs.data[2];
    MatrixND<T> result(3, 3, a, b, c, d, e, f, g, h, i);
    return result;
}

template <typename T>
MatrixND<T> MatrixND<T>::mult(const MatrixND<T> & rhs)
{
    assert(this->cols == rhs.rows);
    std::vector<T> d(this->rows*rhs.cols);
    MatrixND<T> result(d, this->rows, rhs.cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < rhs.cols; j++) {
            long int sum = 0;
            for (int k = 0; k < rhs.rows; k++) {
                sum += data[i * this->cols + k] * rhs.data[k * rhs.cols + j];
                result.data[i * this->rows + j] = sum;
            }
        }
    }
    return result;
}

/** multiplication (scalar)

	calculate scalar product of a matrix

	@params rhs; the scalar;
	@return matrix; the transformed product matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::mult(const T & scalar)
{

    std::vector<T> vec;
    for(unsigned int i = 0; i < data.size(); i++) {
        vec.push_back(data[i] * scalar);
    }

    return MatrixND<T>(vec,rows,cols);
}

/** subtract

	elementwise subtraction of rhs from lhs

	@params rhs; the matrix to subtract
	@return matrix; the difference

*/

template <typename T>
MatrixND<T> MatrixND<T>::sub(const MatrixND<T> & rhs)
{
    if(rows != rhs.rows || cols != rhs.cols) {
        MatrixND<T> matrix;
        return matrix;
    }

    std::vector<T> vec;
    for(unsigned int i = 0; i < data.size(); i++) {
        vec.push_back(data[i] - rhs.data[i]);
    }

    return MatrixND<T>(vec,rows,cols);
}

template <typename T>
void MatrixND<T>::print()
{
   // print out in a nice format using setw and setprecision
    std::cout << std::setprecision(4);
   for(unsigned int i = 0; i < data.size(); i++) {
       std::cout << std::setw(6) << left << data[i] << " ";
       if(i % cols == cols - 1) {
           std::cout << std::endl;
       }
   }
}


/** transpose

	Calculate transpose of matrix

	@return matrix; the transpose of this matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::transpose()
{
    std::vector<T> vec(this->rows*this->cols);
    MatrixND<T> results(vec, cols, rows);
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j< rows; j++)
        {
            results.data[j*cols+i] = data[i*cols+j];
        }
    }
    return results;
}

/** Inverse
 * calculate the inverse of a matrix
 * @return matrix; the inverse of this matrix
 */
 template<typename T>
 MatrixND<T> MatrixND<T>::inverse()
 {
     assert(rows == cols);
     MatrixND<T> result(rows, cols);
     T det = this->determinant();
     if(det == 0) {
         std::cout << "Error! Determinant is 0!" << std::endl;
         return result;
     }
     MatrixND<T> cofactor(rows, cols);
     for(int i = 0; i < rows; i++) {
         for(int j = 0; j < cols; j++) {
             cofactor.data[i*cols+j] = this->cofactor(i, j);
         }
     }
     result = cofactor.transpose().mult(1/det);
     return result;
 }

 /** determinant
  * calculate the determinant of a matrix
  * @ return T; the determinant of this matrix  *
  */
 template<typename T>
 float MatrixND<T>::determinant()
 {
     assert(rows == cols);
     auto det = 0;
     if(rows == 1) {
         det = data[0];
     }
     else if(rows == 2) {
         det = data[0] * data[3] - data[1] * data[2];
     }
     else {
         det = 0;
         for(int i = 0; i < rows; i++) {
             det += pow(-1, i) * data[i] * this->cofactor(0, i);
         }
     }
     return det;
 }

template<typename T>
MatrixND<T> MatrixND<T>::identity() {
    if (rows != cols) {
        MatrixND<T> matrix;
        return matrix;
    }
    std::vector<T> vec(rows*cols);
    MatrixND<T> results(vec, rows, cols);
    for (int i = 0; i < rows; i++) {
        results.data[i * cols + i] = 1;
    }
    return results;
}

template<typename T>
MatrixND<T> MatrixND<T>::zero() {
    std::vector<T> vec(rows*cols);
    MatrixND<T> results(vec, rows, cols);
    return results;
}

template<typename T>
int MatrixND<T>::rank() {
    // Convert the matrix to row-echelon form.
    MatrixND<T> matrixCopy = this->RowEchelon();

    /* If this didn't work, then we compute the rank by finding
        the largest non-zero sub-matrix with a non-zero determinant.

        Note that this method is slower for large matrices and therefore
        it is better to use the RowEchelon method if possible. */
    int numNonZeroRows = 0;
    if (!matrixCopy.IsRowEchelon())
    {
        // Setup a std::vector to store the sub-matrices as we go.
        std::vector<MatrixND<T>> subMatrixVector;

        // Store the current matrix into the array first.
        subMatrixVector.push_back(*this);

        /* Loop through the subMatrixVector until either we have tested every
            sub-matrix or the completeFlag is set. */
        bool completeFlag = false;
        int subMatrixCount = 0;
        while ((subMatrixCount < subMatrixVector.size()) && (!completeFlag))
        {
            // Extract the currentMatrix to work with.
            MatrixND<T> currentMatrix = subMatrixVector[subMatrixCount];
            subMatrixCount++;

            // Test if this matrix is non-zero.
            if (currentMatrix.IsNonZero())
            {
                // If the determinant is non-zero, then we have our result.
                T currentMatrixDet = currentMatrix.Determinant();
                if (!CloseEnough(currentMatrixDet, 0.0))
                {
                    completeFlag = true;
                    numNonZeroRows = currentMatrix.GetNumRows();
                }
                else
                {
                    // Extract and store each sub-matrix (if larger than 2x2).
                    if ((currentMatrix.GetNumRows() > 2) && (currentMatrix.GetNumCols() > 2))
                    {
                        for (int i=0; i<currentMatrix.GetNumRows(); ++i)
                        {
                            for (int j=0; j<currentMatrix.GetNumCols(); ++j)
                            {
                                // Extract this sub-matrix and store.
                                subMatrixVector.push_back(currentMatrix.FindSubMatrix(i,j));
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        /* Converting to row echelon form did work, so we can simply
            count the number of non-zero rows to get the rank. */

        /* If we get to here, then we can assume that the matrix is now
            in row-echelon form and we can compute the rank quite easily
            as simply the number of non-zero rows. */

        int nRows = matrixCopy.GetNumRows();
        int nCols = matrixCopy.GetNumCols();

        // Loop over each row and test whether it has at least one non-zero element.
        for (int i=0; i<nRows; ++i)
        {
            // Loop over the columns of this row.
            int colSum = 0;
            for (int j=0; j<nCols; ++j)
            {
                if (!CloseEnough(matrixCopy.GetElement(i,j), 0.0))
                    colSum++;
            }
            // If colSum is greater than zero, then increment numNonZeroRows.
            if (colSum > 0)
                numNonZeroRows++;
        }

    }
    // The rank of the matrix is simply the number of non-zero rows.
    return numNonZeroRows;
}

template<typename T>
MatrixND<T> MatrixND<T>::rref() {
    MatrixND<T> result = *this;
    for (int i = 0; i < rows; i++) {
        int max = i;
        for (int j = i + 1; j < rows; j++) {
            if (abs(result.data[j * cols + i]) > abs(result.data[max * cols + i])) {
                max = j;
            }
        }
        if (abs(result.data[max * cols + i]) < 1e-10) {
            continue;
        }
        if (max != i) {
            result.swap_row(i, max);
        }
        for (int j = i + 1; j < rows; j++) {
            result.data[j * cols + i] /= result.data[i * cols + i];
            for (int k = i + 1; k < cols; k++) {
                result.data[j * cols + k] -= result.data[j * cols + i] * result.data[i * cols + k];
            }
        }
    }
    return result;
}

template<typename T>
bool MatrixND<T>::IsRowEchelon() {
    MatrixND<T> rref = this->rref();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j && rref.data[i * cols + j] != 0) {
                return false;
            }
        }
    }
    return true;
}
/** Concat

	append two matrices of equal row count

	@params rhs; the matrix to concatanate
	@return matrix; the contanated matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::concat(const MatrixND<T> & rhs)
{

    if(rows != rhs.rows)
        return MatrixND<T>(*this);

    std::vector<T> vec;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            vec.push_back(data[i*cols + j]);
        }
        for(int j = 0; j < rhs.cols; j++) {
            vec.push_back(rhs.data[i*rhs.cols + j]);
        }
    }

    return MatrixND<T>(vec,rows,cols+rhs.cols);
}

/** stack

	append two matrices of equal column count

	@params rhs; the matrix to stack below
	@return matrix; the lhs stacked ontop of rhs matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::stack(const MatrixND<T> & rhs)
{
    if(cols != rhs.cols)
        return MatrixND<T>(*this);

    std::vector<T> vec;

    for(unsigned int i = 0; i < data.size(); i++) {
        vec.push_back(data[i]);
    }
    for(unsigned int i = 0; i < rhs.data.size(); i++) {
        vec.push_back(rhs.data[i]);
    }

    return MatrixND<T>(vec,rows+rhs.rows,cols);
}

/** Kronecker
	https://en.wikipedia.org/wiki/Kronecker_product
	calculate kroncker product of two matrices

	@params rhs; the matrix operand
	@return matrix; the Kronecker product matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::kronecker(const MatrixND<T> & rhs)
{
    std::vector<T> vec;

    for(int i = 0; i < (rows*cols*rhs.rows*rhs.cols); i++) {
        int j = (i/rhs.cols)%cols + (i/(cols*rhs.rows*rhs.cols))*cols; //iterate lhs in proper order
        int k = (i%rhs.cols) + ((i / (cols * rhs.cols))%rhs.rows)*rhs.cols;  //iterate rhs in proper order
        //can use scalar multiplactions, matrix concat and stacking, but this is a single iteration through the vector.
        //Kronecker iterates both matrices in a pattern relative to the large product matrix.
        //std::cout << i << " : " << j << " : " << k << std::endl;
        //std::cout << i << " : " << j << " : " << k << " : " << l << std::endl;
        vec.push_back(data[j]*rhs.data[k]);
    }

    return MatrixND<T>(vec,rows*rhs.rows,cols*rhs.cols);
}
template <typename T>
std::vector<T> MatrixND<T>::eigenvalues() {
    std::vector<T> eigenvalues;
    MatrixND<T> eigenvectors = this->eigenvectors();
    for(int i = 0; i < eigenvectors.rows; i++) {
        eigenvalues.push_back(eigenvectors.data[i*eigenvectors.cols]);
    }
    return eigenvalues;
}

/**
 * get the number of rows in the matrix
 * @tparam T
 * @return
 */
template <typename T>
int MatrixND<T>::getRows()const
{
    return rows;
}
/**
 * get the number of columns in the matrix
 * @tparam T
 * @return
 */
template <typename T>
int MatrixND<T>::getCols()const
{
    return cols;
}
template<typename T>
int MatrixND<T>::getAt(int index) {
    return data[index];
}
template<typename T>
void MatrixND<T>::setAt(int index, int value) {
    data[index] = value;
}

/**
 * get the element at the specified row and column
 * @param row
 * @param col
 * @return T : the element at the specified row and column
 */
template <typename T>
int MatrixND<T>::get(int row, int col)const
{
    return data[row*cols + col];
}
/**
 * multiply the matrix by the vector
 * @tparam T
 * @return VectorND<T> : the vector multiplied by the matrix
 */
template<typename T>
VectorND<T> MatrixND<T>::operator*(const VectorND<T> & v) {
    assert(this->cols == v.getSize());
    std::vector<T> vec;
    for(int i = 0; i < rows; i++) {
        T sum = 0;
        for(int j = 0; j < cols; j++) {
            sum += data[i*cols + j] * v.get(j);
        }
        vec.push_back(sum);
    }
    return VectorND<T>(vec,rows);
}

template<typename T>
MatrixND<T>::MatrixND(MatrixND &&other) noexcept {
    data = std::move(other.data);
    rows = other.rows;
    cols = other.cols;
}

template<typename T>
MatrixND<T>::MatrixND(const MatrixND &other) {
    data = other.data;
    rows = other.rows;
    cols = other.cols;
}

template<typename T>
MatrixND<T> &MatrixND<T>::operator=(const MatrixND &other) {
    data = other.data;
    rows = other.rows;
    cols = other.cols;
    return *this;
}

template<typename T>
MatrixND<T> &MatrixND<T>::operator=(MatrixND &&other)  noexcept {
    data = std::move(other.data);
    rows = other.rows;
    cols = other.cols;
    return *this;
}

template<typename T>
T &MatrixND<T>::operator()(int row, int col) {
    return data[row*cols + col];
}

template<typename T>
void MatrixND<T>::operator()(int row, int col, T value) {
    data[row*cols + col] = value;
}

template<typename T>
MatrixND<T> MatrixND<T>::topRows(int rows) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::bottomRows(int rows) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(rows-i-1,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::leftCols(int cols) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::rightCols(int cols) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,cols-j-1);
        }
    }
    return m;
}

template<typename T>
double MatrixND<T>::mean() {
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += data[i*cols + j];
        }
    }
    return sum/(rows*cols);
}

template<typename T>
double MatrixND<T>::std() {
    double mean = this->mean();
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += pow(data[i*cols + j] - mean,2);
        }
    }
    return sqrt(sum/(rows*cols));
}

template<typename T>
double MatrixND<T>::cov() {
    double mean = this->mean();
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += (data[i*cols + j] - mean)*(data[i*cols + j] - mean);
        }
    }
    return sum/(rows*cols);
}

template<typename T>
double MatrixND<T>::corr() {
    double cov = this->cov();
    double std = this->std();
    return cov/(std*std);
}

template<typename T>
double MatrixND<T>::sum() {
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += data[i*cols + j];
        }
    }
    return sum;
}

template<typename T>
vector<T> MatrixND<T>::flatten() {
    vector<T> vec;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            vec.push_back(data[i*cols + j]);
        }
    }
    return vec;
}

template<typename T>
MatrixND<T> MatrixND<T>::reshape(int rows, int cols) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::diag() {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == j) {
                m(i,j) = this->operator()(i,j);
            }
        }
    }
    return m;
}

template<typename T>
T MatrixND<T>::trace() {
    T sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += this->operator()(i,i);
    }
    return sum;
}

template<typename T>
T MatrixND<T>::sumAbs() {
    T sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += abs(data[i*cols + j]);
        }
    }
    return sum;
}

template<typename T>
T *MatrixND<T>::array() {
    return data.data();
}

template<typename T>
MatrixND<T> MatrixND<T>::topLeft(int rows, int cols) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::topRight(int rows, int cols) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,cols-j-1);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::bottomLeft(int rows, int cols) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(rows-i-1,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::bottomRight(int rows, int cols) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(rows-i-1,cols-j-1);
        }
    }
    return m;
}

template<typename T>
double MatrixND<T>::colwiseMean(int col) {
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += data[i*cols + col];
    }
    return sum/(rows);
}

template<typename T>
double MatrixND<T>::rowwiseMean(int row) {
    double sum = 0;
    for(int i = 0; i < cols; i++) {
        sum += data[row*cols + i];
    }
    return sum/(cols);
}

template<typename T>
double MatrixND<T>::colwiseStd(int col) {
    double mean = this->colwiseMean(col);
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += pow(data[i*cols + col] - mean,2);
    }
    return sqrt(sum/(rows));
}

template<typename T>
double MatrixND<T>::rowwiseStd(int row) {
    double mean = this->rowwiseMean(row);
    double sum = 0;
    for(int i = 0; i < cols; i++) {
        sum += pow(data[row*cols + i] - mean,2);
    }
    return sqrt(sum/(cols));
}


template<typename T>
double MatrixND<T>::colwiseCov(int col) {
    double mean = this->colwiseMean(col);
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += (data[i*cols + col] - mean)*(data[i*cols + col] - mean);
    }
    return sum/(rows);
}

template<typename T>
double MatrixND<T>::rowwiseCov(int row) {
    double mean = this->rowwiseMean(row);
    double sum = 0;
    for(int i = 0; i < cols; i++) {
        sum += (data[row*cols + i] - mean)*(data[row*cols + i] - mean);
    }
    return sum/(cols);
}

template<typename T>
double MatrixND<T>::colwiseCorr(int col) {
    double cov = this->colwiseCov(col);
    double std = this->colwiseStd(col);
    return cov/(std*std);
}

template<typename T>
double MatrixND<T>::rowwiseCorr(int row) {
    double cov = this->rowwiseCov(row);
    double std = this->rowwiseStd(row);
    return cov/(std*std);
}

template<typename T>
double MatrixND<T>::colwiseSum(int col) {
    double sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += data[i*cols + col];
    }
    return sum;
}

template<typename T>
double MatrixND<T>::rowwiseSum(int row) {
    double sum = 0;
    for(int i = 0; i < cols; i++) {
        sum += data[row*cols + i];
    }
    return sum;
}

template<typename T>
MatrixND<T> MatrixND<T>::rowwiseTopRows(int rows) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::colwiseTopRows(int rows) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(j,i);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::colwiseBottomRows(int rows) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(cols-j-1,i);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::rowwiseBottomRows(int rows) {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(rows-i-1,j);
        }
    }
    return m;
}

template<typename T>
vector<T> MatrixND<T>::colwise(int col) {
    vector<T> v(rows);
    for(int i = 0; i < rows; i++) {
        v[i] = data[i*cols + col];
    }
    return v;
}

template<typename T>
vector<T> MatrixND<T>::rowwise(int row) {
    vector<T> v(cols);
    for(int i = 0; i < cols; i++) {
        v[i] = data[row*cols + i];
    }
    return v;
}

template<typename T>
T MatrixND<T>::max() {
    T max = data[0];
    for(int i = 0; i < rows*cols; i++) {
        if(data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

template<typename T>
T MatrixND<T>::min() {
    T min = data[0];
    for(int i = 0; i < rows*cols; i++) {
        if(data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

template<typename T>
T MatrixND<T>::maxRow(int row) {
    T max = data[row*cols];
    for(int i = 0; i < cols; i++) {
        if(data[row*cols + i] > max) {
            max = data[row*cols + i];
        }
    }
    return max;
}

template<typename T>
T MatrixND<T>::minRow(int row) {
    T min = data[row*cols];
    for(int i = 0; i < cols; i++) {
        if(data[row*cols + i] < min) {
            min = data[row*cols + i];
        }
    }
    return min;
}

template<typename T>
T MatrixND<T>::maxCol(int col) {
    T max = data[col];
    for(int i = 0; i < rows; i++) {
        if(data[i*cols + col] > max) {
            max = data[i*cols + col];
        }
    }
    return max;
}

template<typename T>
T MatrixND<T>::minCol(int col) {
    T min = data[col];
    for(int i = 0; i < rows; i++) {
        if(data[i*cols + col] < min) {
            min = data[i*cols + col];
        }
    }
    return min;
}
template<typename T>
MatrixND<T> MatrixND<T>::rowwise() {
    MatrixND<T> m(rows,cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,j) = this->operator()(i,j);
        }
    }
    return m;
}

template<typename T>
MatrixND<T> MatrixND<T>::colwise() {
    MatrixND<T> m(rows,1);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m(i,0) = data[i*cols + j];
        }
    }
    return m;
}