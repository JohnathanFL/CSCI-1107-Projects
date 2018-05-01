/* circq.cpp
 *
 * Defines CircularQ functions and associated operators.
 *
 * Johnathan Lee        CSCI 1107
 * Lab 10               Due 04/03/18
 */

#include "circq.h"


CircularQ::CircularQ() {
   myBack = NULL;
}

// Since it's just 2 statements, should really be inlined...
CircularQ::CircularQ(const CircularQ& orig) {
   myBack = NULL;

   // Since it's the same code and the (this == &rhs) still works...
   *this = orig;
}

CircularQ::~CircularQ() {
   if (myBack) {
      Node* cur    = myBack->next;
      myBack->next = NULL;
      while (cur != myBack) {
         Node* old = cur;
         cur       = cur->next;
         delete old;
      }
      delete myBack;  // Putting out here to avoid problems with size() == 1.
   }
   myBack = NULL;  // Accomodate Microsoft
}

const CircularQ& CircularQ::operator=(const CircularQ& rhs) {
   if (this != &rhs) {
      this->~CircularQ();  // Delete old list

      Node* curRhs = rhs.myBack->next;
      // Use our methods - think deeply of simple things.
      // (I'm gonna have nightmares about that phrase)
      do {
         enqueue(curRhs->data);
         curRhs = curRhs->next;
      } while (curRhs != rhs.myBack->next);
   }
   return *this;
}

bool CircularQ::empty() const {
   return myBack == NULL;  // If myBack is null we have no nodes, so empty.
}

void CircularQ::enqueue(const QueueElement& value) {
   if (myBack) {  // !empty
      Node* newNode = new Node(value, myBack->next);
      myBack->next  = newNode;
      myBack        = newNode;
   } else {
      myBack = new Node(value, myBack);
      // Because assigning it in the constructor would assign to NULL.
      // You don't wanna know how long that one took me.
      myBack->next = myBack;
   }
}

void CircularQ::display(ostream& out) const {
   if (myBack) {
      Node* cur = myBack->next;
      do {
         out << cur->data << " ";
         cur = cur->next;
      } while (cur != myBack->next);
   } else {
      // To help distinguish between no output and outputting blank queue.
      /*//*/ out << "EMPTY_CIRCULAR_QUEUE ";
   }
}

QueueElement CircularQ::front() const {
   return myBack->next->data;
}

void CircularQ::dequeue() {
   if (myBack->next == myBack) {
      delete myBack;
      myBack = NULL;
   } else {
      Node* oldFront = myBack->next;
      myBack->next   = oldFront->next;
      delete oldFront;
   }
}

ostream& operator<<(ostream& out, const CircularQ& q) {
   q.display(out);
   return out;
}
