#include "MyPolynomial.h"
#include <cmath>
// Constructor
myPolynomial::myPolynomial(int c, unsigned e) {
    if (c != 0)
        terms.push_back(myTerm(c, e));
    degree = e;
}

// Constructor with array of monomials
myPolynomial::myPolynomial(int nTerms, int mono[]) {
    for (int i = 0; i < 2 * nTerms; i += 2) {
        int coeff = mono[i];
        unsigned exp = mono[i + 1];
        if (coeff != 0) {
            terms.push_back(myTerm(coeff, exp));
            if (exp > degree)
                degree = exp;
        }
    }
}
void myPolynomial::addTerm(const myTerm& term) {
    if (term.getCoeff() != 0) {
        terms.push_back(term);
        if (term.getExp() > degree)
            degree = term.getExp();
    }
}
// Copy constructor
myPolynomial::myPolynomial(const myPolynomial& poly) : terms(poly.terms), degree(poly.degree) {}

// Overloaded operators
bool myPolynomial::operator==(const myPolynomial& poly) const {
    return terms == poly.terms;
}

bool myPolynomial::operator!=(const myPolynomial& poly) const {
    return !(*this == poly);
}

myPolynomial& myPolynomial::operator+=(const myPolynomial& poly) {
    for (const auto& term : poly.terms)
        addTerm(term);
    return *this;
}

myPolynomial& myPolynomial::operator-=(const myPolynomial& poly) {
    for (const auto& term : poly.terms)
        addTerm(-term);
    return *this;
}

myPolynomial& myPolynomial::operator*=(const myPolynomial& poly) {
    *this = *this * poly;
    return *this;
}

myPolynomial& myPolynomial::operator*=(int k) {
    for (auto& term : terms)
        term.setCoeff(term.getCoeff() * k);
    return *this;
}

myPolynomial myPolynomial::operator-() const {
    myPolynomial result(*this);
    for (auto& term : result.terms)
        term.setCoeff(-term.getCoeff());
    return result;
}

myPolynomial myPolynomial::operator*(int k) const {
    myPolynomial result(*this);
    result *= k;
    return result;
}

myPolynomial myPolynomial::operator+(const myPolynomial& poly) const {
    myPolynomial result(*this);
    result += poly;
    return result;
}

myPolynomial myPolynomial::operator-(const myPolynomial& poly) const {
    myPolynomial result(*this);
    result -= poly;
    return result;
}

myPolynomial myPolynomial::operator*(const myPolynomial& poly) const {
    myPolynomial result;
    for (const auto& term1 : terms) {
        for (const auto& term2 : poly.terms) {
            myTerm newTerm = term1 * term2;
            result.addTerm(newTerm);
        }
    }
    return result;
}

long myPolynomial::operator()(int x) const {
    long result = 0;
    for (const auto& term : terms)
        result += term.getCoeff() * pow(x, term.getExp());
    return result;
}

int myPolynomial::getDegree() const {
    return degree;
}

unsigned myPolynomial::getNumTerms() const {
    return terms.size();
}

myPolynomial myPolynomial::ddx() const {
    myPolynomial result;
    for (const auto& term : terms) {
        myTerm ddxTerm = term.ddx();
        if (ddxTerm.getCoeff() != 0)
            result.addTerm(ddxTerm);
    }
    return result;
}

// Friend operators and functions
myPolynomial operator*(int k, const myPolynomial& poly) {
    return poly * k;
}
ostream& operator <<(ostream &outStream, const myPolynomial& poly) {
    if (poly == myPolynomial::ZERO)
        return outStream << 0;
    bool firstTerm = true;
    for (const auto& term : poly.terms) {
        if (term == myTerm(0, 0))
            continue;

        if (!firstTerm && term.getCoeff() > 0)
            outStream << "+";

        outStream << term;

        firstTerm = false;
    }
    return outStream;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x