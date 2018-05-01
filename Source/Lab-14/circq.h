/* circq.h
 *
 * Declares CircularQ data type and associated operators
 *
 * Johnathan Lee        CSCI 1107
 * Lab 10               Due 04/03/18
 *
 * Modified for Lab 14 by Johnathan Lee:
 * - Removed circq.cpp (All definitions now in this file)
 * - Turned to template version.
 * - Replaced QueueElement with typename T.
 */


#ifndef CIRCQ_H
#define CIRCQ_H

#include <iostream>

using namespace std;


typedef int T;  ///>! The type of element stored in the queue.
/// \class CircularQ
/// \brief A Queue implemented with a circular linked list.
/// \note Uses sizeof(QueueElement) + sizeof(POINTER) per element.
template <typename T>
class CircularQ {
  public:
   /// \brief Default (Empty) constructor
   /// \param None
   /// \post *this is initialized with absolutely no elements.
   CircularQ();

   /// \brief Copy constructor:
   /// \param orig The CircularQ to copy elements from
   /// \post All elements from orig are now ALSO contained in *this.
   /// \note This does NOT transfer ownership, it is a deep copy, orig is
   /// unchanged.
   CircularQ(const CircularQ& orig);

   /// \brief Destructor
   /// \post All elements in this queue are deleted
   ~CircularQ();

   /// \brief Assignment
   /// \param rhs The queue to copy elements from.
   /// \post All elements are deep copied to *this. See copy constructor.
   const CircularQ& operator=(const CircularQ& rhs);

   /// \brief Check if the queue is empty.
   /// \return Whether there are no elements in the queue
   bool empty() const;

   /// \brief Add a value to the end of the queue.
   /// \param value The value to add into the queue.
   /// \post value is now at the end of the queue.
   void enqueue(const T& value);

   /// \brief Outputs *this
   /// \param out The stream to write to
   /// \post The contents of this list are written to out, space delimited.
   void display(ostream& out) const;

   /// \brief Get the front of the queue.
   /// \returns The first element in the queue. (I.E been there the longest).
   T front() const;

   /// \brief Remove the element at the front of the queue.
   /// \post Current this->front() is no longer in memory.
   void dequeue();

  private:
   /// \class Node
   /// \brief Internal storage for data elements. Not relevent outside
   /// CircularQueue class internals.
   class Node {
     public:
      /// \brief Constructor
      /// \param value The data value to assign to data
      /// \param link The Node *this should link to.
      Node(T value, Node* link = NULL) : data(value), next(link) {
      }
      T     data;  ///>! Our data element
      Node* next;  ///>! The next link in the chain
   };

   typedef Node* NodePointer;

   NodePointer myBack;  ///>! Our view into the list. Use myBack->next for front
};


/// \brief Output stream operator for CircularQ
/// \param out The stream to write to.
/// \param q The queue to display
/// \post Writes all elements in q to out. See CircularQ::display for more.
template <typename T>
ostream& operator<<(ostream& out, const CircularQ<T>& q);

template <typename T>
CircularQ<T>::CircularQ() {
   myBack = NULL;
}

// Since it's just 2 statements, should really be inlined...
template <typename T>
CircularQ<T>::CircularQ(const CircularQ<T>& orig) {
   myBack = NULL;

   // Since it's the same code and the (this == &rhs) still works...
   *this = orig;
}

template <typename T>
CircularQ<T>::~CircularQ() {
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

template <typename T>
const CircularQ<T>& CircularQ<T>::operator=(const CircularQ<T>& rhs) {
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

template <typename T>
bool CircularQ<T>::empty() const {
   return myBack == NULL;  // If myBack is null we have no nodes, so empty.
}

template <typename T>
void CircularQ<T>::enqueue(const T& value) {
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

template <typename T>
void CircularQ<T>::display(ostream& out) const {
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

template <typename T>
T CircularQ<T>::front() const {
   return myBack->next->data;
}

template <typename T>
void CircularQ<T>::dequeue() {
   if (myBack->next == myBack) {
      delete myBack;
      myBack = NULL;
   } else {
      Node* oldFront = myBack->next;
      myBack->next   = oldFront->next;
      delete oldFront;
   }
}

template <typename T>
ostream& operator<<(ostream& out, const CircularQ<T>& q) {
   q.display(out);
   return out;
}


#endif
