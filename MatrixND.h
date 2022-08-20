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
#include <cstdlib>
#include <ctime>
#include <random>
#include "VectorND.h"
#define THRESHOLD 1e-10
// enum class for different random_device types
enum class RandomGenerator {
    MERSENNE_TWISTER,
    LINEAR_CONGRUENTIAL
};


using namespace std;
namespace rez {
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
    template<typename MatrixType>
    struct matrix_traits {
        typedef typename MatrixType::index_type index_type;
        typedef typename MatrixType::value_type value_type;
        static index_type min_row(MatrixType const &A) { return A.min_row(); }
        static index_type max_row(MatrixType const &A) { return A.max_row(); }
        static index_type
        min_column(MatrixType const &A) { return A.min_column(); }
        static index_type
        max_column(MatrixType const &A) { return A.max_column(); }
        static value_type &
        element(MatrixType &A, index_type i, index_type k) { return A(i, k); }
        [[maybe_unused]] static value_type
        element(MatrixType const &A, index_type i, index_type k) {
            return A(i, k);
        }
    };

// specialization of the matrix traits for built-in two-dimensional
// arrays
    template<typename T, std::size_t rows, std::size_t columns>
    struct matrix_traits<T[rows][columns]> {
        typedef std::size_t index_type;
        typedef T value_type;
        static index_type min_row(T const (&)[rows][columns]) { return 0; }
        static index_type max_row(T const (&)[rows][columns]) {
            return rows - 1;
        }
        static index_type min_column(T const (&)[rows][columns]) { return 0; }
        static index_type max_column(T const (&)[rows][columns]) {
            return columns - 1;
        }
        [[maybe_unused]] static value_type &element(T (&A)[rows][columns],
                                   index_type i,
                                   index_type k) { return A[i][k]; }
        [[maybe_unused]] static value_type element(T const (&A)[rows][columns],
                                  index_type i,
                                  index_type k) { return A[i][k]; }
    };

// Swap rows i and k of a matrix A
// Note that due to the reference, both dimensions are preserved for
// built-in arrays
    template<typename MatrixType>
    void swap_rows(MatrixType &A,
                   typename matrix_traits<MatrixType>::index_type i,
                   typename matrix_traits<MatrixType>::index_type k) {
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
    void divide_row(MatrixType &A,
                    typename matrix_traits<MatrixType>::index_type i,
                    typename matrix_traits<MatrixType>::value_type v) {
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
    void add_multiple_row(MatrixType &A,
                          typename matrix_traits<MatrixType>::index_type i,
                          typename matrix_traits<MatrixType>::index_type k,
                          typename matrix_traits<MatrixType>::value_type v) {
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
    [[maybe_unused]] void to_reduced_row_echelon_form(MatrixType &A) {
        matrix_traits<MatrixType> mt;
        typedef typename matrix_traits<MatrixType>::index_type index_type;

        index_type lead = mt.min_row(A);

        for (index_type row = mt.min_row(A); row <= mt.max_row(A); ++row) {
            if (lead > mt.max_column(A))
                return;
            index_type i = row;
            while (mt.element(A, i, lead) == 0) {
                ++i;
                if (i > mt.max_row(A)) {
                    i = row;
                    ++lead;
                    if (lead > mt.max_column(A))
                        return;
                }
            }
            swap_rows(A, i, row);
            divide_row(A, row, mt.element(A, row, lead));
            for (i = mt.min_row(A); i <= mt.max_row(A); ++i) {
                if (i != row)
                    add_multiple_row(A, i, row, -mt.element(A, i, lead));
            }
        }
    }

    template<typename MatrixType>
    void print_matrix(MatrixType m, int rows, int cols) {
        std::cout << right << setprecision(4) << std::endl;
        for (size_t r = 0; r < rows; r++) {
            for (size_t c = 0; c < cols; c++) {
                std::cout << setw(7) << right << m[r][c] << '\t';
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }
} // namespace rez
//*****************************************************************************
//*****************************************************************************
template<typename T>
class MatrixND
{    // turns a single index into a row and column and returns the value at that index
    T getAt(int index);
    // sets the value at the given index
    void setAt(int index, int value);

public:
    int rows{}; // number of rows
    int cols{}; // number of columns
    std::vector<T> data; // the data

    MatrixND(); // default constructor
    template<typename ... Args> // constructor with arguments
    explicit MatrixND(const int& r_, const int& c_, const T& first, const Args&... args);
    MatrixND(int r, int c); // constructor with dimensions
    MatrixND(int r, int c, int min, int max, RandomGenerator generator); // constructor with dimensions and random values
    MatrixND(std::vector<T>, int rows, int cols); // constructor with data and dimensions
    MatrixND(T* data, int rows, int cols); // constructor with data and dimensions
    MatrixND(T** data, int rows, int cols); // constructor with data and dimensions
    MatrixND(const MatrixND& other); // copy constructor
    MatrixND(MatrixND&& other) noexcept; // move constructor
    MatrixND& operator=(const MatrixND& other); // copy assignment
    MatrixND& operator=(MatrixND&& other) noexcept ; // move assignment
    // allow for MatrixND<T> M = {{1,2,3},{4,5,6}} for initializer list
    MatrixND(std::initializer_list<std::initializer_list<T>> list) :
    MatrixND(list.size(), list.size() ?  list.begin()->size() : 0) {
        int i = 0, j = 0;
        for (auto row : list) {
            for (auto elem : row) {
                data[i * cols + j] = elem;
                j++;
            }
            i++;
            j = 0;
        }
    }


    // set data and dimensions using a vector
    void set(std::vector<T>, int rows, int cols);
    // set data and dimensions using a pointer
    template<typename  ... Args>
    void set(const T& first, const Args&... args);
    // set data at a specific index with a value
    void setAt(int row, int col, T value);
    // method to swap rows
    [[maybe_unused]] void swapRows(int row1, int row2);
    // method to swap columns
    [[maybe_unused]] void swapCols(int col1, int col2);
    // static function to generate and return a random matrix of the given size
    // with values between 0 and 1
    [[maybe_unused]] static MatrixND<T> random(int rows, int cols);
    // static function to generate and return a random matrix of the given size
    // with values in the given range
    [[maybe_unused]] static MatrixND<T>
    random(int rows, int cols, T min, T max, bool continuous = true);
    // method to test if matrix is square
    [[nodiscard]] bool isSquare() const; // returns true if matrix is square
    [[nodiscard]] bool isZero() const; // returns true if matrix is zero
    // returns true if matrix is identity
    [[maybe_unused]] [[nodiscard]] bool isIdentity() const;
    // returns true if matrix is diagonal
    [[maybe_unused]] [[nodiscard]] bool isDiagonal() const;
    // returns true if matrix is symmetric
    [[maybe_unused]] [[nodiscard]] bool isSymmetric() const;
    // returns true if matrix is skew symmetric
    [[maybe_unused]] [[nodiscard]] bool isSkewSymmetric() const;
    // returns true if matrix is upper triangular
    [[maybe_unused]] [[nodiscard]] bool isUpperTriangular() const;
    // returns true if matrix is lower triangular
    [[maybe_unused]] [[nodiscard]] bool isLowerTriangular() const;
    // returns true if matrix is tridiagonal
    [[maybe_unused]] [[nodiscard]] bool isTridiagonal() const;
    //checks if the f1 - f2  close to 0
    bool closeEnough(T f1, T f2);
    // prints the matrix
    void print();
    // returns the transpose of the matrix
    MatrixND<T> transpose();
    // returns the inverse of the matrix
    MatrixND<T> inverse();
    // returns the determinant of the matrix
    float determinant();
    // function to return the characteristic polynomial of the matrix
    std::vector<T> characteristicPolynomial();
    // method to create an identity matrix of a square matrix
    [[nodiscard]] MatrixND<T> identity();
    // method to create a identity matrix of a specified size
    [[nodiscard]] static MatrixND<T> identity(int size);
    // method to create a zero matrix of a square matrix
    MatrixND<T> zero();
    static MatrixND<T> zero(int rows, int cols);
    // method to calculate the rank of a matrix
    int rank();
    // method to put matrix into reduced row echelon form
    MatrixND<T> rref();
    // method to determine if matrix is in reduced row echelon form
    bool isRowEchelon();
    [[nodiscard]] MatrixND<T> dot(const MatrixND<T> &);
    MatrixND<T> cross(const MatrixND<T>&);
    MatrixND<T> add(const MatrixND<T> &);
    MatrixND<T> sub(const MatrixND<T> &);
    MatrixND<T> mult(const MatrixND<T> &);
    MatrixND<T> mult(const T &);
    // Function to add a multiple of row j to row i (in place).
    void addMultiple(int i, int j, T multiple);
    bool isEqual(const MatrixND<T> &);
    // method to calculate the adjoint of a matrix
    MatrixND<T> adjoint();
    [[nodiscard]] MatrixND<T> concat(const MatrixND<T> &); // concatenate two matrices
    [[nodiscard]] MatrixND<T> stack(const MatrixND<T> &); // stack vertically
    [[nodiscard]] MatrixND<T> kronecker(const MatrixND<T> &); // kronecker product
    // method to vind the eignenvectors of the matrix
    MatrixND<T> eigenvectors(); // not implemented
    // method to return a vector of eigenvalues of the matrix
    std::vector<T> eigenvalues(); // not implemented
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
    // enode from row and column to index
    [[nodiscard]] int index(int row, int col)const;

    [[nodiscard]] int getRows()const; // returns the number of rows
    [[nodiscard]] int getCols()const; // returns the number of columns
    // find the sub matrix of the given row and column
    MatrixND<T> subMatrix(int row, int col);
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
    // method to return the cofactor of the matrix at the specified row and column
    T cofactor(int row, int col);
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
    // Function to the find the row with the maximum element at the column given.
    // Returns the row index.
    int findRowWithMaxElement(int col, int row);
    // method to return the max coefficient of the matrix
    T max();
    // find row with max element
    int maxRow();
    // find column with max element
    int maxCol();
    // method to return the min coefficient of the matrix
    T min();
    // find row with min element
    int minRow();
    // find column with min element
    int minCol();
    // method to return the max coefficient of a specified row of the matrix
    T maxRow(int row);
    // method to return the min coefficient of a specified row of the matrix
    T minRow(int row);
    // method to return the max coefficient of a specified column of the matrix
    T maxCol(int col);
    // method to return the min coefficient of a specified column of the matrix
    T minCol(int col);


    [[nodiscard]] T get(int row, int col)const;
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

//    template <class U> friend MatrixND<U> operator+ (const MatrixND<U>& lhs, MatrixND<U>& rhs);
//    template <class U> friend MatrixND<U> operator+ (const U& lhs, MatrixND<U>& rhs);
//    template <class U> friend MatrixND<U> operator+ (const MatrixND<U>& lhs, U& rhs);
//
//    template <class U> friend MatrixND<U> operator- (const MatrixND<U>& lhs, MatrixND<U>& rhs);
//    template <class U> friend MatrixND<U> operator- (const U& lhs, MatrixND<U>& rhs);
//    template <class U> friend MatrixND<U> operator- (const MatrixND<U>& lhs, U& rhs);
//
//    template <class U> friend MatrixND<U> operator* (const MatrixND<U>& lhs, MatrixND<U>& rhs);
//    template <class U> friend MatrixND<U> operator* (const U& lhs, MatrixND<U>& rhs);
//    template <class U> friend MatrixND<U> operator* (const MatrixND<U>& lhs, const U& rhs);

    template<typename K>
    friend istream& operator>>(istream& is, MatrixND<T>& m);

    template <typename K>
    friend ostream& operator<<(ostream& os, const MatrixND<T>& rhs);

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
    data = {first, args...};
    rows = r_;
    cols = c_;
    auto total = rows * cols;

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
    if (row < rows && col < cols) {
        data[row * cols + col] = value;
    }
}

template<typename T>
[[maybe_unused]] void MatrixND<T>::swapRows(int row1, int row2) {
    if (row1 < rows && row2 < rows) {
        for (int i = 0; i < cols; i++) {
            std::swap(data[row1 * cols + i], data[row2 * cols + i]);
        }
    }
}
template<typename T>
[[maybe_unused]] void MatrixND<T>::swapCols(int col1, int col2) {
    if (col1 < cols && col2 < cols) {
        for (int i = 0; i < rows; i++) {
            std::swap(data[i * cols + col1], data[i * cols + col2]);
        }
    }
}
template<typename T>
MatrixND<T> MatrixND<T>::random(int rows, int cols) {
    MatrixND<T> m(rows, cols);
    // seed a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.setAt(i, j, dis(gen));
        }
    }
    return m;
}
template<typename T>
MatrixND<T> MatrixND<T>::random(int rows, int cols, T min, T max, bool continuous) {
    MatrixND<T> m(rows, cols);
    // seed a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    if (continuous) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                m.setAt(i, j, dis(gen));
            }
        }
    }
    else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                m.setAt(i, j, round(dis(gen)));
            }
        }
    }
    return m;
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
[[maybe_unused]] bool MatrixND<T>::isIdentity() const {
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
bool MatrixND<T>::closeEnough(T f1, T f2) {
    return fabs(f1-f2) < 1e-9;
}

template<typename T>
inline MatrixND<T>::MatrixND(int r, int c)
{
    rows = r;
    cols = c;
    data = vector<T>(r * c);
}

template<typename T>
MatrixND<T>::MatrixND(int r, int c, int min, int max,
                      RandomGenerator generator) {
    rows = r;
    cols = c;
    data = vector<T>(r * c);
    // seed a random number generator depending on the generator
    std::random_device rd;
    if (generator == RandomGenerator::MERSENNE_TWISTER) {
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i * cols + j] = dis(gen);
            }
        }
    }
    else if (generator == RandomGenerator::LINEAR_CONGRUENTIAL) {
        std::minstd_rand gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i * cols + j] = dis(gen);
            }
        }
    } else {
        // defalut to srand with time
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i * cols + j] = (T)rand() / RAND_MAX * (max - min) + min;
            }
        }
    }
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

