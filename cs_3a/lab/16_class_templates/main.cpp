#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix<int> m;
	Matrix<int> n;
	n.setElement(1, 2, 3);
	int array[2][3] = {{1, 2, 3},
						{4, 5, 6}};
	m.setMatrix(array);
	cout << m;
}

