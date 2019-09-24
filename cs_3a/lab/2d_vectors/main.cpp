/*************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #3	 : 2D Array
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : September 23, 2019
 *************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/**************************************************************************
*
* 2D ARRAY
*
*--------------------------------------------------------------------------
* This program will perform addition and multiplication operations on two
* 	vectors
*--------------------------------------------------------------------------
* INPUT:
* 	rows:		number of rows in a matrix
* 	columns:	number of columns in a matrix
* 	matrix:		values in the matrix
*
* OUPUT:
* 	Prints the resulting matrices after the operations
*
**************************************************************************/

/**************************************************************************
 * matrixFill
 * 	This function will initilize the vector
**************************************************************************/
void matrixFill(vector<vector<int>>&v);	            // single vector

/**************************************************************************
 * displayMatrix
 * 	This function will print the values in a vector
**************************************************************************/
void displayMatrix(const vector<vector<int>>&v);	//single vector

/**************************************************************************
 * displayMatrix
 * 	This function will add two vectors
**************************************************************************/
void matrixAddition(const vector< vector<int> >& a, // first vector
    			    const vector< vector<int> >& b, // second vector
                    vector< vector<int> >& c);		// resulting vector

/**************************************************************************
 * matrixMultiplication
 * 	This function will multiply two vectors
**************************************************************************/
void matrixMultiplication(const vector< vector<int> >& a, 	// first vector
    					  const vector< vector<int> >& b, 	// second vector
    					  vector< vector<int> >& c);		// resulting vector
int main()
{
	int rowsA = 0;		// vector 1 row
	int colsA = 0;		// vector 1 column
	int rowsB = 0;		// vector 2 row
	int colsB = 0;		// vector 2 column


	// VECTOR ADDITION
	// INPUT - get row and column
	cout << "Enter the number of rows and columns of the matrices to add: " 
		<< endl;
	cin >> rowsA >> colsA;
	vector<vector<int>> a(rowsA, vector<int>(colsA));
	// PROCESSING - fill vector with user values
	cout << "Enter matrix A: " << endl;
	matrixFill(a);
	// OUTPUT - prints vector
	cout << "For matrix A you entered: " << endl;
	displayMatrix(a);
	// INPUT - get row and column
	cout << "Enter matrix B: " << endl;
	vector<vector<int>> b(rowsA, vector<int>(colsA));
	// PROCESSING - fill vector with user values
	matrixFill(b);
	// OUTPUT - prints vector
	cout << "For matrix B you entered: " << endl;
	displayMatrix(b);
	// PROCESSING/OUTPUT - performs addition
	cout << "sum of A and B is: " << endl;
	vector<vector<int>> c(rowsA, vector<int>(colsA));
	matrixAddition(a, b, c);
	displayMatrix(c);
	cout << "\n\n";

	// VECTOR MULTIPLICATION
	// INPUT - get information for vector multiplication
	cout << "Now for multiplication." << endl;	
	do 
	{
		cout << "Enter the number of rows and columns of matrix A: " << endl;
		cin >> rowsA >> colsA;

		cout << "Enter the number of rows and columns of matrix B: " << endl;
		cin >> rowsB >> colsB;


		if (colsA != rowsB)
		{
			cout << "The number of columns of matrix A must be the same as the "
				 << "number of rows of matrix B." << endl;
		}
	}
	while (colsA != rowsB);
	// PROCESSING - clears previous vector and resizes
	a.clear();
	a.resize(rowsA);
	for (int i = 0; i < rowsA; i++)
		a[i].resize(colsA);
	b.clear();
	b.resize(rowsB);
	for (int i = 0; i < rowsB; i++)
		b[i].resize(colsB);
	c.clear();
	c.resize(rowsA);
	for (int i = 0; i < rowsA; i++)
		c[i].resize(colsB);
	// PROCESSING/OUTPUT - fills vectors and performs multiplciation
	cout << "Enter matrix A: " << endl;
	matrixFill(a);
	cout << "For matrix A you entered: " << endl;
	displayMatrix(a);
	cout << "Enter matrix B: " << endl;
	matrixFill(b);
	cout << "For matrix B you entered: " << endl;
	displayMatrix(b);
	matrixMultiplication(a, b, c);
	cout << "product of A and B is: " << endl;
	displayMatrix(c);
}

/************************************************************************
 * 
 * FUNCTION matrixFill
 * 	
 *-----------------------------------------------------------------------
 * This function will initilize the vector
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	v: vector with predefined dimensions
 *
 * POST-CONDITIONS
 *  Vector values are modified
 *
*************************************************************************/
void matrixFill(vector<vector<int>>&v)		// single vector
{
	int x;	// temp storage for user input
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cin >> x;
			v[i][j] = x;
		}
	}
}

/************************************************************************
 * 
 * FUNCTION displayMatrix
 * 	
 *-----------------------------------------------------------------------
 * This function will print the values in a vector
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	v: vector with predefined dimensions
 *
 * POST-CONDITIONS
 *  Vector values are modified
 *
*************************************************************************/
void displayMatrix(const vector<vector<int>>&v)		// single vector
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

/************************************************************************
 * 
 * FUNCTION matrix Addition
 * 	
 *-----------------------------------------------------------------------
 * This function will add two vectors
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	a: first vector
 * 	b: second vector
 * 	c: result vector
 *
 * POST-CONDITIONS
 * 	Result vector is filled in
 *
*************************************************************************/
void matrixAddition(const vector< vector<int> >& a, 	// vector 1
                    const vector< vector<int> >& b, 	// vector 2
                    vector< vector<int> >& c)			// result vector
{
	for (int i = 0; i < a.size(); i++)	
		for (int j = 0; j < a[0].size(); j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
}

/************************************************************************
 * 
 * FUNCTION functionName
 * 	
 *-----------------------------------------------------------------------
 * This function will multiply two vectors
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	a: first vector
 * 	b: second vector
 * 	c: result vector
 *
 * POST-CONDITIONS
 * 	Result vector is filled in
 *
*************************************************************************/
void matrixMultiplication(const vector< vector<int> >& a, 	// vector 1
                          const vector< vector<int> >& b, 	// vector 2
                          vector< vector<int> >& c)			// result vector
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b[0].size(); j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < a[0].size(); k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