template<typename T>
MatrixND<T>::MatrixND(T **data, int rows, int cols) {
    //use data from the 2d array
    this->rows = rows;
    this->cols = cols;
    this->data = vector<T>(rows * cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            this->data[i * cols + j] = data[i][j];
        }
    }
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
//template<class U>
//MatrixND<U> operator+(const MatrixND<U> &lhs, MatrixND<U> &rhs) {
//    int numRows = lhs.getRows();
//    int numCols = lhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i=0; i<numElements; i++)
//        tempResult[i] = lhs.getAt(i) + rhs.getAt(i);
//
//    MatrixND<U> result(numRows, numCols, tempResult);
//    delete[] tempResult;
//    return result;
//}
//template<class U>
//MatrixND<U> operator+(const U &lhs, MatrixND<U> &rhs) {
//    int numRows = rhs.getRows();
//    int numCols = rhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i=0; i<numElements; i++)
//        tempResult[i] = lhs + rhs.getAt(i);
//
//    MatrixND<U> result(numRows, numCols, tempResult);
//    delete[] tempResult;
//    return result;
//}
//template<class U>
//MatrixND<U> operator+(const MatrixND<U> &lhs, U &rhs) {
//    int numRows = lhs.getRows();
//    int numCols = lhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i=0; i<numElements; i++)
//        tempResult[i] = lhs.getAt(i) + rhs;
//
//    MatrixND<U> result(numRows, numCols, tempResult);
//    delete[] tempResult;
//    return result;
//}
//template<class U>
//MatrixND<U> operator-(const MatrixND<U> &lhs, MatrixND<U> &rhs) {
//    int numRows = lhs.getRows();
//    int numCols = lhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i=0; i<numElements; i++)
//        tempResult[i] = lhs.getAt(i) - rhs.getAt(i);
//
//    MatrixND<U> result(numRows, numCols, tempResult);
//    delete[] tempResult;
//    return result;
//} //
//template<class U>
//MatrixND<U> operator-(const U& lhs, MatrixND<U>& rhs) {
//    int numRows = rhs.getRows();
//    int numCols = rhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i=0; i<numElements; i++)
//        tempResult[i] = lhs - rhs.getAt(i);
//
//    MatrixND<U> result(numRows, numCols, tempResult);
//    delete[] tempResult;
//    return result;
//}
//template<class U>
//MatrixND<U> operator-(const MatrixND<U>& lhs, U& rhs) {
//    int numRows = lhs.getRows();
//    int numCols = lhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i=0; i<numElements; i++)
//        tempResult[i] = lhs.getAt(i) - rhs;
//
//    MatrixND<U> result(numRows, numCols, tempResult);
//    delete[] tempResult;
//    return result;
//}
//template<class U>
//MatrixND<U> operator*(const MatrixND<U> &lhs, MatrixND<U> &rhs) {
//    // Verify the dimensions of the inputs.
//    if (lhs.getCols() != rhs.getRows())
//        throw std::invalid_argument("Number of columns in matrix must equal number of rows in vector.");
//
//    // Setup the vector for the output.
//    MatrixND<U> result(lhs.getRows());
//
//    // Loop over rows and columns and perform the multiplication operation element-by-element.
//    for (int row=0; row<lhs.getRows(); ++row)
//    {
//        U cumulativeSum = static_cast<U>(0.0);
//        for (int col=0; col<lhs.getCols(); ++col)
//        {
//            cumulativeSum += (lhs.getAt(row, col) * rhs.getAt(col, row));
//        }
//        result.setAt(row, cumulativeSum);
//    }
//
//    return result;
//}
//template<class U>
//MatrixND<U> operator*(const U &lhs, MatrixND<U> &rhs) {
//    int numRows = rhs.getRows();
//    int numCols = rhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i = 0; i < numElements; ++i) {
//        tempResult[i] = lhs * rhs.getAt(i);
//    }
//
//    MatrixND<U> result(tempResult, numRows, numCols);
//    delete[] tempResult;
//    return result;
//}
//template<class U>
//MatrixND<U> operator*(const MatrixND<U> &lhs, U &rhs) {
//    int numRows = lhs.getRows();
//    int numCols = lhs.getCols();
//    int numElements = numRows * numCols;
//    U *tempResult = new U[numElements];
//    for (int i=0; i<numElements; ++i)
//        tempResult[i] = lhs.getAt(i) * rhs;
//
//    MatrixND<U> result(tempResult, numRows, numCols);
//    delete[] tempResult;
//    return result;
//}
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
template<typename T>
MatrixND<T> MatrixND<T>::adjoint() {
    MatrixND<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.setAt(i, j, cofactor(i, j));
        }
    }
    // finding any -0 and replacing it with 0
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            if (result.get(i, j) == -0) {
                result.setAt(i, j, 0);
            }
        }
    }
    return result.transpose();
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
            T sum = 0;
            for (int k = 0; k < rhs.rows; k++) {
                sum += data[i * this->cols + k] * rhs.data[k * rhs.cols + j];
                result.data[i * rhs.cols + j] = sum;
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

template<typename T>
void MatrixND<T>::addMultiple(int i, int j, T multiple) {
    for (int k=0; k<cols; ++k)
        data[index(i,k)] += (data[index(j,k)] * multiple);
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
   std::cout << std::endl << std::setprecision(4);
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
    std::vector<T> vec;
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            vec.push_back(data[j * cols + i]);
        }
    }

    return MatrixND<T>(vec,cols,rows);
}

