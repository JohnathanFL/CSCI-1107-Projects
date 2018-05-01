#include <iostream>
#include "circq.h"
using namespace std;

int main() {
   // Note: I added some comments for clarity of testing, but file is otherwise
   // unchanged.

   CircularQ q1;

   q1.enqueue(10);
   q1.enqueue(20);
   q1.enqueue(30);

   q1.display(cout);    // Expected: 10 20 30
   cout << q1 << endl;  // Expected: 10 20 30
   {
      CircularQ q;
      q.enqueue(10);
      q.enqueue(20);
      q.enqueue(30);
      cout << "in { } for queue" << q << endl;  // Expected: 10 20 30
      // Expected: No crashes. (Please, compiler?)
      cout << "Testing destructor " << endl;
   }
   CircularQ q2(q1);
   cout << "Testing copy constructor " << endl;

   cout << q2 << endl;  // Expected: 10 20 30

   CircularQ q3;

   q3 = q2;
   cout << "Testing assignment operator." << endl;

   cout << q3 << endl;  // Expected: 10 20 30

   cout << "Testing front method: " << q3.front() << endl;  // Expected: 10

   // Expected:
   // 20 30
   // 30
   // EMPTY_CIRCULAR_QUEUE (Or nothing, if that output is disabled.)
   while (!q3.empty()) {
      q3.dequeue();
      cout << q3 << endl;
   }  // end while


   return 0;
}  // end main
