#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	int totalElem = MAXROWS + MAXCOLS + 1;
	cout << "Demonstrating with string matrix:\n\n";

	cout << "Matrix set to first array\n";
	string firstArray[MAXROWS + MAXCOLS + 1] = {"Congra", "y", "ar", "alm", "don", "La"};
	Matrix<string> m1;
	m1.setMatrix(firstArray);
	cout << m1;

	cout << "Matrix incremented by second array\n\n";
	string secondArray[MAXROWS + MAXCOLS + 1] = {"tulations", "ou", "e", "ost", "e", "b!"};
	Matrix<string> m2;
	m2.setMatrix(secondArray);
	cout << m1 + m2;

	cout << "Demonstrating with int matrix\n\n";
	int intArr1[totalElem] = {1, 2, 3, 4, 5, 6};
	int intArr2[totalElem] = {7, 7, 7, 7, 7, 7};



	
}

