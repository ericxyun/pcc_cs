#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix<int> m;
	Matrix<int> n;
	m.setElement(1, 2, 3);
	n.setElement(2, 3, 1);
	cout << n;
}

