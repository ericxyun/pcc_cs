#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	cout << "Demonstrating with string matrix:\n\n";
	cout << "Matrix set to first array\n";
	string firstArray[MAXROWS + MAXCOLS + 1] = {"Congra", "y", "ar", "alm", "don", "La"};
	Matrix<string> m1;
	m1.setMatrix(firstArray);
}

