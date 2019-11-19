#include <iostream>
using namespace std;
const int MAXROWS = 2;
const int MAXCOLS = 3;

template <class T>
class Matrix
{

	private:
		T array[MAXROWS][MAXCOLS];
		T rows;
		T cols;

	public:
		Matrix()
		{
			for (int i = 0; i < MAXROWS; i++)	
			{
				for (int j = 0; j < MAXCOLS; j++)
				{
					array[i][j] = 0;
				}
			}
		}
		void printMatrix() const
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
		friend ostream& operator<<(std::ostream& out, const Matrix m)
		{
			for (int i = 0; i < MAXROWS; i++)	
			{
				for (int j = 0; j < MAXCOLS; j++)
				{
					out << m.array[i][j];
				}
				out << endl;
			}
			return out;
		}
		void setElement(T row, T col, T value)
		{
			array[row][col] = value;	
		}
		void setMatrix(const T a[])
		{
				
		}
		void setMatrix(const T m [MAXROWS][MAXCOLS])
		{

		}

		Matrix operator+(const Matrix &m)
		{
			for (int i = 0; i < MAXROWS; i++)
			{
				for (int j = 0; j < MAXCOLS; j++)
				{
					array[i][j] += m.array[i][j];
				}
			}
		}
		return this;
};
