/*---  RandomInt.h -----------------------------------------------------
  This header file declares RandomInt,a  pseudo-random integer class.
 
  Written by: Joel C. Adams, Spring, 1993, at Calvin College.
  Written for: C++: An Introduction To Computing.
  Revised: Spring 1997, for C++: An Introduction To Computing 2e.
  Revised: Summer 2001, for C++: An Introduction To Computing 3e.
  Revised: Dec., 2004 by L. Nyhoff: Documentation incorporated  
     for ADTs, Data Structures, and Problem Solving with C++, 2E
 
  Usage: to generate a...
   nondeterministic sequence of 'random' numbers in 0..RAND_MAX:
      RandomInt rint1;       
   deterministic sequence of 'random' numbers in 0..RAND_MAX:
      RandomInt rint2(a);
   nondeterministic sequence of 'random' numbers in b..c:
      RandomInt rint3(b, c);       
   deterministic sequence of 'random' numbers in b..c:
      RandomInt rint2(a, b, c);
 
  Caution: RandomInt objects are NOT autonomous, but SHARE the ANSI-C
   standard random number generator rand().  For most applications,
   this will have no effect.  However, if a program defines an unseeded
   RandomInt r1, and later defines a seeded RandomInt r2, then the
   number-sequence for r1 will be 'random' prior to the definition
   of r2, but deterministic following the definition of r2 (because r2's
   re-seeding the random number generator affects the numbers of r1).
 
  Class Invariant: myRandomValue contains a 'random' number
                  between myLowerBound and myUpperBound (inclusive).

  See RandomInt.cpp for non-trivial operation definitions.
-----------------------------------------------------------------------*/

#ifndef RANDOMINT
#define RANDOMINT

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;

class RandomInt
{
 public:
  RandomInt();
  /*------------------------------------------------------------------
    Default constructor.
    Initializes a RandomInt to a number within default bounds.
    
    Postcondition: myLowerBound == 0 && myUpperBound == RAND_MAX &&
                   srand() has been seeded (using time()) &&
                   myRandomValue contains a 'random' number.
  ------------------------------------------------------------------*/
  
  RandomInt(int low, int high);
  /*------------------------------------------------------------------
    Bounded explicit-value constructor.
    Initializes a RandomInt to a number within specified bounds.
    
    Precondition:  0 <= low && low < high.
    Postcondition: myLowerBound == low && myUpperBound == high&&
                   srand() has been seeded (using time()) &&
                   myRandomValue contains a 'random' number.
  ------------------------------------------------------------------*/
  
  RandomInt(int seedValue);
  /*------------------------------------------------------------------
    Seeded explicit-value constructor.
    Initializes a RandomInt to a number within default bounds
       using a specified seed value. 
       
    Postcondition: myLowerBound == 0 && myUpperBound == RAND_MAX &&
                   srand() has been seeded (using seedValue) &&
                   myRandomValue contains a 'random' number.
  ------------------------------------------------------------------*/

  RandomInt(int seedValue, int low, int high);
  /*------------------------------------------------------------------
    Seeded and bounded explicit-value constructor.
    Initializes a RandomInt to a number within specified bounds
       using a specified seed value. 
       
    Precondition:  0 <= low && low < high.
    Postcondition: myLowerBound == low && myUpperBound == high&&
                   srand() has been seeded (using seedValue) &&
                   myRandomValue contains a 'random' number.
  ------------------------------------------------------------------*/

  void print(ostream & out) const;
  /*------------------------------------------------------------------
    Output a RandomInt via an ostream (Function Member). 

    Precondition:  ostream out is open.        
    Postcondition: myRandomValue has been inserted into out. 
    Note:  The output operator << is defined below.
  ------------------------------------------------------------------*/

  RandomInt generate();
  /*------------------------------------------------------------------
    Generate a new 'random' number within myLowerBound..myUpperBound.  

    Postcondition: myRandomValue has a new 'random' value &&
                   this RandomInt object is returned. 
  ------------------------------------------------------------------*/
  
