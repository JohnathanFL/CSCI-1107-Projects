/* circq.h
 *
 * Declares CircularQ data type and associated operators
 *
 * Johnathan Lee        CSCI 1107
 * Lab 10               Due 04/03/18
 */


#ifndef CIRCQ_H
#define CIRCQ_H

#include <iostream>

using namespace std;


typedef int QueueElement;  ///>! The type of element stored in the queue.
/// \class CircularQ
/// \brief A Queue implemented with a circular linked list.
/// \note Uses sizeof(QueueElement) + sizeof(POINTER) per element.
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
   void enqueue(const QueueElement& value);

   /// \brief Outputs *this
   /// \param out The stream to write to
   /// \post The contents of this list are written to out, space delimited.
   void display(ostream& out) const;

   /// \brief Get the front of the queue.
   /// \returns The first element in the queue. (I.E been there the longest).
   QueueElement front() const;

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
      Node(QueueElement value, Node* link = NULL) : data(value), next(link) {
      }
      QueueElement data;  ///>! Our data element
      Node*        next;  ///>! The next link in the chain
   };

   typedef Node* NodePointer;

   NodePointer myBack;  ///>! Our view into the list. Use myBack->next for front
};


/// \brief Output stream operator for CircularQ
/// \param out The stream to write to.
/// \param q The queue to display
/// \post Writes all elements in q to out. See CircularQ::display for more.
ostream& operator<<(ostream& out, const CircularQ& q);


#endif
