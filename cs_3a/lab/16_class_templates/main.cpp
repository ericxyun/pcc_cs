#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix<int> m;
	Matrix<int> n;
	m.setElement(1, 2, 2);
	n.setElement(1, 2, 3);
	cout << m + n;
}

