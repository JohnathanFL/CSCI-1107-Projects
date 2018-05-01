/// \file HashTable.cpp
/// \author Johnathan Lee for CSCI 1107, Lab 13
/// \brief HashTable implementation.


#include "HashTable.h"

HashTable::HashTable(unsigned size) {
   tableSize = size;
   table     = new LinkedList<string>[tableSize];
}

HashTable::~HashTable() {
   for (int i = 0; i < tableSize; i++)
      table[i].~LinkedList();  // Make sure LinkedList destructor is called.

   delete[] table;
   table = NULL;  // Because Visual studio is somehow still in use.
}

void HashTable::insert(string str) {
   int strHash = hash(str);
   table[strHash].insert(str);
}

void HashTable::display(ostream& out) {
   for (int i = 0; i < tableSize; i++) {
      cout << "Index " << i << ": " << table[i] << endl;
   }
}

int HashTable::hash(const string& str) {
   // Max out at 3 characters, otherwise use what's in the string.
   int stopping = (str.length() > 3 ? 3 : str.length());
   int total    = 0;


   for (int i = 0; i < 3; i++)
      total += str[i];

   return total % tableSize;
}