/** Inverse
 * calculate the inverse of a matrix
 * @return matrix; the inverse of this matrix
 */
 template<typename T>
 MatrixND<T> MatrixND<T>::inverse()
 {
     if (rows != cols) {
         MatrixND<T> matrix;
         return matrix;
     }
     MatrixND<T> result(rows, cols);
     T det = this->determinant();
     if(det == 0) {
         std::cout << "Matrix is not invertible" << std::endl;
         return result;
     }
     // calculate the adjoint matrix
     MatrixND<T> inv(rows, cols);
     MatrixND<T> adj = this->adjoint();
     // finding the inverse by dividing the adjoint matrix by the determinant
     for(int i = 0; i < rows; i++) {
         for(int j = 0; j < cols; j++) {
             inv.data[i * cols + j] = adj.data[i * cols + j] / det;
         }
     }
     return inv;
 }

 /** determinant
  * calculate the determinant of a matrix
  * @ return T; the determinant of this matrix  *
  */
 template<typename T>
 float MatrixND<T>::determinant()
 {
// Check if the matrix is square.
     if (!isSquare()) {
         return -999999;
     }

     // If the matrix is 2x2, we can just compute the determinant directly.
     T determinant;
     if (rows == 2)
     {
         determinant = (data[0] * data[3]) - (data[1] * data[2]);
     }
     else
     {
         /* Otherwise we extract the sub-matrices and then recursively call this function
             until we get to 2x2 matrices. */

         // We will find the sub-matrices for row 0.
         // So, loop over each column.
         T cumulativeSum = 0.0;
         T sign = 1.0;
         for (int j = 0; j < cols; ++j)
         {
             // And find the sub-matrix for each element.
             MatrixND<T> subMatrix = this->subMatrix(0, j);

             /* Cumulatively multiply the determinant of the sub-matrix by the
                 current element of this matrix and the sign variable (note the
                 recursive calling of the Determinant() method). */
             cumulativeSum += this->get(0, j) * subMatrix.determinant() * sign;
             sign = -sign;
         }
         determinant = cumulativeSum;
     }

     return determinant;
 }
