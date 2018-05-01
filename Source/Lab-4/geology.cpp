/*--- geology.cpp ---------------------------------------------------
  A program to model rocks.

  Written by:   Larry R. Nyhoff
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                                Solving with C++, 2E

                                         Lab #2.2  and  Project #2.2

  Johnathan Lee			CSCI 1107
  Lab 4					Due Date:	02/06/18
---------------------------------------------------------------------*/

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
// Function prototypes go here

#include "Rock.h"

int main() {
   /***** PART 1 ******/

   // Declare a variable to store a rock

   Rock sample;

   // Input and display various rocks

   for (;;) {
      cout << "Enter a rock (" << ROCK_OVERFLOW << " to stop): ";

      cin >> sample;

      if (sample == ROCK_OVERFLOW)
         break;
      cout << "Rock is: " << sample << endl;
   }

   /***** PART 2 ******/

   // Display all the rock names

   cout << "\nList of rocks:\n";
   for (Rock rockVal = BASALT; rockVal < ROCK_OVERFLOW;
        rockVal      = nextOne(rockVal))
      cout << rockVal << "  ";
   cout << endl;

   for (Rock rockVal = BASALT; rockVal < ROCK_OVERFLOW;
        rockVal      = nextOne(rockVal))
      // Display only 4 rocks per line (rockVal % 4)
      cout << kind(rockVal) << "   " << (rockVal % 4 == 0 ? "\n" : "");
   cout << endl;


   // More complete testing for project 2.2 #2
   Rock input;
   cout << "Please enter a rock: ";
   cin >> input;
   cout << "You entered: " << input << ", which is a(n) " << kind(input)
        << " rock!\n";

   /****** Project 2.2 Program *****/
}
