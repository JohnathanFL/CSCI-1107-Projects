/// \file Token.cpp
/// \brief Defines a Token class
/// \author Johnathan Lee
/// \date Due 05/04/18

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "circq.h"

/// \class Token
/// \brief A token class. Holds a string and a list of all lines it is seen on.
class Token {
  public:
   /// \brief Explicit constructor
   /// \param tok The token to use
   /// \param initialLine The line that will be first in lineNumbers.
   /// \note Do not use as implicit constructor. This is just to make the
   /// compiler happy.
   Token(const string& tok = "", unsigned initialLine = -1);

   /// \brief Copy constructor
   /// \param tok The Token to copy from.
   Token(const Token& tok);

   /// \brief Assignment operator for token
   /// \param rhs The token to assign from.
   /// \returns a reference to *this;
   Token& operator=(const Token& rhs);

   /// \brief Print *this to an ostream
   /// \param out The ostream to write to.
   /// \post *this has been written to out in the following format:
   /// (##TOKEN## on lines ##EACH LINE NUMBER##)
   /// \note See CircularQ->display for each line number.
   void display(ostream& out) const;

   /// \brief Concatenate the line numbers in this Token with those of another.
   /// \param rhs The token to take numbers from.
   /// \returns A token containing all the line numbers from *this, followed by
   /// all the line numbers from rhs. (Skipping duplicate lines)
   /// \note Pass by value to avoid making another temp variable.
   Token operator+(Token rhs);

   /// \brief Less than operator
   /// \param rhs Other token to compare
   /// \returns Whether this->token < rhs.token.
   bool operator<(const Token& rhs) const;

   /// \brief Greater than operator
   /// \param rhs Other token to compare
   /// \returns Whether this->token > rhs.token.
   bool operator>(const Token& rhs) const;


   /// \brief Equality operator
   /// \param rhs Other token to compare
   /// \returns Whether this->token == rhs.token.
   bool operator==(const Token& rhs) const;

   /// \brief Gets the token from this instance.
   /// \returns A const ref to the token.
   /// \note const ref to avoid copying large strings.
   const string& getToken() const;

  private:
   string              token;        ///>! The token we have.
   CircularQ<unsigned> lineNumbers;  ///>! All lines this token was found on.
};

/// \brief Stream insertion operator for Token
/// \param out The stream to write to
/// \param t The token to display
/// \post t.display has been called on out.
ostream& operator<<(ostream& out, const Token& t);

#endif
