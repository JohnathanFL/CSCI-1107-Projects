// complex.cpp
// Implemenation file for complex.h
#include "complex.h"

// DEFAULT AND EXPLICIT CONSTRUCTOR
Complex::Complex(double inReal, double inImagi) {
   real  = inReal;
   imagi = inImagi;
}

// IO FUNCS

void Complex::display(ostream& out) const {
   out << real << (imagi >= 0 ? "+" : "") << imagi << "i";
}

void Complex::read(istream& in) {
   char dummy;
   // a+bi, put a/b into real/imagi
   in >> real >> dummy >> imagi;

   // Assuming no spaces, a simple in>>real>>imagi>>dummy would work,
   // but if they enter as a - bi, it would fail and give a + 0i, so check sign.
   if (dummy == '-')
      imagi *= -1;

   // Consume i
   in >> dummy;
}

//*****************************************************************************
// NOTE: IN THE COMMENTS FOR EACH OF THESE, A and C REFER TO THE LHS AND RHS
// REAL PARTS, WHILE B AND D REFER TO THE LHS AND RHS IMAGI PARTS.
//*****************************************************************************


// OPERATOR FUNCS

Complex Complex::add(const Complex& rhs) const {
   // (a+c)+(b+d)i
   return Complex(real + rhs.real, imagi + rhs.imagi);
}

Complex Complex::subtract(const Complex& rhs) const {
   return add(rhs.mult(-1));  // Addition is subtraction of opposite.
}

Complex Complex::mult(const Complex& rhs) const {
   // (ac - bd) + (bc + ad)i
   return Complex(real * rhs.real - imagi * rhs.imagi,
                  imagi * rhs.real + real * rhs.imagi);
}

Complex Complex::div(const Complex& rhs) const {
   double newReal, newImagi,  // You know it's getting serious when we split
                              // this into variables first.
       denom =
           (pow(rhs.real, 2) + pow(rhs.imagi, 2));  // Since they're the same.
   // (ac+bd)/(c^2+d^2)
   newReal  = (real * rhs.real + imagi * rhs.imagi) / denom;
   newImagi = (imagi * rhs.real - real * rhs.imagi) / denom;
   return Complex(newReal, newImagi);
}

bool Complex::isEqual(const Complex& rhs) const {
   return (real == rhs.real) && (imagi == rhs.imagi);
}

// GETTERS AND SETTERS

double Complex::getReal() const {
   return real;
}

double Complex::getImagi() const {
   return imagi;
}

void Complex::setReal(double newReal) {
   real = newReal;
}

void Complex::setImagi(double newImagi) {
   imagi = newImagi;
}

// NON MEMBER FUNCS

// No idea why this would be a non member func....
Complex abs(const Complex& com) {
   return sqrt(pow(com.getReal(), 2) + pow(com.getImagi(), 2));
}

// OPERATORS

Complex operator+(const Complex& lhs, const Complex& rhs) {
   return lhs.add(rhs);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
   return lhs.subtract(rhs);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
   return lhs.mult(rhs);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
   return lhs.div(rhs);
}

bool operator==(const Complex& lhs, const Complex& rhs) {
   return lhs.isEqual(rhs);
}

istream& operator>>(istream& in, Complex& com) {
   com.read(in);
   return in;
}

ostream& operator<<(ostream& out, const Complex& com) {
   com.display(out);
   return out;
}
