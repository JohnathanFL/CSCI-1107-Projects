#include "complex.h"
#include <iostream>
using namespace std;

int main(){

	Complex u(3, 4), v(0,3);
	cout << "Testing the explicit value constructor: " << endl;
	cout << "u(3,4) is equal to: " << u << endl
		<< "v(0,3) is equal to: " << v << endl;


	Complex w, z;
	
	cout << "Testing the default constructor: " << endl;
	cout << "w is equal to: " << w << endl
		<< "z is equal to: " << z << endl;
//**********************************************************************
	
	cout << "Testing the overloaded extraction operator: " << endl;
	
	cout << "Enter a complex number in the form of a + bi" << endl;
	cin >> w;

	cout << "You entered the value of " << w << endl;

	cout << "Enter a complex number in the form of a + bi" << endl;
	cin >> z;

	cout << "You entered the value of " << z << endl;
//***********************************************************************
	
	cout << "Testing the overloaded addition operator: " << endl;
	cout << "With two complex objects: " << endl;
	w = u + v;
	
	cout << "w = u + v is equal to: " <<  w << endl;

	cout << "With one complex object: " << endl;
	w = 3 + v;

	cout << "w = 3 + v is equal to: " << w << endl;

	cout << "With one complex object: " << endl;
	w = v + 3;

	cout << "w = v + 3 is equal to: " << w << endl;
//********************************************************************
	
	cout << "Testing the overloaded subtraction operator: " << endl;
	cout << "With two complex objects: " << endl;
	z = u - v;

	cout << "z = u - v is equal to: " << z << endl;

	cout << "With one complex object: " << endl;
	z = 3 - v;

	cout << "z = 3 - v is equal to: " << z << endl;

	cout << "With one complex object: " << endl;
	z = v - 3;

  // NOTE: Changed from v+3 to v-3 in string to match above op.
	cout << "z = v - 3 is equal to: " << z << endl;
//********************************************************************
	
	cout << "Testing the overloaded multiplication operator: " << endl;
	cout << "With two complex objects: " << endl;
	z = u * v;

	cout << "z = u * v is equal to: " << z << endl;

	cout << "With one complex object: " << endl;
	z = 3 * v;

	cout << "z = 3 * v is equal to: " << z << endl;

	cout << "With one complex object: " << endl;
	z = v * 3;

	cout << "z = v * 3 is equal to: " << z << endl;
//*********************************************************************

	cout << "Testing the overloaded division operator: " << endl;
	cout << "With two complex objects: " << endl;
	z = u / v;

	cout << "z = u / v is equal to: " << z << endl;

	cout << "With one complex object: " << endl;
	z = 3 / v;

	cout << "z = 3 / v is equal to: " << z << endl;

	cout << "With one complex object: " << endl;
	z = v / 3;

	cout << "z = v / 3 is equal to: " << z << endl;
//**********************************************************************
	cout << "Testing the absolute value: " << endl;
	cout << "abs(u) is " << abs(u) << endl;

	Complex c1(3, 5), c2(3, 5), c3(5, 3);
	
	if (c1 == c2)
		cout << c1 << " is equal to " << c2 << endl;
	else
		cout << c1 << " is not equal to " << c2 << endl;

	if (c2 == c3)
		cout << c2 << " is equal to " << c3 << endl;
	else
		cout << c2 << " is not equal to " << c3 << endl;

	cout << "All done testing\n\n";

	return 0;
}