#include "MyComplex.h"

    myComplex::myComplex(int real, int imag) {
        realPart = real;
        imaginaryPart = imag;
    }
    // Copy constructor
    myComplex::myComplex(const myComplex& number) {
        realPart = number.getrealPart;
        imaginaryPart = number.getimaginaryPart;
    }
    // Accessor functions
    int getRealPart() const {
        return realPart;
    }
    int getImaginaryPart() const {
        return imaginaryPart;
    }
    // Mutator functions
    void setRealPart(int real) {
        realPart = real;
    }
    void set(int real, int imag){
        realPart = real;
        imaginaryPart = imag;
    }
    myComplex myComplex::operator+(const myComplex& other) const {
        return myComplex(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }
    myComplex operator +(int value) const {
        return myComplex(realPart + value, imaginaryPart);
    }

    myComplex myComplex::operator-(const myComplex& other) const {
        return myComplex(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }
    myComplex operator -(int value) {
        return myComplex(realPart-value, imaginaryPart);
    }
    myComplex operator *(const myComplex &number) {
        int a = realPart, b = imaginaryPart, c = number.getRealPart(), d = number.getImaginaryPart();
        return myComplex(a*c-b*d, a*d+b*c);
    }
    myComplex operator *(int value) {
        return myComplex(value * realPart, value * imaginaryPart);
    }

    // Overloaded assignment operators
    myComplex& operator =(const myComplex& number) {
        this->realPart = number.getRealPart();
        this->imaginaryPart = number.getImaginaryPart();
        return *this;
    }
    myComplex& operator +=(const myComplex &number) {
        *this = *this + number;
        return *this;
    }
    myComplex& operator +=(int value) {
        *this = *this + value;
        return *this;
    }
    myComplex& operator -=(const myComplex &number) {
        *this = *this - number;
        return *this;
    }
    myComplex& operator -=(int value) {
        *this = *this - value;
        return *this;
    }
    myComplex& operator *=(const myComplex &number) {
        *this = *this * number;
        return *this;
    }
    myComplex& operator *=(int value) {
        *this = *this * value;
        return *this;
    }

    // Overloading relational operators
    bool operator ==(const myComplex &number) const {
        return (realPart == number.getRealPart()) && (imaginaryPart == number.getImaginaryPart());
    }
    bool operator !=(const myComplex &number) const {
        return !(*this == number);
    }
    bool operator >(const myComplex &number) const {
        return norm2() > number.norm2();
    }
    bool operator >=(const myComplex &number) const {
        return norm2() >= number.norm2();
    }
    bool operator <(const myComplex &number) const {
        return norm2() < number.norm2();
    }
    bool operator <=(const myComplex &number) const {
        return norm2() <= number.norm2();
    }
    // Overloaded unary operators
    myComplex operator -() {
        return myComplex(-realPart, -imaginaryPart);
    }
    myComplex operator ~() {
        return myComplex(realPart, -imaginaryPart);
    }
    myComplex& operator ++() {
        realPart += 1;
        return *this;
    }
    myComplex operator ++(int) {
        myComplex ret(realPart, imaginaryPart);
        ++(*this);
        return ret;
    }
    myComplex& operator --() {
        realPart -= 1;
        return *this;
    }
    myComplex operator --(int) {
        myComplex ret(realPart, imaginaryPart);
        --(*this);
        return ret;
    }
    
    int norm2() const {
        return realPart * realPart + imaginaryPart * imaginaryPart;
    }