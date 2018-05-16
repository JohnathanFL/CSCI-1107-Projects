/// \file Token.cpp
/// \brief Implementation for Token.h
/// \author Johnathan Lee
/// \date Due 05/04/18

#include "Token.h"
#include "BST.h"

#include <cassert>

Token::Token(const string& tok, unsigned initialLine) {
   token = tok;
   lineNumbers.enqueue(initialLine);
}

Token::Token(const Token& tok) {
   token       = tok.token;
   lineNumbers = tok.lineNumbers;
}

Token& Token::operator=(const Token& rhs) {
   token       = rhs.token;
   lineNumbers = rhs.lineNumbers;
   return *this;
}

void Token::display(ostream& out) const {
   out << "( " << token << " on lines " << lineNumbers << " )";
}

Token Token::operator+(Token rhs) {
   Token newToken = *this;
   while (!rhs.lineNumbers.empty()) {
      newToken.lineNumbers.enqueueIfUnique(rhs.lineNumbers.front());
      rhs.lineNumbers.dequeue();
   }
   return newToken;
}

bool Token::operator<(const Token& rhs) const {
   return this->token < rhs.token;
}

bool Token::operator>(const Token& rhs) const {
   return this->token > rhs.token;
}

bool Token::operator==(const Token& rhs) const {
   return token == rhs.token;
}

const string& Token::getToken() const {
   return token;
}

ostream& operator<<(ostream& out, const Token& t) {
   t.display(out);
   return out;
}

template <>
void BST<Token>::insert(const Token& word) {
   BinNodePointer locptr = myRoot,  // search pointer
       parent            = NULL;    // pointer to parent of current node
   bool found            = false;   // indicates if item already in BST
   while (!found && locptr != NULL) {
      parent = locptr;

      if (word < locptr->data)  // descend left
         locptr = locptr->left;
      else if (locptr->data < word)  // descend right
         locptr = locptr->right;
      else  // item found
         found = true;
   }
   if (!found) {  // construct node containing item
      locptr = new (nothrow) BinNode(word);
      if (locptr == NULL) {
         cerr << "*** Out of memory -- terminating program ***\n";
         exit(1);
      }

      if (parent == NULL)  // empty tree
         myRoot = locptr;
      else if (word < parent->data)  // insert to left of parent
         parent->left = locptr;
      else  // insert to right of parent
         parent->right = locptr;
   } else
      locptr->data = locptr->data + word;
}
