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
	cout << m1;

	cout << "Matrix incremented by second array\n\n";
	string secondArray[MAXROWS + MAXCOLS + 1] = {"tulations", "ou", "e", "ost", "e", "b!"};
	Matrix<string> m2;
	m2.setMatrix(secondArray);
	cout << m1 + m2;

	cout << "Demonstrating with int matrix\n\n";
	int intArr1[MAXROWS + MAXCOLS + 1] = {1, 2, 3, 4, 5, 6};
	int intArr2[MAXROWS + MAXCOLS + 1] = {6, 5, 4, 3, 2, 1};
	cout << "Matrix set to first array\n";
	Matrix<int> m3;
	m3.setMatrix(intArr1);
	cout << m3;
	cout << endl;
	cout << "Matrix incremented by second array\n";
	Matrix<int> m4;
	m4.setMatrix(intArr2);
	cout << m3 + m4;

	cout << "Demonstrating with float matrix\n\n";
	float floatArr1[MAXROWS + MAXCOLS + 1] = {1.6, 2.5, 3.4, 4.3, 5.2, 6.1};
	float floatArr2[MAXROWS + MAXCOLS + 1] = {6.1, 5.2, 4.3, 3.4, 2.5, 1.6};
	cout << "Matrix set to first array\n";
	Matrix<float> m5;
	m3.setMatrix(floatArr1);
	cout << m6;
	cout << endl;
	cout << "Matrix incremented by second array\n";
	Matrix<float> m4;
	m4.setMatrix(floatArr2);
	cout << m3 + m4;


	
}

