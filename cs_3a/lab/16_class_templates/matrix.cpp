#include "matrix.h"

template <class T>
Matrix<T>::Matrix()
{
	for (int i = 0; i < MAXROWS; i++)	
	{
		for (int j = 0; j < MAXCOLS; j++)
		{
			array[i][j] = 0;
		}
	}
}

template <class T>
void Matrix<T>::printMatrix() const
{

	for (int i = 0; i < MAXROWS; i++)	
	{
		for (int j = 0; j < MAXCOLS; j++)
		{
			cout << array[i][j];
		}
		cout << endl;
	}
}

template <class T>
ostream& operator<<(std::ostream& out, const Matrix<T> m)
{
	for (int i = 0; i < MAXROWS; i++)	
	{
		for (int j = 0; j < MAXCOLS; j++)
		{
			cout << m.array[i][j];
		}
		cout << endl;
	}
	return out;
}

