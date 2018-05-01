/* Project4-1.cpp
 * Generates a bar graph from a Rockfile.txt
 * Johnathan Lee           CSCI 1107
 * Due 02/27/18
 */


#include <fstream>
#include <iomanip>
#include <iostream>

#include "Rock.h"

using namespace std;

void countOccurences(int count[], string fileName);
void barGraph(int counts[]);

int main() {
   int count[ROCK_OVERFLOW] = {};

   countOccurences(count, "Rockfile.txt");
   barGraph(count);
   return 0;
}

/// \brief Counts the occurences of rocks in a file.
/// \param count The array to store counts in, indexed by RockNames.
/// \param fileName the name of the file to read from.
/// \post count contains the number of times each Rock's human readable name
/// appears in fileName.
void countOccurences(int count[], string fileName) {
   Rock     rock;
   ifstream inFile;
   inFile.open(fileName);

   // Count occurences
   while (inFile >> rock) {
      count[rock.getName()]++;
      /* DEBUG STUFF
      cout << "Read rock: " << rock
           << "\nCount is now: " << count[rock.getName()];
           */
   }
}

/// \brief Outputs a bargraph of the counts of rocks.
/// \param counts The array containing the counts, indexed by RockNames.
/// \post A bar graph has been printed in the following format for each rock:
/// <ROCK NAME>: <ONE 'X' FOR EACH COUNT> (<INTEGER COUNT>)
/// ... <MORE OF THE ABOVE FOR EACH ROCK>
void barGraph(int counts[]) {
   // Start at BASALT(0).
   for (Rock rock = BASALT; rock < ROCK_OVERFLOW; ++rock) {
      cout << setw(20) << rock << ":";
      for (int i = 0; i < counts[rock.getName()]; i++) {
         cout << "X";
      }
      cout << " (" << counts[rock.getName()] << ")" << endl;
   }
}
