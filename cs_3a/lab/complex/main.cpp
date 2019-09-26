#include <iostream>
#include "complex.h"
// #include "complex.cpp"
using namespace std;


int main()
{
	bool test_bool;
	Complex usr_input;

	cout << "\nTesting default constructor\n";
	cout << Complex() << endl;

	cout << "\nTesting one parameter constructor with input 5\n";
	cout << Complex(5) << endl;

	cout << "\nTesting two parameter constructor with input 0, 0\n";
	cout << Complex(0, 0) << endl;

	cout << "\nTesting two parameter constructor with input 1, 2\n";
	cout << Complex(1, 2) << endl;

	cout << "\nTesting two parameter constructor with input -13, 21\n";
	cout << Complex(-13, 21) << endl;

	cout << "\nTesting two parameter constructor with input -3, -4\n";
	cout << Complex(-3, -4) << endl;

	cout <<"\nTesting addition subtraction and multiplication for complex numbers: 10+4i and 5+3i\n";
	display(Complex(10, 4), Complex(5, 3));

	cout << "\nTesting addition subtraction and multiplication for complex numbers: -10-4i and -5-3i\n";
	display(Complex(-10, -4), Complex(-5, -3));

	cout << "\nTesting == operator with -10-4i and -5-3i\n";
	test_bool = (Complex(-10, -4) == Complex(-5, -3));
	cout << "Should be false: " << test_bool << endl;;

	cout << "\nTesting == operator with 10+4i and 10+4i\n";
	test_bool = (Complex(10, 4) == Complex(10, 4));
	cout << "Should be true: " << test_bool << endl;;

	cout << "\nTesting << and >> operators\n";
	cout << "enter imaginary number of form a+bi or a-bi\n";
	cin >> usr_input;
	cout << usr_input << endl;
		

}


