///// \file Project8-1.cpp
///// \author Johnathan Lee for CSCI 1107
///// \date Due 04/10/18

//#include <iostream>
// using namespace std;

// unsigned indent   = 0;  ///>! For tracing functions
// unsigned numCalls = 0;  ///>! For counting calls.

// void doIndent(bool arrowRight);

// int f(int n) {
//   int retVal;

//   indent += 2;
//   doIndent(true);
//   cout << "Entering f(" << n << ");\n";
//   if (n < 2)
//      retVal = 0;
//   else
//      retVal = 1 + f(n / 2);

//   doIndent(false);
//   cout << "f(" << n << ") returns " << retVal << "\n";
//   indent -= 2;
//   return retVal;
//}

// int recFibonacci1(int n);
// int euclidGCD(int a, int b);

// int main1() {
//   int    m, n;
//   string funcName = "euclidGCD";
//   cout << "Enter numbers to trace " << funcName << "() for: ";
//   cin >> m >> n;
//   cout << "Trace for " << funcName << "(" << n << ") is: \n";
//   euclidGCD(m, n);
//   cout << "It took a whopping " << numCalls << " to calculate that!\n";
//}

///// \brief Helper function for tracing
///// \param arrowRight Should we use a ==> ? If not, use a <==.
// void doIndent(bool arrowRight) {
//   for (int i = 0; i < indent; i++)
//      cout << " ";
//   cout << (arrowRight ? "==>" : "<==");
//}

///// \brief Recursively calculates the fibonacci number for n
///// \param n The index into the fibonacci sequence to calculate.
///// \returns The value of the fibonacci sequence at index n.
///// \note Don't do this for n > 30 or so... Just don't.
// int recFibonacci(int n) {
//   {  // Tracing stuff
//      numCalls++;
//      indent += 2;
//      doIndent(true);
//      cout << "Entering recFibonacci(" << n << ");\n";
//   }
//   int ret;


//   if (n == 1 || n == 2)  // 2
//      ret = 1;            // 3
//   else
//      ret = recFibonacci(n - 1) + recFibonacci(n - 2);  // 4

//   {  // Tracing stuff
//      doIndent(false);
//      cout << "recFibonacci(" << n << ") returns " << ret << "\n";
//      indent -= 2;
//   }
//   return ret;
//}

///// \brief Calculates the greatest common divisor of a and b using the
///Euclidean
///// Algorithm.
///// \param a see next
///// \param b Together with a, the numbers whose GCD we will find.
///// \returns The GCD of a and b.
// int euclidGCD(int a, int b) {
//   {  // Tracing stuff
//      numCalls++;
//      indent += 2;
//      doIndent(true);
//      cout << "Entering euclidGCD(" << a << "," << b << ");\n";
//   }

//   int ret;

//   int r = a % b;
//   if (r == 0) {
//      ret = 0;
//   } else {
//      int next = euclidGCD(b, r);
//      ret      = (next == 0 ? r : next);
//   }

//   {  // Tracing stuff.
//      doIndent(false);
//      cout << "euclidGCD(" << a << "," << b << ") returns " << ret << "\n";
//      indent -= 2;
//   }

//   return ret;
//}
