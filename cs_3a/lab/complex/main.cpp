#include <iostream>
#include "complex.h"
#include "complex.cpp"
using namespace std;


int main()
{
	Complex x(2, 1);
	Complex y(3, 2);
	Complex sum = x + y;
	Complex difference = x - y;
	Complex product = x * y;
	cout << "Sum: " << sum << endl;
	cout << "Difference: " << difference << endl;
	cout << "Product: " << product << endl;


}
