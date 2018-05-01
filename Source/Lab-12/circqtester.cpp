/// \file circqtester.cpp
/// \brief Testing driver for the CircularQueue class
/// \author Johnathan Lee for CSCI 1107, Lab 12, Proj 7.2
/// \date 04/10/18


#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

#include "circq.h"


using namespace std;

/// \brief Helper function to say WHAT we're testing.
void testing(string what) {
   cout << "Testing " << what << "...\n";
}

/// \brief Helper function to say we passed a test. (assert didn't fail).
/// \note Only gets called if the assert before it passed.
void passed() {
   cout << "PASSED!\n\n\n";
}


//int main() {
//   testing("Constructor and empty");
//   CircularQ<int> intQueue;
//   // Constructor should make an empty queue.
//   assert(intQueue.empty());
//   passed();

//   testing("Enqueue, Dequeue, Front, and empty");
//   for (int i = 10; i < 100; i += 10)
//      intQueue.enqueue(i);

//   for (int i = 10; i < 100; i += 10) {
//      // Make sure each went in properly
//      assert(intQueue.front() == i);
//      intQueue.dequeue();
//   }
//   // Should be empty after dequeing all elements
//   assert(intQueue.empty());
//   passed();


//   {
//      testing("Display");
//      for (int i = 10; i < 100; i += 10)
//         intQueue.enqueue(i);

//      stringstream ss;
//      intQueue.display(ss);
//      // display should output each followed by 2 spaces
//      cout << "Output was: " << ss.str() << endl;
//      assert(ss.str() == "10 20 30 40 50 60 70 80 90 ");
//      passed();


//      stringstream
//          ss2;  // Since for some reason ss.clear doesn't work properly...
//      testing("operator<<");
//      ss2 << intQueue;

//      cout << "Output was: " << ss2.str() << endl;
//      // display should output each followed by 2 spaces
//      assert(ss2.str() == "10 20 30 40 50 60 70 80 90 ");
//      passed();
//   }
//   testing("Destructor");
//   {
//      CircularQ<int> desTester;
//      desTester.enqueue(10);
//      desTester.dequeue();
//      // Now destruct. You'll know if it works using magic.
//   }
//   passed();

//   {
//      testing("Copy constructor");
//      CircularQ<int> q1;
//      for (int i = 10; i < 100; i += 10)
//         q1.enqueue(i);


//      CircularQ<int> q2(q1);

//      for (int i = 10; i < 100; i += 10) {
//         // Make sure each went in properly
//         assert(q2.front() == i);
//         q2.dequeue();
//      }
//      passed();
//   }

//   {
//      testing("Assignment operator");
//      CircularQ<int> q1, q2;
//      for (int i = 10; i < 100; i += 10)
//         q1.enqueue(i);

//      q2 = q1;

//      for (int i = 10; i < 100; i += 10) {
//         // Make sure each went in properly
//         assert(q2.front() == i);
//         q2.dequeue();
//      }
//      passed();
//   }


//   return 0;
//}  // end main
