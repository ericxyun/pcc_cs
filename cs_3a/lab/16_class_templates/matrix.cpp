#include "matrix.h"

template <class T>
Matrix<T>::Matrix()
{
	for (int i = 0; i < MAXROWS; i++)	
		for (int j = 0; j < MAXCOLS; j++)
		{
			array[i][j] = 0;
			cout << array[i][j];
		}
		cout << endl;
}

