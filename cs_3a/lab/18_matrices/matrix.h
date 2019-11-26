#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
using namespace std;

/**
   This class describes a row in a matrix.
*/
class MatrixMisMatchException: public invalid_argument
{
	public:
		MatrixMisMatchException();
		MatrixMisMatchException(string message): 
			get_message(message) {};
		string get_message(string message);

	private:
		string message;
};

class MatrixIndexException: public out_of_range
{
			
};

class Matrix; // Forward definition
class MatrixRow
{
public:
   /**
      Remembers a row for a given matrix.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   MatrixRow(Matrix* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   double& operator[](int j);

private:
   Matrix* mat;
   int i;
};

/**
   This class describes a row in a constant matrix.
*/
class ConstMatrixRow
{
public:
   ConstMatrixRow(const Matrix* m, int s);
   double operator[](int j) const;

private:
   const Matrix* mat;
   int i;
};

/**
   This class describes a 3 x 3 matrix.
*/
class Matrix
{
public:
   Matrix()
   {
	   for (int i = 0; i < (ROWS * COLUMNS); i++)
	   {
		   elements[i] = 0;
	   }
   }

   double& operator()(int i, int j);
   double operator()(int i, int j) const;
   MatrixRow operator[](int i);   
   ConstMatrixRow operator[](int i) const;
   Matrix& operator+=(const Matrix& right);

   static const int ROWS = 3;
   static const int COLUMNS = 3;

private:
   double elements[ROWS * COLUMNS];
};

Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const Matrix& right);
Matrix operator*(double left, const Matrix& right);
Matrix operator*(const Matrix& left, double right);
ostream& operator<<(ostream& left, const Matrix& right);

inline double& Matrix::operator()(int i, int j)
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}

inline double Matrix::operator()(int i, int j) const
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}
   
inline MatrixRow Matrix::operator[](int i) 
{
   return MatrixRow(this, i);
}   

inline ConstMatrixRow Matrix::operator[](int i) const
{
   return ConstMatrixRow(this, i);
}   
   
inline MatrixRow::MatrixRow(Matrix* m, int s) : mat(m), i(s) { }
   
inline double& MatrixRow::operator[](int j)
{
   return (*mat)(i,j);
}   

inline ConstMatrixRow::ConstMatrixRow(const Matrix* m, int s) 
   : mat(m), i(s) { }

inline double ConstMatrixRow::operator[](int j) const
{
   return (*mat)(i, j);
}   

inline Matrix operator*(double left, const Matrix& right)
{
   return right * left;
}

#endif
