// RationalNumber.cpp
// Implemenation file for RationalNumber.h

#include "RationalNumber.h"

#include <cassert>

RationalNumber::RationalNumber(int pA, int pB) {
   // Initialize to 0=0/1
   num   = pA;
   denom = pB;
}

// I/O

void RationalNumber::read(istream& in) {
   in >> num;  // get a

   // So we can input single numbers (like the eq solver's input)
   if (in.peek() == '/') {
      in.get();     // ignore '/'
      in >> denom;  // get b
   }
}

void RationalNumber::parse(istream& in, ostream& out) {
   bool           hasRhs;
   RationalNumber rhs;
   string         op;

   in >> *this;  // All input starts with a rational number, as per specs.
   in >> op;     // All input then as an op, whether it's X, G, +, etc.

   // Figure out if it's a binary or unary operation
   switch (op[0]) {
         // If it's a unary operator...
      case 'I':
      case 'M':
      case 'R':
      case 'G':
         hasRhs = false;
         break;
      default:
         hasRhs = true;
         break;
   }

   if (hasRhs) {  // BINARY OPERATIONS
      if (op == "X") {
         // Parsing a number of the form (a/b)x+c/d=e/f
         char           dummy;  // For the '+' and '='
         RationalNumber cd, ef;
         in >> dummy >> cd >> dummy >> ef;

         // cout << "DEBUG: Working with: " << *this << " " << cd << " " << ef
         // << flush;

         // Solving on paper, I get:
         // ((e/f)-(c/d))/(a/b)
         // so let's just use that exactly.

         // (ef - cd) / ab, reduced to lowest terms.
         *this = ef.sub(cd).div(*this).reduced();
         out << "X = " << *this;
      } else {  // Normal binary ops.
         in >> rhs;
         // Reducing the arthmetic ops' results, as per instructions.
         if (op == "+")
            *this = add(rhs).reduced();
         else if (op == "-")
            *this = sub(rhs).reduced();
         else if (op == "*")
            *this = mult(rhs).reduced();
         else if (op == "/")
            *this = div(rhs).reduced();
         else if (op == "L")
            setAB(lowestCommonDenominator(rhs), 1);
         else if (op == "<")
            setAB(isLessThan(rhs), 1);
         else if (op == "<=")
            setAB(isLessThanEqual(rhs), 1);
         else if (op == ">")
            setAB(isGreaterThan(rhs), 1);
         else if (op == ">=")
            setAB(isGreaterThanEqual(rhs), 1);
         else if (op == "=")
            setAB(isEqual(rhs), 1);

         out << *this;
      }
   } else {  // Unary operations
      if (op == "M") {
         out << mixedForm();
      } else {
         if (op == "I")
            *this = invert();
         else if (op == "G")
            *this = greatestCommonFactor();
         else if (op == "R")
            *this = reduced();

         out << *this;
      }
   }
}

void RationalNumber::display(std::ostream& out) const {
   if (denom == 1)  // If we're already an integer...
      out << num;
   else
      out << num << "/" << denom;
}


// OPERATIONS
RationalNumber RationalNumber::invert() const {
   return RationalNumber(denom, num);
}

int RationalNumber::greatestCommonFactor() const {
   int gcd = 1;  // assume they have no GCD other than 1
   for (int i = 2; i < max(num, denom); i++) {
      if ((num % i == 0) && (denom % i == 0))  // if both divisible by it...
         gcd = i;                              // ....it must be a divisor.
   }
   return gcd;
}

RationalNumber RationalNumber::reduced() const {
   int gcd = greatestCommonFactor();
   return RationalNumber(num / gcd, denom / gcd);
}

string RationalNumber::mixedForm() const {
   stringstream stream;
   stream << num / denom << " + " << num % denom << "/" << denom;
   return stream.str();
}

RationalNumber RationalNumber::add(const RationalNumber& rhs) const {
   int lcd = lowestCommonDenominator(rhs);
   return RationalNumber((lcd / denom) * num + (lcd / rhs.denom) * rhs.num,
                         lcd);
}

RationalNumber RationalNumber::sub(const RationalNumber& rhs) const {
   return add(rhs.mult(RationalNumber(-1)));  // Addition=sub of opposite.
}

RationalNumber RationalNumber::mult(const RationalNumber& rhs) const {
   return RationalNumber(num * rhs.num, denom * rhs.denom);
}

RationalNumber RationalNumber::div(const RationalNumber& rhs) const {
   return mult(rhs.invert());  // Division is multiplication of the inverted.
}

int RationalNumber::lowestCommonDenominator(const RationalNumber& rhs) const {
   if (denom == rhs.denom) {
      return denom;
   } else {
      RationalNumber temp(denom, rhs.denom);
      // Multiplying 2 numbers together is the same as putting all their
      // factors in a long chain:
      // 4*6 = 2*2*2*3.
      // If you divide that by the largest number they have in common
      // (GCD): 2*2*2*3 / 2 = 2*2*3=12 Gives a number which is the
      // multiplication of everything they don't have in common without
      // everything they do. (the LCD)
      // Or where A,B are sets of the factors: AuB - A(intersection)B
      // (Side note: Huh, discrete actually came in handy)
      int lcd = denom * rhs.denom / temp.greatestCommonFactor();
      return lcd;
   }
}

bool RationalNumber::isLessThan(const RationalNumber& rhs) const {
   return sub(rhs).num < 0;  // if a-b < 0, then b > a
}

bool RationalNumber::isLessThanEqual(const RationalNumber& rhs) const {
   return sub(rhs).num <= 0;  // if a-b == 0, they are equal. See above
}

bool RationalNumber::isGreaterThan(const RationalNumber& rhs) const {
   return sub(rhs).num > 0;  // if a-b > 0, then a > b;
}

bool RationalNumber::isGreaterThanEqual(const RationalNumber& rhs) const {
   return sub(rhs).num >= 0;
}

bool RationalNumber::isEqual(const RationalNumber& rhs) const {
   RationalNumber reducedThis = reduced(), reducedRhs = rhs.reduced();
   return (reducedThis.num == reducedRhs.num) &&
          (reducedThis.denom == reducedRhs.denom);
}

// GETTERS AND SETTERS

int RationalNumber::getNum() const {
   return num;
}

void RationalNumber::setNum(int value) {
   num = value;
}

int RationalNumber::getDenom() const {
   return denom;
}

void RationalNumber::setDenom(int value) {
   if (value != 0) {
      if (value >= 1) {
         denom = value;
      } else {
         num *= -1;
         denom = abs(value);
      }
   } else
      denom = 1;
}

void RationalNumber::setAB(int valueA, int valueB) {
   num   = valueA;
   denom = valueB;
}

ostream& operator<<(ostream& out, const RationalNumber& num) {
   num.display(out);
   return out;
}

istream& operator>>(istream& in, RationalNumber& num) {
   num.read(in);
   return in;
}

RationalNumber operator+(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.add(rhs);
}

RationalNumber operator-(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.sub(rhs);
}

RationalNumber operator*(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.mult(rhs);
}

RationalNumber operator/(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.div(rhs);
}

bool operator<(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.isLessThan(rhs);
}

bool operator<=(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.isLessThanEqual(rhs);
}

bool operator>(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.isGreaterThan(rhs);
}

bool operator>=(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.isGreaterThanEqual(rhs);
}

bool operator==(const RationalNumber& lhs, const RationalNumber& rhs) {
   return lhs.isEqual(rhs);
}