// NOT WORKING NEEDS TO BE FIXED
template<typename T>
std::vector<T> MatrixND<T>::characteristicPolynomial() {
    std::vector<T> poly;
    MatrixND<T> adj = this->adjoint();
    MatrixND<T> inv = this->inverse();
    MatrixND<T> adjInv = adj * inv;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            poly.push_back(adjInv.data[i * cols + j]);
        }
    }
    return poly;
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
MatrixND<T> MatrixND<T>::identity(int size) {
    std::vector<T> vec(size*size);
    MatrixND<T> results(vec, size, size);
    for (int i = 0; i < size; i++) {
        results.data[i * size + i] = 1;
    }
    return results;
}

template<typename T>
MatrixND<T> MatrixND<T>::zero() {
    __assert(isSquare(), "Matrix is not square!");
    std::vector<T> vec(rows*cols);
    MatrixND<T> results(vec, rows, cols);
    return results;
}
template<typename T>
MatrixND<T> MatrixND<T>::zero(int rows, int cols) {
    std::vector<T> vec(rows*cols);
    MatrixND<T> results(vec, rows, cols);
    return results;
}

template<typename T>
int MatrixND<T>::rank() {
    // Convert the matrix to row-echelon form.
    MatrixND<T> matrixCopy = this->rref();

    /* If this didn't work, then we compute the rank by finding
        the largest non-zero sub-matrix with a non-zero determinant.

        Note that this method is slower for large matrices and therefore
        it is better to use the RowEchelon method if possible. */
    int numNonZeroRows = 0;
    if (!matrixCopy.isRowEchelon())
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
            if (!currentMatrix.isZero())
            {
                // If the determinant is non-zero, then we have our result.
                T currentMatrixDet = currentMatrix.determinant();
                if (!closeEnough(currentMatrixDet, 0.0))
                {
                    completeFlag = true;
                    numNonZeroRows = currentMatrix.getRows();
                }
                else
                {
                    // Extract and store each sub-matrix (if larger than 2x2).
                    if ((currentMatrix.getRows() > 2) && (currentMatrix.getCols() > 2))
                    {
                        for (int i=0; i<currentMatrix.getRows(); ++i)
                        {
                            for (int j=0; j<currentMatrix.getCols(); ++j)
                            {
                                // Extract this sub-matrix and store.
                                subMatrixVector.push_back(currentMatrix.subMatrix(i,j));
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

        int nRows = matrixCopy.getRows();
        int nCols = matrixCopy.getCols();

        // Loop over each row and test whether it has at least one non-zero element.
        for (int i=0; i<rows; ++i)
        {
            // Loop over the columns of this row.
            int colSum = 0;
            for (int j=0; j<cols; ++j)
            {
                if (!closeEnough(matrixCopy.get(i,j), 0.0))
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
    // Convert the matrix to row-echelon form.
    MatrixND<T> matrixCopy = *this;
    int nRows = matrixCopy.getRows();
    int nCols = matrixCopy.getCols();
    T A[nRows][nCols];
    for (int r = 0; r < nRows; r++)
        for (int c = 0; c < nCols; c++)
            A[r][c] = matrixCopy.get(r,c);

    // Loop over each row and test whether it has at least one non-zero element.
    for (int i=0; i<nRows; ++i)
    {
        int lead = 0;
        while (lead < nRows) {
            float d, m;
            for (int r = 0; r < nRows; r++) { // for each row ...
                /* calculate divisor and multiplier */
                d = A[lead][lead];
                m = A[r][lead] / A[lead][lead];

                for (int c = 0; c < nCols; c++) { // for each column ...
                    if (r == lead)
                        A[r][c] /= d;               // make pivot = 1
                    else
                        A[r][c] -= A[lead][c] * m;  // make other = 0
                }
            }
            lead++;

        }
    }
    MatrixND<T> result(nRows, nCols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // fill the result matrix
            // check if the element is within the tolerance
            if (closeEnough(A[i][j], 0.0))
                result(i,j) = 0.0;
            else
                result(i,j) = A[i][j];

        }
    }
    return result;
}

template<typename T>
bool MatrixND<T>::isRowEchelon() {
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
template<typename T>
MatrixND<T> MatrixND<T>::eigenvectors() {

}
template <typename T>
std::vector<T> MatrixND<T>::eigenvalues() {
    if(rows != cols)
        return std::vector<T>();
    MatrixND<T> A = *this;
    std::vector<T> eigenvalues;
    for(int i = 0; i < rows; i++) {
        eigenvalues.push_back(A.data[i*cols + i]);
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
MatrixND<T> MatrixND<T>::subMatrix(int row, int col) {
    // Create a new matrix to store the sub-matrix.
    // Note that this is one row and one column smaller than the original.
    MatrixND<T> subMatrix(rows-1, cols-1);

    // Loop over the elements of the existing matrix and copy to sub-matrix as appropriate.
    int count = 0;
    for (int i=0; i<rows; ++i)
    {
        for (int j=0; j<cols; ++j)
        {
            // If i or j correspond to rowNum or colNum, then ignore this element.
            if ((i != row) && (j != col))
            {
                // Copy the element to the sub-matrix.
                subMatrix.data[count] = data[i*cols + j];
                count++;
            }
        }
    }

    return subMatrix;
}

template<typename T>
T MatrixND<T>::getAt(int index) {
    if (index < 0 || index >= data.size()) {
        return 0;
    }
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
T MatrixND<T>::get(int row, int col)const
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
int MatrixND<T>::index(int row, int col) const {
    if  (row < 0 || row >= rows || col < 0 || col >= cols) {
        return -1;
    }
    return row*cols + col;
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
T MatrixND<T>::cofactor(int row, int col) {
    MatrixND<T> m(rows-1,cols-1);
    for(int i = 0; i < rows-1; i++) {
        for(int j = 0; j < cols-1; j++) {
            if(i < row && j < col) {
                m(i,j) = this->operator()(i,j);
            }
            else if(i < row && j >= col) {
                m(i,j) = this->operator()(i,j+1);
            }
            else if(i >= row && j < col) {
                m(i,j) = this->operator()(i+1,j);
            }
            else {
                m(i,j) = this->operator()(i+1,j+1);
            }
        }
    }
    return m.determinant()*pow(-1,row+col);
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
int MatrixND<T>::findRowWithMaxElement(int col, int row) {
    T tempValue = data[get(row, col)];
    int rowIndex = row;
    for (int k=row+1; k<rows; ++k)
    {
        if (fabs(data[get(k, col)]) > fabs(tempValue))
        {
            rowIndex = k;
            tempValue = data[get(k, col)];
        }
    }
    return rowIndex;
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
int MatrixND<T>::maxRow() {
    T max = data[0];
    int row = 0;
    for(int i = 0; i < rows*cols; i++) {
        if(data[i] > max) {
            max = data[i];
            row = i/cols;
        }
    }
    return row;
}
template<typename T>
int MatrixND<T>::maxCol() {
    T max = data[0];
    int col = 0;
    for(int i = 0; i < rows*cols; i++) {
        if(data[i] > max) {
            max = data[i];
            col = i%cols;
        }
    }
    return col;
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
int MatrixND<T>::minRow() {
    T min = data[0];
    int row = 0;
    for(int i = 0; i < rows*cols; i++) {
        if(data[i] < min) {
            min = data[i];
            row = i/cols;
        }
    }
    return row;
}
template<typename T>
int MatrixND<T>::minCol() {
    T min = data[0];
    int col = 0;
    for(int i = 0; i < rows*cols; i++) {
        if(data[i] < min) {
            min = data[i];
            col = i%cols;
        }
    }
    return col;
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



