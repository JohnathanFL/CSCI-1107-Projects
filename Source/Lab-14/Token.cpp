


#include "Token.h"

#include <cassert>

Token::Token(const string &tok, unsigned initialLine) {
  token = tok;
  lineNumbers.enqueue(initialLine);
}

Token::Token(const Token &tok) {
  token = tok.token;
  lineNumbers = tok.lineNumbers;
}

Token &Token::operator=(const Token &rhs) {
  token = rhs.token;
  lineNumbers = rhs.lineNumbers;
  return *this;
}

void Token::display(ostream &out) const {
  out << "( " << token << " on lines " << lineNumbers << " )";
}

Token Token::operator+(Token rhs) {
  Token newToken = *this;
  while (!rhs.lineNumbers.empty()) {
    newToken.lineNumbers.enqueue(rhs.lineNumbers.front());
    rhs.lineNumbers.dequeue();
  }
  return newToken;
}

bool Token::operator<(const Token &rhs) const {
  return this->token < rhs.token;
}

bool Token::operator>(const Token &rhs) const {
  return this->token > rhs.token;
}

bool Token::operator==(const Token &rhs) const {
  return token == rhs.token;
}

const string &Token::getToken() const {
  return token;
}

ostream &operator<<(ostream &out, const Token &t) {
  t.display(out);
  return out;
}
