#ifndef TOKEN_H
#define TOKEN_H


#include <string>

#include "circq.h"

// Made into a template for greater reuse.
class Token {
  public:
   Token(const string& tok, int initialLine) {
      token = tok;
      lineNumbers.enqueue(initialLine);
   }
   Token(const Token& tok) {
      token       = tok.token;
      lineNumbers = tok.lineNumbers;
   }
   ~Token() {
      token.~string();
      lineNumbers.~CircularQ();
   }

   void addLine(int num) {
      lineNumbers.enqueue(num);
   }

   void display(ostream& out) const {
      out << "( " << token << " on lines " << lineNumbers << " )";
   }

   Token operator+(Token rhs) {
      Token newToken = *this;
      while (!rhs.lineNumbers.empty()) {
         newToken.lineNumbers.enqueue(rhs.lineNumbers.front());
         rhs.lineNumbers.dequeue();
      }
      return newToken;
   }
   bool operator<(const Token& rhs) const {
      return this->token < rhs.token;
   }
   bool operator>(const Token& rhs) const {
      return this->token > rhs.token;
   }

   const string& getToken() const {
      return token;
   }

  private:
   string         token;
   CircularQ<int> lineNumbers;
};


ostream& operator<<(ostream& out, const Token& t) {
   t.display(out);
   return out;
}

#endif
