/*--- treetester.cpp -------------------------------------------------
  Program for testing class template BST.

  Written by:   Larry R. Nyhoff

  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                            Lab #10.1

  Add your name here and other info requested by your instructor.

 ---------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

//*---- PART 3 ----
// makeCopy() is a function with a
void makeCopy(BST<int> aBST)  // BST value parameter
{                             // to test the copy constructor
   cout << "\nNow copying the BST and adding 38999,"
           " -12312, and 55657 to the copy:\n";
   aBST.insert(38999);
   aBST.insert(-12312);
   aBST.insert(55657);

   cout << "--Here's the modified  copy: \n";
   aBST.graph(cout);
}
//---- END PART 3 ----*/

int main() {
   const char MENU[] =
       "MENU CHOICES\n"
       "0.  Display the menu\n"
       "1.  Check if BST is empty\n"
       "2.  Insert some elements into the BST\n"
       "3.  Search for an element\n"
       "4.  Delete some elements from the BST\n"
       "5.  Graphical representation of BST (sideways)\n"
       "6.  Inorder traversal\n"
       "61. Preorder traversal\n"
       "62. Postorder traversal\n"
       "7.  Check destructor\n"
       "8.  Check copy constructor\n"
       "9.  Check assignment operator\n"
       "10. Quit the program\n";

   // Testing Constructor and empty()
   BST<int> intBST;  // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";


   // Test Other Operations
   cout << MENU << endl;
   int choice;
   do {
      cout << "\nEnter a menu choice (0 for menu, 5 to graph, 10 to stop): ";
      cin >> choice;
      switch (choice) {
         case 0:  // Display menu
            cout << MENU << endl;
            break;

         case 1:  // Checking empty
            cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
            break;

         case 2:  // Insert elements
            cout << "\nNow insert a bunch of integers into the BST."
                    "\nTry items not in the BST and some that are in it:\n";
            int number;
            for (;;) {
               cout << "Item to insert (-999 to stop inserting): ";
               cin >> number;
               if (number == -999)
                  break;
               intBST.insert(number);
               cout << "Here's the BST:\n";
               intBST.graph(cout);
            }
            break;

         case 3:  // Searching)
            cout << "\n\nNow testing the search() operation."
                    "\nTry both items in the BST and some not in it:\n";
            for (;;) {
               cout << "Item to find (-999 to stop searching): ";
               cin >> number;
               if (number == -999)
                  break;
               cout << (intBST.search(number) ? "Found" : "Not found") << endl;
            }
            break;

         case 4:  // Deleting elements
            cout << "\nNow testing the remove() operation."
                    "\nTry both items in the BST and some not in it:\n";
            for (;;) {
               cout << "Item to delete (-999 to stop deleting): ";
               cin >> number;
               if (number == -999)
                  break;
               intBST.remove(number);
               cout << "Here's the BST:\n";
               intBST.graph(cout);
            }
            break;

         case 5:  // Graphical representation
            cout << "Here's the BST (sidewise):\n";
            intBST.graph(cout);
            break;

         case 6:  // Inorder traversal
            cout << "\nInorder Traversal of BST: \n";
            intBST.inorder(cout);
            cout << endl;
            break;

         default:
            cerr << "BAD CHOICE -- TRY AGAIN\n";
            break;

         case 10:  // quit menu
            break;

         /* ---- PART 1 ----
         case 61: // Test preorder traversal
                   cout << "\nPreorder Traversal of BST: \n";
                   intBST.preorder(cout);
                   break;
        ---- END PART 1 ----*/

         /* ---- PART 1 ----
         case 62: // Test postorder traversal
                   cout << "\nPostorder Traversal of BST: \n";
                   intBST.postorder(cout);
                   break;
        ---- END PART 2 ----*/

         //* ---- PART 2 ----
         case 7:  // Testing the Destructor
            cout << "\nNow testing the destructor. Remember to add an\n"
                    "output statement to your destructor to indicate \n"
                    "when it is called.\n";
            {
               BST<int> doomedBST;
               doomedBST.insert(6);
               doomedBST.insert(9);
               doomedBST.insert(5);
               doomedBST.insert(1);
               doomedBST.insert(3);
               doomedBST.insert(7);
               cout << "\nHere's a BST:\n";
               doomedBST.graph(cout);
               cout << "\n\nLifetime of this BST is over -- now destroy it.\n";
            }
            break;
            //---- END PART 2 ----*/

            //* ---- PART 3 ----
         case 8:  // Testing the Copy Constructor
         {
            cout << "\nNow testing the copy constructor.\n";
            cout << "-- First with an initializing declaration: "
                    "BST<int> copy = intBST;\n";
            BST<int> copy = intBST;
            cout << "Here's the original:\n";
            intBST.graph(cout);
            cout << "\nHere's the copy:\n";
            copy.graph(cout);
         }
            cout << "\n\n-- Now by passing intBST to a value parameter:\n";
            makeCopy(intBST);
            cout << "\n--Check that original BST hasn't been changed.\n"
                    "-- Inorder traversal of original:\n";
            intBST.graph(cout);
            cout << endl;
            break;
            // ---- END PART 3 ----*/

            //* ---- PART 4 ----
         case 9:  // Testing the Assignment Operator
            cout << "\nNow testing the assignment operator with the "
                    "statement:\n   and_anotherBST = anotherBST = intBST;\n";
            BST<int> anotherBST, and_anotherBST;
            ;
            and_anotherBST = anotherBST = intBST;
            cout << "\n-- Here's intBST:\n";
            intBST.graph(cout);
            cout << "\nHere's anotherBST:\n";
            anotherBST.graph(cout);
            cout << "\nand_anotherBST:\n";
            and_anotherBST.graph(cout);
            cout << "\nNow testing self-assignment with"
                    "\n   anotherBST = anotherBST;\n";
            anotherBST = anotherBST;
            cout << "\nHere's anotherBST:\n";
            anotherBST.graph(cout);
            cout << endl;
            break;
            //---- END PART 4 ----*/

      }  // switch

   } while (choice != 10);

}  // end main()
