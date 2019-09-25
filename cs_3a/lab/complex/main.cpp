#include <iostream>
#include "complex.h"
#include "complex.cpp"
using namespace std;


int main()
{
	Complex c(2, 1);
	Complex d(3, 2);
	Complex e = c + d;
	e.display();

}
