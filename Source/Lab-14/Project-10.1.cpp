/// \file Project-10.1.cpp
/// \brief Concordance creator
/// \author Johnathan Lee for CSCI 1107, Lab 14
/// \date Due 05/04/18

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "BST.h"
#include "Token.h"

using namespace std;

typedef BST<Token>
    AlphabetBST[26];  ///>! An array of BSTs, 1 member per letter.

/// \brief Gets a file based on user input.
/// \param file The ifstream to open.
/// \pre User must enter a valid filename/path in cin.
/// \post file is initialized/opened to the specified file.
void getFile(ifstream& file);

/// \brief Tells whether ch is one of [A-Z] or [a-z]
/// (uppercase or lowercase alphabetic)
bool isAlphabetic(char ch);

/// \brief Generates a concordance (an alphabetical listing of all distinct
/// words in a piece of text.)
/// \param storage An array of 26 BSTs which store tokens in which to store the
/// concordance.
/// \param inputFile The file to read from.
/// \post storage contains a concordance, indexed by the first letter of each
/// word.
/// \note All non-alphabetic (see isAlphabetic) characters will be removed. All
/// alphabetic characters will be made uppercase. (See std::toupper)
void generateConcordance(AlphabetBST& storage, ifstream& inputFile);

/// \brief Displays a concordance.
/// \param concord The pre-generated concordance to display.
/// \post concord has been displayed to cout in the following format:
/// concord[<UPPERCASE CHARACTER INDEX>]:
/// <CONCORDANCE FOR THAT LETTER GRAPHED>
/// ...
/// \note See BST::graph and Token::display for more.
void displayConcordance(AlphabetBST& concord);

/// \brief Strips any non-alphabetic characters from str and makes it all
/// UPPERCASE.
/// \param str The string to operate on
/// \post Examples of transformations: "hello"->"HELLO", "h3llo"->"HLLO"
void stripNonAlpha(string& str);
//*/
int main() {
   AlphabetBST concord;
   ifstream    inputFile;

   getFile(inputFile);
   generateConcordance(concord, inputFile);
   displayConcordance(concord);

   return 0;
}
//*/
void getFile(ifstream& file) {
   // Default name for rapid testing: Just comment out the 2 lines after it.
   string fileName = "concord.txt";

   //*
   cout << "Enter a filename to read from: ";
   cin >> fileName;
   //*/
   file.open(fileName);
   if (!file.good()) {
      cout << "Error opening " << fileName << " , terminating...\n";
      exit(1);
   }
}

bool isAlphabetic(char ch) {
   return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

void generateConcordance(AlphabetBST& storage, ifstream& inputFile) {
   string   lineBuf;
   unsigned lineNum = 1;
   // For each line
   while (getline(inputFile, lineBuf)) {
      stringstream line;
      line << lineBuf;

      // For each word on the line
      string wordBuf;
      while (line >> wordBuf) {
         stripNonAlpha(wordBuf);
         // Note for future: Don't do this and then try to test with a string
         // like "2". Just don't. Especially before you implement the non-alpha
         // character stripper.
         storage[wordBuf[0] - 'A'].insert(Token(wordBuf, lineNum));
      }

      lineNum++;
   }
}

void displayConcordance(AlphabetBST& concord) {
   // Automatically displays in ascending order since that's how they were
   // inserted.
   for (char i = 'A'; i < 'Z'; i++) {
      if (!concord[i - 'A'].empty())
         cout << "concord[" << i << "]:\n" << concord[i - 'A'] << endl;
   }
}

void stripNonAlpha(string& str) {
   for (unsigned i = 0; i < str.size(); i++) {
      char ch = str[i];
      if (isAlphabetic(ch)) {
         str[i] = toupper(ch);
      } else {
         // If this character isn't [A-Z] or [a-z]
         str.erase(i, 1);  // Remove it
         i--;              // And make sure we're still going over all the stuff
                           // properly (Since erase will move us).
      }
   }
}
