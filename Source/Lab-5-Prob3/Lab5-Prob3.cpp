/* Lab5-Prob3.cpp
 *
 * Johnathan Lee        CSCI 1107
 * Lab 5                #3, problem text from P. 138 # 2.
 * Due 02/13/18
 */

/*
 * From book for reference: Peter the postman became bored one night and, to
 * break the monotony of the night shift, he carried out the following
 * experiment with a row of mailboxes in the post office. These mailboxes were
 * numbered 1-150, and beginning with mailbox 2, he opened the doors of all the
 * even numbered mailboxes, leaving the others closed. Next, beginning with
 * mailbox 3, he went to every 3rd mailbox, opening its door if it was closed,
 * and closing it if it was open. Then he repeated this procedure with every
 * 4th, every 5th, etc. When finished, he was surprised at the distribution of
 * closed mailboxes. Write a program to determine which mailboxes these were.
 */


#include <iostream>

using namespace std;

void flipBoxes(bool* boxAr, int numToFlip, int everyNth, bool startWithFirst);
void displayBoxes(bool boxes[], int numBoxes);

const int NUM_BOXES = 150;

int main() {
   // These mailboxes were numbered 1-150
   bool boxes[NUM_BOXES] = {true};  // Using true = closed.

   // and beginning with mailbox 2, he opened the doors of all the even numbered
   // mailboxes, leaving the others closed
   //
   // Since they started closed, flipping is the same as opening.
   // Start with 0 instead so that even numbering works correctly.
   // cout << "Flipping even!" << endl; // For debugging
   flipBoxes(&boxes[0], NUM_BOXES, 2, false);

   // beginning with mailbox 3, he went to every 3rd mailbox, opening its door
   // if it was closed,  and closing it if it was open (flipping). Then he
   // repeated this procedure with every  4th, every 5th, etc.
   //
   // Assuming continued all the way up to every NUM_BOXES-th,
   // and using i = which nth.
   for (int i = 3; i < NUM_BOXES; i++) {
      // cout << "\n\nFlipping every n=" << i << endl; // For debugging
      flipBoxes(&boxes[2], NUM_BOXES - 2, i, true);
   }

   // Show distribution
   displayBoxes(boxes, NUM_BOXES);

   return 0;
}

/// \brief Flips values in a boolean array
///
/// \pre boxAr MUST be a pointer to a bool and there MUST be at least numToFlip
/// values directly after it.
///
/// \param boxAr A pointer to the first value to flip.
/// \note Doesn't have the be the beginning of the array, just the first to flip
///
/// \param numToFlip How many values we should iterate over
///
/// \param everyNth How many values do we skip every time? (Flip every 2nd, 3rd,
/// etc)
///
/// \param startWithFirst Should we flip the first box, or just start counting
/// from there?
///
/// \post Values in boxAr have been toggled according to the rules in param.
void flipBoxes(bool* boxAr, int numToFlip, int everyNth, bool startWithFirst) {
   int i;

   if (startWithFirst)
      i = 0;
   else
      i = 1;

   for (; i < numToFlip; i++)
      if ((i + 1) % everyNth == 0) {
         boxAr[i] = !boxAr[i];
         // For debugging
         // cout << "Flipped at i = " << i << "(Box num " << i + 1 << ")\n";
      }
}

/// \brief Displays boxes in a 25x(numBoxes / 25) grid.
///
/// \param boxes The array of boxes to output.
/// \param numBoxes How many boxes in the array?
///
/// \post boxes has been printed to cout, using a '|' for closed and '-' for
/// open.
void displayBoxes(bool boxes[], int numBoxes) {
   cout << "\nMailboxes: (| for closed and - for open): \n";

   // Using | for closed, and - for open.
   // Think of a normal mailbox, with the door up when closed and down when open
   for (int i = 0; i < numBoxes; i++)
      cout << (i % 25 == 0 ? "\n" : "  ") << (boxes[i] ? "|" : "-");

   cout << "\n";  // Extra newline since my console messes up without a trailing
                  // newline.
}
