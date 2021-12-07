#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Matrix.h"

using namespace std;

/**
 * This function prints a line
 * that separates other print statements.
 */
void sep_Func() {
    cout << "_________________________________" << endl;
} // sep_Func

/**
 * Driver method for the Matrix class
 * {@return int}
 */
int main() {

    Matrix a (2, 2);
    a.at(0, 0) = 1.5; // [ 1.5, 2.0 ]
    a.at(0, 1) = 2.0; // [ 1.0, 3.5 ]
    a.at(1, 0) = 1.0;
    a.at(1, 1) = 3.5;

    cout << "Matrix a elements:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "[ " << a.at(0, i) << " ]";
    } // for
    cout << endl;
    for (int i = 0; i < 2; i++) {
        cout << "[ " << a.at(1, i) << " ]";
    }
    cout << endl;

    cout << "\nThere is/are " << a.numRows() << " Row(s) in Matrix a" << endl;
    cout << "There is/are " << a.numCols() << " Column(s) in Matrix a" << endl;

    sep_Func();

    Matrix b(2, 1);
    b.at(0, 0) = 3.5; // [ 3.5 ]
    b.at(1, 0) = 2.0; // [ 2.0 ]

    cout << "\nMatrix b elements:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "[ " << b.at(i, 0) << " ]" << endl;
    } // for
    cout << endl;

    cout << "There is/are " << b.numRows() << " Row(s) in Matrix b" << endl;
    cout << "There is/are " << b.numCols() << " Column(s) in Matrix b" << endl;

    sep_Func();

    Matrix c(2, 2);
    c.at(0,0) = 2.5;
    c.at(0,1) = 3.0;
    c.at(1,0) = 6.3;
    c.at(1,1) = 4.25;

    cout << "\nMatrix c elements:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "[ " << c.at(0, i) << " ]";
    } // for
    cout << endl;
    for (int i = 0; i < 2; i++) {
        cout << "[ " << c.at(1, i) << " ]";
    } // for
    cout << endl;

    cout << "\nThere is/are " << c.numRows() << " Row(s) in Matrix c" << endl;
    cout << "There is/are " << c.numCols() << " Column(s) in Matrix c" << endl;

    sep_Func();

    cout << "\nMatrix a tranposed: " << endl;
    Matrix d(a.t());
    for (int i = 0; i < 2; i++) {
        cout << "[ " << d.at(0, i) << " ]";
    } // for
    cout << endl;
    for (int i = 0; i < 2; i++) {
        cout << "[ " << d.at(1, i) << " ]";
    } // for
    cout << endl;

    sep_Func();

    cout << "\nMatrix a 'plus' by '2.5': " << endl;
    Matrix e(a.add(2.5));
    cout << "[ " << e.at(0,0) << " ]" <<
         "[ " << e.at(0,1) << " ]" << endl;
     cout << "[ " << e.at(1,0) << " ]" <<
        "[ " << e.at(1,1) << " ]" << endl;

    sep_Func();

    cout << "\nMatrix a 'subtracted' by '1.3': " << endl;
    Matrix f(a.subtract(1.3));
    cout << "[ " << f.at(0,0) << " ]" <<
        "[ " << f.at(0,1) << " ]" << endl;
    cout << "[ " << f.at(1,0) << " ]" <<
        "[ " << f.at(1,1) << " ]" << endl;

    sep_Func();

    cout << "\nMatrix a 'divided' by '3': " << endl;
    Matrix g(a.divide(3));
    cout << "[ " << g.at(0,0) << " ]" <<
        "[ " << g.at(0,1) << " ]" << endl;
    cout << "[ " << g.at(1,0) << " ]" <<
        "[ " << g.at(1,1) << " ]" << endl;

    sep_Func();

    cout << "\nMatrix a 'plus' Matrix c:" << endl;
    Matrix h(a.add(c));
    cout << "[ " << h.at(0, 0) << " ]" << "[ " << h.at(0, 1) << " ]" << endl //  4.5, 3
         << "[ " << h.at(1, 0) << " ]" << "[ " << h.at(1, 1) << " ]" << endl; //    3 , 8.5

    sep_Func();

    Matrix i(a.multiply(b));
    cout << "\nMatrix a 'multiplied' by Matrix b: " << endl;
    cout << "[ " << i.at(0, 0) << " ]" << endl  // [ 9.25 ]
         << "[ " << i.at(1, 0) << " ]" << endl; // [ 10.5 ]

    sep_Func();

    cout << "\nMatrix a 'subracted' by Matrix c:" << endl;
    Matrix j(a.subtract(c));
    cout << "[ " << j.at(0, 0) << " ]" << "[ " << j.at(0, 1) << " ]" << endl //  4.5, 3
         << "[ " << j.at(1, 0) << " ]" << "[ " << j.at(1, 1) << " ]" << endl; //    3 , 8.5
    return EXIT_SUCCESS;
} // main