  RandomInt generate(int low, int high);
  /*------------------------------------------------------------------
    Generate a new 'random' number within low..high.  

    Precondition:  0 <= low && low < high
    Postcondition: myRandomValue has a new 'random' value &&
                   this RandomInt object is returned. 
  ------------------------------------------------------------------*/
  
  operator int();
  /*------------------------------------------------------------------
    Convert RandomInt objects to int objects, where appropriate.

    Precondition:  A RandomInt has been used in a context defined
                   for an int, but not for a RandomInt.
    Postcondition: myRandomValue has been read and returned. 
  ------------------------------------------------------------------*/

 private:
  //--- Utility Functions
  
  void initialize(int low, int high);
  /*------------------------------------------------------------------
    Initialize the data members and seed the random number generator
    using a default value (the clock).
 
    Precondition:  0 <= low && low < high.
    Postcondition: myLowerBound == low && myUpperBound == high &&
                   srand() has been seeded (using time()) &&
                   myRandomValue contains a 'random' number.  
  ------------------------------------------------------------------*/

  void seededInitialize(int seedValue, int low, int high);
  /*------------------------------------------------------------------
    Initialize the data members and seed the random number generator
    using a specified value (seedValue).
 
    Precondition:  0 <= low && low < high.
    Postcondition: myLowerBound == low && myUpperBound == high &&
                   srand() has been seeded (using seedValue) &&
                   myRandomValue contains a 'random' number.  
  ------------------------------------------------------------------*/

  int nextRandomInt();
  /*------------------------------------------------------------------
    Generate next random integer.
 
    Precondition:  srand() has been called to seed rand() &&
                   myLowerBound has been initialized &&
                   myUpperBound has been initialized.   
    Postcondition: A new 'random' number is returned.
  ------------------------------------------------------------------*/

  //--- Data Members
  int myLowerBound,                         //  the minimum random value
      myUpperBound,                         //  the maximum random value
      myRandomValue;                        //  the current random value

  static bool generatorInitialized;         //  initialization flag
};

//--- Definition of default constructor
inline RandomInt::RandomInt()
{
  initialize(0, RAND_MAX);
}

//--- Definition of bounded explicit-value constructor
inline RandomInt::RandomInt(int low, int high)
{
  assert(0 <= low);
  assert(low < high);
  initialize(low, high);
}

//--- Definition of seeded explicit-value constructor
inline RandomInt::RandomInt(int seedValue)
{
  assert(seedValue >= 0);
  seededInitialize(seedValue, 0, RAND_MAX);
}

//--- Definition of bounded and seeded explicit-value constructor
inline RandomInt::RandomInt(int seedValue, int low, int high)
{
  assert(seedValue >= 0);
  assert(0 <= low);
  assert(low < high);
  seededInitialize(seedValue, low, high);
}

//--- Definition of print()
inline void RandomInt::print(ostream & out) const
{
  out << myRandomValue;
}

//--- Definition of output operator <<
inline ostream & operator<< (ostream & out, const RandomInt & randInt)
/*------------------------------------------------------------------
  Output a RandomInt via an ostream (Non-Function Member). 

  Precondition:  ostream out is open.        
  Postcondition: randInt has been inserted into out and out is
                 returned.
 ------------------------------------------------------------------*/
{
  randInt.print(out);
  return out;
}

//--- Definition of nextRandomInt()
inline int RandomInt::nextRandomInt()
{
  return myLowerBound + rand() % (myUpperBound - myLowerBound + 1);
}

//--- Definition of  generate()
inline RandomInt RandomInt::generate()
{
  myRandomValue = nextRandomInt();
  return *this;
}

//--- Definition of operator int()
inline RandomInt::operator int() 
{
  return myRandomValue;
}

#endif
