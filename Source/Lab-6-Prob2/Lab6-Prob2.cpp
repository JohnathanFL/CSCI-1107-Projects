/* Lab6-Prob2.cpp
 * Test driver for RationalNumber class.
 * NOTE: Includes an auto tester. Simply define AUTO_TESTS
 *
 * Johnathan Lee    CSCI 1107
 * Due: 02/26/18
 */


#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

#include "RationalNumber.h"

// Because typing in test inputs over and over during development got boring.
#define AUTO_TESTS

// Tester for RationalNumber
int main() {
   RationalNumber num;
   cout << "Enter appropriate equations followed by enter, use CTRL+C to "
           "stop: \n";

#ifdef AUTO_TESTS
   // All of the official inputs for easy automated testing.
   std::string inputs[] = {"3/8 + 1/6\n",  "3/8 - 1/6\n",  "3/8 * 1/6\n",
                           "3/8 / 1/6\n",  "3/8 I\n",      "8/3 M\n",
                           "6/8 R\n",      "6/8 G\n",      "1/6 L 3/8\n",
                           "1/6 < 3/8\n",  "1/6 <= 3/8\n", "1/6 > 3/8\n",
                           "1/6 >= 3/8\n", "3/8 = 9/24\n", "2/3 X + 2 = 4/5\n"};
   std::string expectedOutputs[] = {
       "13/24", "5/24", "1/16", "9/4", "8/3", "2 + 2/3", "3/4",     "2",
       "24",    "1",    "1",    "0",   "0",   "1",       "X = -9/5"};


   for (int i = 0; i < 15; i++) {
      // You're right, this class is pretty useful.
      stringstream testIn, testOut;

      testIn << inputs[i];
      num.parse(testIn, testOut);

      cout << inputs[i] << "Result: ";
      assert(expectedOutputs[i] == testOut.str());
      cout << testOut.str();
      cout << "\n";
   }
#else

   while (true) {
      num.parse(cin, cout);
      cout << "\n";
   }
#endif


   return 0;
}
