#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix<int> m;
	Matrix<int> n;
	m.setElement(1, 2, 2);
	cout << m;
	n.setElement(1, 2, 3);
	cout << n;
	cout << m + n;
}

