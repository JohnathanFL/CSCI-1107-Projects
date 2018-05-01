/// \file SortDriver.cpp
/// \author Johnathan Lee for CSCI 1107, Lab 13
/// \brief Sorting algorithm and test driver.
#include <algorithm>
#include <iostream>
#include <vector>

#include "RandomInt.h"
#include "Timer.h"

using namespace std;


/// \brief Sort an object that provides subscript access.
/// \tparam T The type of the object we're sorting. MUST PROVIDE SUBSCRIPT
/// OPERATOR.
/// \param vec The object we're sorting
/// \param n The number of elements to sort.
/// \post vec has been sorted.
template <typename T>
void selectionSort(T& vec, int n);

/// \brief Helper function to sort array by either selectionSort or STL's sort,
/// timing it.
/// \param vec The vector to sort.
/// \param stl Should we use STL's sort?
/// \param displayContents Should we display pre-sorted and post-sorted stuff?
/// \note Probably don't do displayContents on a 30000 element list... just
///       maybe..
/// \note Pass by value to preserve old contents for next sort.
void timeSort(vector<int> vec, bool stl, bool displayContents) {
   Timer timer;

   cout << "Sorted \n";
   if (displayContents) {
      for (int& el : vec)
         cout << el << " ";

      cout << "\nInto \n";
   }
   if (!stl) {
      timer.start();
      selectionSort(vec, vec.size());
      timer.stop();
   } else {
      timer.start();
      sort(vec.begin(), vec.end());
      timer.stop();
   }

   if (displayContents) {
      for (int& el : vec)
         cout << el << " ";
   }
   cout << "\nIn " << timer.seconds() << " seconds using "
        << (stl ? "STL's sort" : "our selection sort") << "!\n\n";
}

int main() {
   // Initial testing for selection sort.
   vector<int> singleEl = {2}, inOrder = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
               reverseOrder = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, random;

   RandomInt r(0, 100);
   for (int i = 0; i < 10; i++)
      random.push_back(r.generate());  // from 1-100


   timeSort(singleEl, false, true);
   timeSort(inOrder, false, true);
   timeSort(reverseOrder, false, true);
   timeSort(random, false, true);


   int         numEls = 0;
   vector<int> largeSet;


   cout << "Enter a number of elements for the large set: ";
   cin >> numEls;

   for (int i = 0; i < numEls; i++)
      largeSet.push_back(r.generate());

   // Definitely don't want to display all 25000 elements...
   timeSort(largeSet, false, false);
   timeSort(largeSet, true, false);

   return 0;
}

// Using a simple T for the entire type as opposed to vector<T> or other such
// stuff lets it be used on BOTH arrays AND vectors, and passing in n manually
// allows sorting over a range.
template <typename T>
void selectionSort(T& vec, int n) {
   for (int i = 0; i < n - 2; i++) {
      int smallPos = i;
      // Skipping smallest in favor of indexing.
      for (int j = i + 1; j < n - 1; j++) {
         if (vec[j] < vec[smallPos])
            smallPos = j;
      }
      swap(vec[smallPos], vec[i]);
   }
}
