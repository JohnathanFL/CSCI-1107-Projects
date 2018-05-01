/* RationalNumber.h
 * Defines a class RationalNumber and its functions/operators.
 * Johnathan Lee     CSCI 1107
 * Due 03/06/18
 */
#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

/// \class RationalNumber
/// \brief A class for handling rational numbers of the form a/b, where a and b
/// are integers and b is non-zero.
class RationalNumber {
  public:
   /// \brief Explicit and default constructor for RationalNumber
   /// \post *this has been constructed with either pA and pB for numerator and
   /// denominator
   RationalNumber(int pA = 0, int pB = 1);


   /// \brief Reads in a RationalNumber from in
   /// \param in Stream to read from
   /// \post *this is set to the input.
   /// \note Input is in the form of either a/b OR simply a, which becomes a/1.
   void read(istream& in);  // For a single rational number

   /// \brief Parses an equation from in, sets this to result, and prints
   /// result.
   ///
   /// \param in Stream to read from.
   /// \param out Stream to send result to.
   /// \post *this has been set to the result of the operation, *this has been
   /// sent to out.
   /// \note Supported operators:
   /// Binary: + - * / < <= > >= = L
   /// Unary: I M R G
   /// Expression: a/bX + c/d = e/f (Solves for X)
   void parse(istream& in,
              ostream& out);  // For a full equation with operations

   /// \brief Outputs *this to out.
   /// \param out Stream to display to.
   /// \post *this Has been written to out in one of the following forms:
   ///            a/b, if b != 1
   ///            a, if b == 1
   void display(ostream& out) const;  // Write to output.

   // Unary operations
   /// \brief Inverts *this from a/b to b/a and returns it.
   RationalNumber invert() const;
   /// \brief Finds the greatest common factor of this->num and this->denom and
   /// returns it.
   int greatestCommonFactor() const;

   /// \brief Reduces *this. (i.e 2/4->1/2, 4/2->2/1, etc)
   /// \note Worth noting that this internally calls
   /// this->greatestCommonFactor().
   RationalNumber reduced() const;

   /// \brief Returns a string which represents this as a mixed form, in the
   /// form m + a/b. (i.e 5/2 -> 2 + 1/2)
   string mixedForm() const;

   // Binary operations
   /// \brief Adds *this to rhs and returns the result.
   /// \param rhs The right-hand-side of the equation lhs + rhs.
   RationalNumber add(const RationalNumber& rhs) const;
   /// \brief Subtracts rhs from *this and returns the result.
   /// \param rhs The right-hand-side of the equation lhs - rhs.
   /// \note Internally calls add for addition of the opposite.
   RationalNumber sub(const RationalNumber& rhs) const;
   /// \brief Multiplies *this by rhs and returns the result.
   /// \param rhs The right hand side of the equation lhs * rhs.
   RationalNumber mult(const RationalNumber& rhs) const;
   /// \brief Divides *this by rhs and returns the result.
   /// \param rhs The right hand side of the equation lhs / rhs.
   /// \note Internally calls mult on rhs.invert()
   RationalNumber div(const RationalNumber& rhs) const;
   /// \brief Finds the lowest common denominator of *this and rhs
   /// \param rhs The other number to find the LCD for.
   /// \returns The lowest common denominator of lhs and rhs.
   int lowestCommonDenominator(const RationalNumber& rhs) const;

   // Relational Operations
   /// \brief Less than comparison
   /// \returns a/b < c/d, where a/b and c/d are *this and rhs in reduced form
   /// with a common denominator.
   bool isLessThan(const RationalNumber& rhs) const;
   /// \brief Less than or equal to comparison
   /// \returns a/b <= c/d, where a/b and c/d are *this and rhs in reduced form
   /// with a common denominator.
   bool isLessThanEqual(const RationalNumber& rhs) const;
   /// \brief Greater than comparison
   /// \returns a/b > c/d, where a/b and c/d are *this and rhs in reduced form
   /// with a common denominator.
   bool isGreaterThan(const RationalNumber& rhs) const;
   /// \brief Greater than or equal to comparison
   /// \returns a/b >= c/d, where a/b and c/d are *this and rhs in reduced form
   /// with a common denominator.
   bool isGreaterThanEqual(const RationalNumber& rhs) const;

   /// \brief Equivalence comparison
   /// \returns Whether the reduced form of *this is equal to the reduced form
   /// of rhs. Note: Does a direct comparison of reducedThis and reducedRhs
   /// member variables.
   bool isEqual(const RationalNumber& rhs) const;


   /// \brief Getter for this->num
   int getNum() const;
   /// \brief Setter for this->num
   /// \param value The new value for a
   /// \post this->num = value
   void setNum(int value);

   /// \brief Getter for this->denom
   int getDenom() const;
   /// \brief Setter for this->denom
   /// \param value The new value for b
   /// \post this->denom = value. If value == 0, then b is set to 1. If b < 0,
   /// then a has its sign flipped.
   void setDenom(int value);

   /// \brief Convenience setter for both numerator and denominator
   /// \param valueA The new value for this->num
   /// \param valueB The new value for this->denom
   /// \post this->num = valueA and this->denom = valueB.
   void setAB(int valueA, int valueB);

  private:
   int num,    ///< The numerator of the fraction
       denom;  ///< The denominator of the fraction.
};

//---------->RationalNumber Operators

// IO
/// \brief Reads into a RationalNumber
/// \param in The stream to read from
/// \param num The number to store in.
/// \post num.read(in) has been called.
istream& operator>>(istream& in, RationalNumber& num);
/// \brief Writes out a RationalNumber
/// \param out The stream to write to.
/// \param num The number to read from.
/// \post num.display(out) has been called.
ostream& operator<<(ostream& out, const RationalNumber& num);


// Arithmetic
// NOTE: These are all nothing but wrappers for RationalNumber methods.

/// \brief Calls lhs.add(rhs)
RationalNumber operator+(const RationalNumber& lhs, const RationalNumber& rhs);
/// \brief Calls lhs.sub(rhs)
RationalNumber operator-(const RationalNumber& lhs, const RationalNumber& rhs);
/// \brief Calls lhs.mult(rhs)
RationalNumber operator*(const RationalNumber& lhs, const RationalNumber& rhs);
/// \brief Calls lhs.div(rhs)
RationalNumber operator/(const RationalNumber& lhs, const RationalNumber& rhs);

// Relational
/// \brief Calls lhs.isLessThan(rhs)
bool operator<(const RationalNumber& lhs, const RationalNumber& rhs);
/// \brief Calls lhs.isLessThanEqual(rhs)
bool operator<=(const RationalNumber& lhs, const RationalNumber& rhs);
/// \brief Calls lhs.isGreaterThan(rhs)
bool operator>(const RationalNumber& lhs, const RationalNumber& rhs);
/// \brief Calls lhs.isGreaterThanEqual(rhs)
bool operator>=(const RationalNumber& lhs, const RationalNumber& rhs);
/// \brief Calls lhs.isEqual(rhs)
bool operator==(const RationalNumber& lhs, const RationalNumber& rhs);

#endif
