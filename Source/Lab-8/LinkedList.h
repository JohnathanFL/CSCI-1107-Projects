/*--- LinkedList.h --------------------------------------------------------
  This header file contains the declarations of LinkedList, a class for
  singly-linked lists.

  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                    Lab #5.1 and Projects 5.1 & 5.2

   Add a list of the basic operations including brief descriptions.

  Johnathan Lee         CSCI 1107
  Due 03/20/18

 --------------------------------------------------------------------------*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

//----- Add typdef statement here
typedef int ElementType;

class LinkedList {
  public:
   //------ LinkedList OPERATIONS


   // Prototype the class constructor here
   LinkedList();
   /* --- LinkedList constructor --------------------------------------
      Constructs an empty LinkedList object.

      Precondition:  None.
      Postcondition: This list's data members have been initialized
          for an empty list.
   ---------------------------------------------------------------------*/


   // Prototype and document the size() operation here
   int size() const;
   /* --- size() --------------------------------------------------------------
    *  Gives the number of elements in the LinkedList.
    *  PostCondition: this->mySize is returned.
    */


   // Prototype and document display() here
   /* --- display() -----------------------------------------------------------
    *  Displays all elements of this LinkedList
    *  Postconditions: All elements of this, if there are any, are printed to
    */
   void display(ostream& out) const;

   // Prototype insert() here
   void insert(ElementType newElem);
   /*----------------------------------------------------------------------
      Insert a value into the LinkedList in a sorted order.

      Precondition:  The parameter contains the data item to insert into an
                     ordered linked list. The field variable mySize needs
                     to be modified.
      Postcondition: dataValue has been inserted into this LinkedList
          object at the position determined by its value.
   -----------------------------------------------------------------------*/


   // Prototype erase() here
   void erase(ElementType target);
   /*----------------------------------------------------------------------
      erase() removes a node containing the value from the LinkedList.

      Precondition:  A data element from the list

      Postcondition: The data value at the position determined by its value
                     has been removed(depending upon if it is in the list)
                     from this LinkedList object.
   -----------------------------------------------------------------------*/


   // Prototype and document the destructor here
   ~LinkedList();
   /*---------------------------------------------------------------------------
    * Deletes the contents of the entire list.
    * Pre: None
    * Post: All elements are destroyed and their memory freed.
    */

   // Prototype and document the copy constructor here
   LinkedList(const LinkedList& rhs);
   /*---------------------------------------------------------------------------
    * Deep copies the list.
    * Pre: None.
    * Post: *this has been constructed with the contents of rhs, but NOT the
    *       same memory locations.
    */

   // Prototype and document the assignment operator here
   const LinkedList& operator=(const LinkedList& rhs);
   /*---------------------------------------------------------------------------
    * Deep copies the list IF the rhs is not the same object.
    * Pre: None
    * Post: *this is the same as rhs, and a reference to *this is returned.
    */

  private:
   class Node {
     public:
      //------ DATA MEMBERS OF Node
      // Define data and next members here
      ElementType data;
      Node*       next;

      //------ Node OPERATIONS

      // Prototype the Node constructor here
      Node(ElementType ele);

      /* --- The Node class constructor initializes a Node's data members.

         Precondition:  None
         Receive:       dataValue, an ElementType value;
         Postcondition: The data and next members have been set to
                        dataValue and 0, respectively.
      -------------------------------------------------------------------*/

   };  //--- end of Node class

   typedef Node* NodePointer;


   //------ DATA MEMBERS OF LinkedList
   // declare first as a pointer to a Node and declare mySize
   NodePointer first;
};  //--- end of LinkedList class

// Put prototype of operator<<() here
ostream& operator<<(ostream& out, const LinkedList& list);
#endif
