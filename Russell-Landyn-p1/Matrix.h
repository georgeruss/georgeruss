#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;

class Matrix {

public:
    uint rows;
    uint cols;
    double **dynamicArray;

    /**
     * Matrix class constructor used to initialize variables.
     * {@param rows} number of rows in a matrix
     * {@param cols} number of columns in a matrix
     */
    Matrix(uint rows, uint cols);                 // constructor (all elements initialized to 0)

    /**
     * Copy constructor used to copy dynamic arrays.
     * {@param m} Reference variable for a pointer
     */
    Matrix(const Matrix & m);                     // copy constructor

    /**
     * Destructor method that frees up memory.
     */
    ~Matrix();                                    // destructor

    /**
     * This function adds the scalar to the matrix.
     * {@param s} Scalar value
     * {@return Matrix}
     */
    Matrix add(double s) const;                   // add scalar to this matrix

    /**
     * This function adds two matrices.
     * {@param m} reference of matrix to be added by
     * {@return Matrix}
     */
    Matrix add(const Matrix & m) const;           // add this matrix and another matrix

    /**
     * This functions subtracts a matrix by a scalar.
     * {@param s} value of scalar to be subtracted by
     * {@return Matrix}
     */
    Matrix subtract(double s) const;              // subtract scalar from this matrix

    /**
     * This function subtracts a matrix by another matrix.
     * {@param m} reference of matrix to be subtracted by
     *
     * {@return Matrix}
     */
    Matrix subtract(const Matrix & m) const;      // subtract another matrix from this matrix

    /**
     * This function multiplies a matrix by a scalar.
     * {@param s} value of the scalar
     * {@return Matrix}
     */
    Matrix multiply(double s) const;              // multiply this matrix by a scaler

    /**
     * This function multiplies a matrix by another matrix.
     * {@param m} reference of matrix
     * {@return Matrix}
     */
    Matrix multiply(const Matrix & m) const;      // multiply this matrix by another matrix

    /**
     * This function divides a matrix by a scalar.
     * {@param s} value of scalar to be divided by
     * {@return Matrix}
     */
    Matrix divide(double s) const;                // divide this matrix by a scalar

    /**
     * This function tranposes a Matrix.
     * {@return Matrix}
     */
    Matrix t() const;                             // transpose of this matrix

    /**
     * This function returns the number of rs in a matrix.
     * {@return uint}
     */
    const uint numRows() const;                   // returns the number of rows

    /**
     * This function returns the number of columns in a matrix.
     * {@return uint}
     */
    const uint numCols() const;                   // returns the number of cols

    /**
     * This function gets/sets values of a matrix.
     * {@param row} row value to be get/set
     * {@param col} column value to be get/set
     * {@return double}
     */
    double & at(uint row, uint col);              // get/set element at row,col

    /**
     * This function returns a constant value of a matrix.
     * {@param row} row value to be get/set
     * {@param col} column value to be get/set
     * {@return double}
     */
    const double & at (uint row, uint col) const; //get element at rowcol(when using a const object)

}; // Matrix

#endif
