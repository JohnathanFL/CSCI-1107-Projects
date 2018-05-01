/*--- rectester.cpp -------------------------------------------------------
  Program to test a recursive Fibonacci function.
   
  Written by:   Larry R. Nyhoff
   
  Written for:  Lab Manual for ADTs, Data Structures, and Problem
                Solving with C++, 2E

                            Lab #8.1
                                                          
  Johnathan Lee       CSCI 1107
  Lab 11              Due 04/10/18
 --------------------------------------------------------------------------*/

#include <iostream>
#include <chrono>

using namespace std;

//-- PUT THE GLOBAL VARIABLE DECLARATIONS HERE



// PUT PROTOTYPE OF recFibonacci HERE
int recFibonacci(int n);
/*-----------------------------------------------------------
  recFibonacci is a recursive Fibonacci number calculator.
 
  Precondition:  The parameter nis a positive integer.
  Postcondition: The n-th Fibonacci number is returned.
 ------------------------------------------------------------*/

int main()
{
  int number;

  for (;;)
  {
    cout << "\nPlease enter a positive integer (or 0 to stop): ";
    cin >> number;

    if (number <= 0) break;

    cout << "The " << number << "-th Fibonacci number is "
         << recFibonacci(number) << endl;
  }
  

}

// DEFINE recFibonacci() HERE
int recFibonacci(int n) {
  if (n == 1 || n == 2)
    return 1;
  else
    return recFibonacci(n - 1) + recFibonacci(n - 2);
}