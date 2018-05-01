/*   Project-2.2.cpp
 *
 * Johnathan Lee     CSCI 1107
 * Project 2.2       Lab 4
 * Due 02/06/18
 */

#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Rock.h"

using namespace std;

bool openFile(string filename, ifstream& stream);
void countRocks(ifstream& inFile, int counts[]);
void printArrayHistogram(int ar[]);


int main() {
   int      count[ROCK_OVERFLOW] = {0};
   ifstream inFile;


   if (!openFile("Rockfile.txt", inFile)) {
      cout << "Failed to open Rockfile.txt! Exiting...\n\n";
      exit(1107);
   }
   countRocks(inFile, count);
   printArrayHistogram(count);

   return 0;
}

/// \brief Helper for ifstream that gives simpler error checking.
/// \pre stream shouldn't already be opened
///
/// \param filename The name of the file to open
/// \param stream a REFERENCE to the ifstream to use.
///
/// \returns Whether the file opened correctly.
/// \post stream is opened, AND IF returned true, opened correctly.
bool openFile(string filename, ifstream& stream) {
   stream.open(filename);
   return !stream.bad();
}

/// \brief Counts occurences of rock names from an inFile.
///
/// \param inFile The file to read rocks from.
/// \note The file must contain the STRING names of rocks, no numbers.
///
/// \param counts The array to store the occurence count in.
/// \note counts MUST have enough space for all rocks. (a size of
/// Rock::ROCK_OVERFLOW)
///
/// \post inFile's marker is at the end of the file, counts is filled with the
/// counts of each rock type.
void countRocks(ifstream& inFile, int counts[]) {
   Rock rock;
   while (inFile >> rock)  // Should automatically stop at EOF
      counts[rock]++;
}

/// \brief Prints a histogram of an array of rock counts.
///
/// \param ar The array to read from.
/// \note ar MUST be AT LEAST Rock::ROCK_OVERFLOW in size.
///
/// \post ar Has been printed to stdout in the following format:
/// <ROCK NAME>: <X repeated once for each occurence> (<number of occurences>)
void printArrayHistogram(int ar[]) {
   for (int i = 0; i < Rock::ROCK_OVERFLOW; i++) {  // Loop through rocks
      cout << setw(12) << Rock(i) << ":";
      for (int j = 0; j < ar[i]; j++)  // Loop through X's
         cout << "X";

      cout << "(" << ar[i] << ")\n";
   }
}
