/// \file HashTable.h
/// \author Johnathan Lee for CSCI 1107, Lab 13
/// \brief Defines a HashTable class which stores strings.

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

#include "LinkedList.h"

/// \class HashTable
/// \brief Stores strings in a hash indexed lookup table.
class HashTable {
  public:
   /// \brief Default constructor
   /// \param size The size of the table to use.
   HashTable(unsigned size = 11);

   /// \brief Destructor
   /// \note Deallocates memory AND explicitly calls LinkedList destructor.
   ~HashTable();

   /// \brief Insert into the HashTable
   /// \param str The string to insert.
   /// \post str Is inserted into the table at the index of its hash.
   void insert(string str);

   /// \brief Display the entire HashTable
   /// \param out The stream to display to.
   /// \post *this is written to out in the format:
   ///  Index <index>: <All items with this hash>
   /// ...
   void display(ostream& out);

  private:
   /// \brief The actual hashing function
   /// \param str The string to hash.
   /// \returns A hash based on the mod of the sum of the first 3 characters and
   /// the table size.
   int hash(const string& str);

   unsigned            tableSize;  ///>! Size of this table. Also used for hash
   LinkedList<string>* table;      ///>! Storage for the elements.
};


#endif
