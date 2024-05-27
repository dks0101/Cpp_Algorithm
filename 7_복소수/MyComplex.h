#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>
#include <cmath>
using namespace std;

class myComplex {
private:
    int realPart;
    int imaginaryPart;
    int norm() const {
        return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
    }
public:
    myComplex(int real=0, int imag =0); // Constructor with parameters
    myComplex(const myComplex& other); // Copy constructor

    int getRealPart() const; // Accessor function for real part
    int getImaginaryPart() const; // Accessor function for imaginary part

    void setRealPart(int real); // Mutator function for real part
    void setImaginaryPart(int imag); // Mutator function for imaginary part
    void set(int real, int imag);
    // Arithmetic operators
    myComplex operator+(const myComplex& other) const;
    myComplex operator-(const myComplex& other) const;
    myComplex operator*(const myComplex& other) const;
    myComplex operator+(int value) const;
    myComplex operator-(int value) const;
    myComplex operator*(int value) const;

    // Assignment operators
    myComplex& operator=(const myComplex& other);
    myComplex& operator+=(const myComplex& other);
    myComplex& operator-=(const myComplex& other);
    myComplex& operator*=(const myComplex& other);
    myComplex& operator=(int value);
    myComplex& operator+=(int value);
    myComplex& operator-=(int value);
    myComplex& operator*=(int value);

    // Relational operators
    bool operator==(const myComplex& other) const;
    bool operator!=(const myComplex& other) const;
    bool operator>(const myComplex& other) const;
    bool operator>=(const myComplex& other) const;
    bool operator<(const myComplex& other) const;
    bool operator<=(const myComplex& other) const;

    // Unary operators
    myComplex operator-() const;
    myComplex operator~() const;
    myComplex& operator++(); // Prefix increment
    myComplex operator++(int); // Postfix increment
    myComplex& operator--(); // Prefix decrement
    myComplex operator--(int); // Postfix decrement

    // Friend functions for input/output
    friend std::ostream& operator<<(std::ostream& os, const myComplex& complex);
    friend std::istream& operator>>(std::istream& is, myComplex& complex);

    // Other member functions
    myComplex conjugate() const;
    double norm() const;
};

#endif  // MYCOMPLEX_H
