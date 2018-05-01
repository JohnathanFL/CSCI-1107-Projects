/* complex.h
 * Defines a class Complex.
 * Johnathan Lee     CSCI 1107
 * Due 03/06/18
 */
#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>
#include <iostream>

using namespace std;

/// \class Complex
/// \brief A class for handling Complex numbers.
class Complex {
  public:
   /// \brief Default/explicit combo. Initializes to 0+0i by default
   /// \param inReal number to initialize this->real to.
   /// \param inImagi number to initialize this->imagi to.
   Complex(double inReal  = 0,
           double inImagi = 0);  // Construct from doubles (Default)

   /// \brief Displays the Complex number to the out stream.
   /// \param out The stream to display to.
   /// \post This number is printed to the stream in 1 of the 2 formats:
   ///       <real>+<imagi>i, if imagi is pos, and
   ///       <real>-<imagi>i, if imagi is neg.
   void display(ostream& out) const;

   /// \brief Reads a complex number from an input stream
   /// \post *this has been replaced by whatever is next in the stream.
   void read(istream& in);

   /// \brief Adds *this to another Complex.
   /// \param rhs The right hand side
   /// \returns *this + rhs, following rules for complex arithmetic.
   Complex add(const Complex& rhs) const;
   /// \brief Subtracts rhs from *this.
   /// \param rhs The right hand side
   /// \returns *this - rhs.
   Complex subtract(const Complex& rhs) const;
   /// \brief Multiplies *this by another complex
   /// \param rhs The right hand side
   /// \returns *this * rhs, following rules for complex arithmetic.
   Complex mult(const Complex& rhs) const;
   /// \brief Divides *this by another Complex.
   /// \param rhs The right hand side
   /// \returns *this / rhs, following rules for complex arithmetic.
   Complex div(const Complex& rhs) const;

   /// \brief Returns whether this is equal to another Complex.
   /// \param rhs The Complex to compare ourselves with.
   /// \returns this->real == rhs.real && this->imagi == rhs.imagi.
   bool isEqual(const Complex& rhs) const;

   /// \brief Getter for this->real
   double getReal() const;
   /// \brief Getter for this->imagi
   double getImagi() const;

   /// \brief Setter for this->real
   /// \note Sets directly, no special rules.
   void setReal(double newReal);
   /// \brief Setter for this->imagi
   /// \note Sets directly, no special rules.
   void setImagi(double newImagi);

  private:
   double real,  ///> The real part of a+bi (a)
       imagi;    ///> The imaginary part of a+bi (b)
};

// OVERLOADS OF FUNCTIONS FOR COMPLEX

/// \brief Overload of absolute value function for Complex numbers.
/// \param com The number to take an absolute value of.
/// \returns The absolute value of com, following rules of complex arithmetic.
Complex abs(const Complex& com);


// COMPLEX OPERATORS

// Note: These all directly call the equivalent functions in lhs, passing in rhs
// as a param.
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
bool    operator==(const Complex& lhs, const Complex& rhs);

/// \brief Reads in a complex number from in to com
/// \note Simply calls com.read(in)
istream& operator>>(istream& in, Complex& com);
/// \brief Displays a complex number com to a stream out.
/// \note Simply calls com.display(out)
ostream& operator<<(ostream& out, const Complex& com);
#endif
