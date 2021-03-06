#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

/**
 * Matrix class constructor used to initialize variables.
 * {@param rows} number of rows in a matrix
 * {@param cols} number of columns in a matrix
 */
Matrix::Matrix(uint rows, uint cols) {
    this->rows = rows;
    this->cols = cols;

    dynamicArray = new double * [cols];

    for (uint i = 0; i < rows; i++) {
        dynamicArray[i] = new double [cols];
    } // for

    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            dynamicArray[i][j] = 0;
        } // for
    } // for
} // Matrix

/**
 * Copy constructor used to copy dynamic arrays.
 * {@param m} Reference variable for a pointer
 */
Matrix::Matrix(const Matrix &m) {
    this->rows = m.rows;
    this->cols = m.cols;
    this->dynamicArray = new double * [m.rows];

    for (uint i = 0; i < m.rows; i++) {
        this->dynamicArray = new double * [m.cols];
    }

    for (uint i = 0; i < m.rows; i++) {
        for (uint j = 0; j < m.cols; j++) {
            this->dynamicArray[i][j] = m.dynamicArray[i][j];
        }
    }
} // Matrix

/**
 * Destructor function.
 */
Matrix::~Matrix() {
    for (uint i = 0; i < rows; i++) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
} // destructor

/**
 * This function adds the scalar to the matrix.
 * {@param s} Scalar value
 * {@return Matrix}
 */
Matrix Matrix::add(double s) const {
    Matrix temp (this->rows, this->cols);
    for (uint i = 0; i < this->rows; i++) {
        for (uint j = 0; j < this->cols; j++) {
            temp.dynamicArray[i][j] += this->dynamicArray[i][j] + s;
        } // for
    } // for
    return temp;
} // add

/**
 * This function adds two matrices.
 * {@param m} reference of matrix to be added by
 * {@return Matrix}
 */
Matrix Matrix::add(const Matrix & m) const {
    Matrix temp(this->rows,this->cols);
    if (this->rows != m.rows || this->cols != m.cols) {
        for(uint i = 0; i < this->rows; i++) {
            for(uint j=0; j < this->cols; j++) {
                temp.dynamicArray[i][j] = this->dynamicArray[i][j];
            } // for
        } // for
       return temp;
    } else {
        for(uint i = 0; i < this->rows; i++) {
            for(uint j = 0;j < this->cols; j++) {
                temp.dynamicArray[i][j] += m.dynamicArray[i][j] + this->dynamicArray[i][j];
            } // for
        } // for
    } // if
    return temp;
} // add

/**
 * This functions subtracts a matrix by a scalar.
 * {@param s} value of scalar to be subtracted by
 * {@return Matrix}
 */
Matrix Matrix::subtract(double s) const {
     Matrix temp (this->rows, this->cols);
     for(uint i=0;i<this->rows;i++) {
         for(uint j=0;j<this->cols;j++) {
             temp.dynamicArray[i][j] += this->dynamicArray[i][j] - s;
         } // for
     } // for
     return temp;
} // subtract

/**
 * This function subtracts a matrix by another matrix.
 * {@param m} reference of matrix to be subtracted by
 *
 * {@return Matrix}
 */
Matrix Matrix::subtract(const Matrix & m) const {
    Matrix temp (this->rows, this->cols);
    if (this->rows != m.rows || this->cols != m.cols) {
        for(uint i = 0; i < rows; i++) {
            for(uint j = 0; j < cols; j++){
                temp.dynamicArray[i][j] = this->dynamicArray[i][j];
            } // for
        } // for
       return temp;
    } else {
        for(uint i = 0;i < this->rows;i++) {
            for(uint j = 0; j < this->cols; j++) {
                temp.dynamicArray[i][j] += this->dynamicArray[i][j] - m.dynamicArray[i][j];
            } // for
        } // for
    } // if
    return temp;
} // subtract

/**
 * This function multiplies a matrix by a scalar.
 * {@param s} value of the scalar
 * {@return Matrix}
 */
Matrix Matrix::multiply(double s) const {
    Matrix temp (this->rows, this->cols);
    for(uint i = 0; i < this->rows; i++) {
        for(uint j = 0; j < this->cols; j++) {
            temp.dynamicArray[i][j] += this->dynamicArray[i][j] * s;
        } // for
    } // for
    return temp;
} // multiply

/**
 * This function multiplies a matrix by another matrix.
 * {@param m} reference of matrix
 * {@return Matrix}
 */
Matrix Matrix::multiply(const Matrix & m) const {
    Matrix temp(this->cols, m.rows);
    if (this->cols != m.rows) {
        for(uint i = 0;i < rows; i++){
            for(uint j = 0; j < cols; j++){
                temp.dynamicArray[i][j] = this->dynamicArray[i][j];
            } // for
        } // for
      return temp;
    } else {
        for (uint i = 0; i < this->rows; i++) {
            for(uint j = 0; j < m.cols; j++) {
                for(uint k = 0; k < this->cols; k++) {
                    temp.dynamicArray[i][j] += this->dynamicArray[i][k] * m.dynamicArray[k][j];
                } // for
            } // for
        } // for
        return temp;
    } // if
} // divide

/**
 * This function divides a matrix by a scalar.
 * {@param s} value of scalar to be divided by
 * {@return Matrix}
 */
Matrix Matrix::divide(double s) const {
    return multiply(1/s);
} // divide

/**
 * This function tranposes a matrix.
 * {@return Matrix}
 */
Matrix Matrix::t() const {
    Matrix temp (this->cols, this->rows);
    for(uint i = 0; i < this->rows; i++) {
        for(uint j=0; j < this->cols; j++) {
            temp.dynamicArray[j][i] = this->dynamicArray[i][j];
        } // for
    } // for
    return temp;
} // t

/**
 * This function return the number of rows in a matrix.
 * {@return uint}
 */
const uint Matrix::numRows() const {
    return this->rows;
} // numCols

/**
 * This function returns the number of columns in a matrix.
 * {@return uint}
 */
const uint Matrix::numCols() const {
    return this->cols;
} // numCols

/**
 * This function gets/sets values of a matrix.
 * {@param row} row value to be get/set
 * {@param col} column value to be get/set
 * {@return double}
 */
double & Matrix::at (uint row, uint col) {
    double * r = &dynamicArray[row][col];
    return *r;
} // at

/**
 * This function a constant value of a matrix.
 * {@param row} row value to be get/set
 * {@param col} column value to be get/set
 * {@return double}
 */
const double & Matrix::at (uint row, uint col) const {
    return dynamicArray[row][col];
} // at
