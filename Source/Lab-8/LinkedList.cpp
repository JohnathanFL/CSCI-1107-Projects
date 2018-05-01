/* LinkedList.cpp
 * Definitions for LinkedList.h
 * Johnathan Lee        CSCI 1107
 * Due 03/20/18
 */

#include "LinkedList.h"

#include <cassert>
#include <new>

LinkedList::LinkedList() {
   first = NULL;
}

int LinkedList::size() const {
   int   count = 0;
   Node* cur   = first;
   while (cur) {
      cur = cur->next;
      count++;
   }
   return count;
}

void LinkedList::display(ostream& out) const {
   NodePointer ptr = this->first;
   while (ptr) {
      out << ptr->data << " ";
      ptr = ptr->next;
   }
}

void LinkedList::insert(ElementType newElem) {
   Node *cur = first, *pred = NULL;
   Node* newNode = new Node(newElem);

   while (cur && cur->data < newElem) {
      pred = cur;
      cur  = cur->next;
   }

   if (pred)
      pred->next = newNode;
   else
      first = newNode;

   newNode->next = cur;
}

void LinkedList::erase(ElementType target) {
   Node *cur = first, *pred = NULL;

   while (cur && cur->data != target) {
      pred = cur;
      cur  = cur->next;
   }

   if (cur != NULL) {  // We found it and/or list wasn't empty.
      // Deletion in the middle or end
      // I.e cur isn't == first.
      if (pred != NULL)
         pred->next = cur->next;

      // Deletion at beginning
      // Make sure we either know it's empty OR know the next link.
      if (cur == first)
         first = cur->next;

      delete cur;
   }  // Otherwise don't bother doing anything.
}

LinkedList::~LinkedList() {
   cout << "List destroyed!\n";
   Node* cur = first;

   while (cur != NULL) {
      first = cur->next;
      delete cur;
      cur = first;
   }
}

LinkedList::LinkedList(const LinkedList& rhs) {
   // Note for code maintenance: The below code is the same as that in operator=
   if (rhs.first == NULL) {
      first = NULL;
   } else {
      Node *origPtr = rhs.first, *lastPtr = NULL;
      lastPtr = new Node(origPtr->data);
      first   = lastPtr;
      origPtr = origPtr->next;
      while (origPtr != NULL) {
         lastPtr->next = new Node(origPtr->data);
         lastPtr       = lastPtr->next;
         origPtr       = origPtr->next;
      }
   }
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs) {
   cout << "Calling operator=\n";
   if (this != &rhs) {
      cout << "   operator= : rhs wasn't the same.\n";
      this->~LinkedList();  // Destroy value of var
      if (rhs.first == NULL) {
         first = NULL;
      } else {
         Node *origPtr = rhs.first, *lastPtr = NULL;
         lastPtr = new Node(origPtr->data);
         first   = lastPtr;
         origPtr = origPtr->next;
         while (origPtr != NULL) {
            lastPtr->next = new Node(origPtr->data);
            lastPtr       = lastPtr->next;
            origPtr       = origPtr->next;
         }
      }
   } else  // FOR DEBUG AND PART 7's testing.
      cout << "  operator= : rhs was the same.\n";
   return *this;
}

ostream& operator<<(ostream& out, const LinkedList& list) {
   list.display(out);

   return out;
}

LinkedList::Node::Node(ElementType ele) {
   data = ele;
}
