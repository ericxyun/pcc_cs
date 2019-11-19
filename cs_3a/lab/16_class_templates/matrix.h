#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
	const int MAXROWS = 2;
	const int MAXCOLS = 3;

	private:
		T array[MAXROWS][MAXCOLS];
		T rows;
		T cols;

	public:
		Matrix();
		void prTMatrix() const;
		ostream& operator<<(std::ostream& out, const Matrix m);
		void setElement(T row, T col, T value);
		void setMatrix(const T[]);
		void setMatrix(const T m[][]);
		Matrix operator+(const Matrix &m);
}
