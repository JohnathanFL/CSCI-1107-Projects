/*--- linktester.cpp --------------------------------------------------
  A program for testing class LinkedList.

  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                    Lab #5.1 and Projects 5.1

   Johnathan Lee         CSCI 1107
   Due 03/20/18

  ---------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "LinkedList.h"

//*---- PART 6 ---- TEST COPY CONSTRUCTOR

void f(LinkedList aList)  // LinkedList value parameter
{                         // to test the copy constructor
   for (int i = 1; i < 5; i++)
      aList.insert(100 * i);  // insert into the copy


   cout << aList << endl;  // output the copy
}
//---- END PART 6 ----*/

int main() {
   LinkedList intList;  // TEST THE CONSTRUCTOR
   cout << "Constructing intList\n";

   //* ---- PART 1 ---- TEST SIZE OPERATION

   cout << "Size of intList is " << intList.size() << endl;

   /*---- END PART 1 ----*/


   //* ---- PART 2A ---- TEST OUTPUT OF EMPTY LIST USING display()

   cout << "Empty List (using display): \n";
   intList.display(cout);
   cout << endl;

   //---- END PART 2A ----*/

   //* ---- PART 2B ---- TEST OUTPUT OF EMPTY LIST USING <<

   cout << "Empty List (using <<): \n" << intList << endl;

   //---- END PART 2B ----*/

   //* ---- PART 3 ---- TEST INSERT OPERATION
   cout << "Inserting the values of 0, 10, ..., 80 into the list. \n\n";

   for (int i = 0; i < 9; i++)
      intList.insert(10 * i);  //  -- insert 10*i into the list in order

   cout << intList << endl << endl;  // Were the items inserted correctly?


   //-------------------------------------------------------------------
   //        Test insert at end of list:
   //-------------------------------------------------------------------

   cout << "\nInserting a data element, 999,  at end of list:\n";

   intList.insert(999);

   cout << "\nAfter inserting 999 at end of list:\n" << intList << endl;

   //-------------------------------------------------------------------
   //        Test insert into the middle of the list:
   //-------------------------------------------------------------------

   cout << "\nInserting a data element, 25, into the middle of the list:\n";

   intList.insert(25);

   cout << "\nAfter inserting 25 at end of list:\n" << intList << endl;

   //---- END PART 3 ----*/

   //* ---- PART 4 ---- TEST ERASE OPERATION

   cout << "\nTesting the removal of the last node from the list. The original "
           "list :\n"
        << intList << endl;

   intList.erase(999);

   cout << "\nThe list with the last node removed:\n" << intList << endl;

   cout << "\nTesting the removal of the first node from the list. The "
           "original list :\n"
        << intList << endl;

   intList.erase(0);

   cout << "\nThe list with the first node removed:\n" << intList << endl;

   cout << "\nTesting the removal of a node, 25,  from the middle of the list. "
           "The original list :\n"
        << intList << endl;

   intList.erase(25);

   cout << "\nThe list with the node containing 25 removed:\n"
        << intList << endl;

   cout << "\nTesting the removal of a node that is not contained in the list. "
           "The original list :\n"
        << intList << endl;

   intList.erase(1107);

   cout << "\nThe list after trying to remove a node not in the list:\n"
        << intList << endl;
   //----END PART 4 ----* /

   //* ---- PART 5 ---- TEST DESTRUCTOR
   {
      LinkedList anotherList;  // this is now a local object to the block
      for (int i = 0; i < 5; i++)
         anotherList.insert(20 * i);

      cout << "\nHere's another list:\n" << anotherList << endl;
      cout << "Now destroying this list\n ";
   }
   cout << "*** anotherList has lost scope, therefore the destructor should "
           "have been called.\n";
   cout << "*** If the destructor was called, anotherList was destroyed ***\n";
   //---- END PART 5 ----*/


   //* ---- PART 6 ---- TEST COPY CONSTRUCTOR
   cout << "\n\nTesting copy constructor" << endl;
   f(intList);

   cout << "\n\nOriginal list:";  // output the original to make sure
   cout << intList << endl;       // it hasn't been changed.

   //---- END PART 6 ----*/

   // ---- PART 7 ----
   //   ADD STATEMENTS HERE TO TEST ASSIGNMENT OPERATOR
   LinkedList second;

   cout << "second before: " << second << endl;
   second = intList;
   cout << "second after assignment to intList: " << second << endl;

   cout << "\n\nSelf assignment: \n";
   second = second;
   // ---- END PART 7 ----

   cout << "END TESTS.\n";
}
