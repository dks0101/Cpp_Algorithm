#include <iostream>
#include <list>
#include <cmath>
using namespace std;
class myPolynomial;
class myTerm {
public:
    myTerm(int c = 0, unsigned e = 0);
    // copy constructor
    myTerm(const myTerm &term);
    // overloaded operators
    bool operator == (const myTerm& term) const;
    bool operator != (const myTerm& term) const;
    bool operator < (const myTerm& term) const;
    myTerm operator - () const;
    // accessor functions
    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }
    // mutator functions
    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }
    // member functions
    myTerm ddx() const; // derivative of a term
    // friend functions and classes
    friend ostream& operator <<(ostream &outStream, const myTerm& term);
    friend myPolynomial;
    myTerm operator*(const myTerm& term) const {
        int newCoeff = coeff * term.coeff;
        unsigned newExp = exp + term.exp;
        return myTerm(newCoeff, newExp);
    }
private:
    int coeff; // integer coefficient
    unsigned exp; // exponent (non-negative integer)
};

myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e) {}
// copy constructor
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp) {}
// overloaded operators
bool myTerm::operator == (const myTerm& term) const{
    return (coeff==term.coeff) && (exp==term.exp);
}
// overloaded operators
bool myTerm::operator != (const myTerm& term) const {
    return !(*this == term);
}
// overloaded operators
bool myTerm::operator < (const myTerm& term) const {
    return exp > term.exp;
}
myTerm myTerm::operator - () const {
    return myTerm(-coeff, exp);
}
// derivative of a term
myTerm myTerm::ddx() const {
    if (exp == 0)
        return myTerm(0, 0);
    return myTerm(exp*coeff, exp-1);
}
// output operator
ostream& operator <<(ostream &outStream, const myTerm& term) {
    if (term.exp == 0)
        if (term.coeff == 0) // nothing to output
            return outStream;
        else
            return outStream << term.coeff;

    if (term.coeff == 1)
        outStream << "x";
    else if (term.coeff == -1)
        outStream << "-x";
    else
        outStream << term.coeff << "x";
    if (term.exp == 1)
        return outStream;
    else
        return outStream << "^" << term.exp;
}

class myPolynomial {
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    // copy constructor
    myPolynomial(const myPolynomial &poly);
    // overloaded operators
    bool operator == (const myPolynomial &poly) const;
    bool operator != (const myPolynomial &poly) const;
    myPolynomial& operator += (const myPolynomial &poly);
    myPolynomial& operator -= (const myPolynomial &poly);
    myPolynomial& operator *= (const myPolynomial &poly);
    myPolynomial& operator *= (int k);
    myPolynomial operator -() const;
    myPolynomial operator *(int k) const;
    myPolynomial operator +(const myPolynomial &poly) const;
    myPolynomial operator -(const myPolynomial &poly) const;
    myPolynomial operator *(const myPolynomial &poly) const;
    void addTerm(const myTerm& term);
    long operator() (int x) const; // evaluate the polynomial
    int getDegree() const; // get a degree of the polynomial
    unsigned getNumTerms() const; // number of terms in the polynomial
    myPolynomial ddx() const; // derivative of a polynomial
    // friend operators and functions
    friend myPolynomial operator *(int k, const myPolynomial &poly);
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE; // P(x) = 1
    static const myPolynomial X; // P(x) = x
private:
    int degree; // maximum expnent
    list<myTerm> terms; // list of terms
};

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
    for (int i=1;i<poly.terms;++i) {
        if (poly.termArray[i].getCoeff() > 0) cout << "+";
        cout << poly.termArray[i];
    }
    return outStream;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);

void testSimpleCase();
void testDataFromFile();
int main() {
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase() {
    // test static variables
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;
    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
    int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1,100, 1, 0};
    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);
    // test constructor
    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;
    // test copy constructor
    cout << p9 << endl;
    // test accessor function
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
    // test evaluation function
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
    // test comparison operators
    cout << (p7 == p9) << " " << (p7 != p9) << endl;
    // test derivative function
    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;
    // test unary operator -
    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;
    // test k*p(x) or p(x) * k
    cout << 3*myPolynomial::ZERO << endl;
    cout << 3*myPolynomial::ONE << endl;
    cout << myPolynomial::X*3 << endl;
    cout << 3*p4 << " " << p4*3 << endl;
    cout << 0*p5 << " " << p5*5 << endl;

    // test binary operator +
    cout << p4 + p5 << " " << p4 + p6 << endl;
    cout << p4 + p8 << " " << p8 + p8 << endl;
    // test binary operator -
    cout << p4 - p5 << " " << p4 - p6 << endl;
    cout << p4 - p8 << " " << p8 - p8 << endl;
    // test binary operator *
    cout << p4 * p5 << " " << p4 * p6 << endl;
    cout << p4 * p8 << " " << p8 * p8 << endl;

    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp1 += p5) << endl;
    cout << (tmp2 -= p5) << endl;
    cout << (tmp3 *= p5) << endl;
    cout << (tmp4 *= 3) << endl;
    int t;
    cin >> t;
}
void testDataFromFile() {
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++){
        int numTerms, terms[100];
        /* read first polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
        cin >> terms[2*j] >> terms[2*j+1];
        myPolynomial p1(numTerms, terms);
        /* read second polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
            cin >> terms[2*j] >> terms[2*j+1];
        myPolynomial p2(numTerms, terms);
        cout << p1 << endl << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE),p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;
        cout << p5 << endl;
    }
}