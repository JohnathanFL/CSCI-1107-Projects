/*--- RandomInt.cpp ------------------------------------------------
  This implementation file defines the nontrivial RandomInt 
  operations.

  Written by: Joel C. Adams, Spring, 1993, at Calvin College.
  Written for: C++: An Introduction To Computing.
  Revised: Spring 1997, for C++: An Introduction To Computing 2e.
  Revised: Summer 2001, for C++: An Introduction To Computing 3e.
  Revised: Dec., 2004 by L. Nyhoff: Documentation modified for  
           ADTs, Data Structures, and Problem Solving with C++, 2E
 
  See RandomInt.h for the class declaration and documentation.
------------------------------------------------------------------*/

#include "RandomInt.h"

//--- Definition of generatorInitialized
bool RandomInt::generatorInitialized = false;

//--- Definition of initalize()
void RandomInt::initialize(int low, int high)
{
  myLowerBound = low;
  myUpperBound = high;

  if (!generatorInitialized)       // call srand() first time only
  {
     srand(long(time(0)));         // use clock for seed
     generatorInitialized = true;
  }

  myRandomValue = nextRandomInt();
}

//--- Definition of seededInitialize()
void RandomInt::seededInitialize(int seedValue, int low, int high)
{
  myLowerBound = low;
  myUpperBound = high;
  srand(seedValue);
  generatorInitialized = true;
  myRandomValue = nextRandomInt();
}

//--- Definition of generate()
RandomInt RandomInt::generate(int low, int high)
{
  assert(0 <= low);
  assert(low < high);
  myLowerBound = low;
  myUpperBound = high;
  myRandomValue = nextRandomInt();
  return *this;
}
