
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab 11	 : Intro to 2D Arrays 
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
 *
 * INTRO TO 2D ARRAYS
 *
 *--------------------------------------------------------------------------
 * This program will do matrix addition and matrix multiplication arrays
 * 		2D arrays
 *--------------------------------------------------------------------------
 * INPUT:
 * 		ex   : exercise number
 * 		sumA : first matrix for addition
 * 		sumB : second matrix for addition
 * 		multA: first matrix for multiplication
 * 		multB: second matrix for multiplication
 *
 * OUTPUT:
 * 		Matrix Addition Results
 * 		Matrix Multiplication Results
 *
 ***************************************************************************/

// global variables
const int M = 2; 	// Addition Matrix -row
const int N = 3;   	// Addition Matrix column
const int Q = 2;    // First Multiplication Matrix - row
const int R = 3; 	// Second Multiplication Matrix - row
const int S = 3;    // Second Multiplication Matrix - column

// FUNCTION Prototypes
/**************************************************************************
 * matrixAdd
 * 		This function will take in two 2D arrays as inputs and print the 
 * 		resulting matrix addition.
 ***************************************************************************/
void matrixAdd(const int a[][N], const int b[][N], int result[][N]);

// FUNCTION Prototypes
/**************************************************************************
 * matrixMult
 * 		This function will take in two 2D arrays as inputs and print the 
 * 		resulting matrix multiplication.
 ***************************************************************************/
void matrixMult(const int a[][R], const int b[][S],  int result[][S]);

int main()
{
	// INPUT - get the exercise number
	int ex;
	cout << "Which exercise? ";
	cin >> ex;
	cout << endl;

	if (ex == 1)
	{
		// variables
		int sumA[M][N]; 		// first matrix for addition
		int sumB[M][N]; 		// second matrix for addition
		int sumResult[M][N];    // result matrix for addition

		// INPUT - get the two matrices from user input
		cout << "Enter Matrix A: ";
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> sumA[i][j];
			}
		}
		cout << "Enter Matrix B: ";
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> sumB[i][j];
			}
		}

		// PROCESSING - Add the two matrices
		matrixAdd(sumA, sumB, sumResult);

		// OUTPUT - print results
		int count;
		count = 0; 		// counter for printing three numbers per line

		cout << "Res: " << endl;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				 cout << sumResult[i][j] << " ";
				 count++;
				 if (count == 3)
				 {
					cout << endl;
					count = 0;
				 }
			}
		}
	}


	else if (ex == 2)
	{
		// variables
		int multA[Q][R]; 		// first matrix for multiplication
		int multB[R][S]; 		// second matrix for multiplication
		int multResult[Q][S]; 	// result matrix for multiplication
		
		// INPUT - get the two matrices from user input
		cout << "Enter Matrix A(size 2x3): ";
		for (int i = 0; i < Q; i++)
		{
			for (int j = 0; j < R; j++)
			{
				cin >> multA[i][j];
			}
		}

		cout << "Enter Matrix B(size 3x3): ";
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < S; j++)
			{
				cin >> multB[i][j];
			}
		}
		
		// PROCESSING - multiply the two matrices
		matrixMult(multA, multB, multResult);

		// OUTPUT - print the resulting matrix
		int count; 		
		count = 0; 		// counter for printing three numbers per line

		cout << "Res: " << endl;
		for (int i = 0; i < Q; i++)
		{
			for (int j = 0; j < S; j++)
			{
				 cout << multResult[i][j] << " ";
				 count++;
				 if (count == 3)
				 {
					cout << endl;
					count = 0;
				 }
			}
		}
	}
}

/************************************************************************
 * 
 * FUNCTION matrixAdd
 * 	
 *-----------------------------------------------------------------------
 * This function will take in two 2D arrays as inputs and print the 
 * 		resulting matrix addition.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		- Three declared int array with size 3 by 3:
 * 			- two for addition with user input values
 * 			- one to store results
 *
 * POST-CONDITIONS
 * 		- the calculations made with two arrays with input values will
 * 			be stored in the result array
 *
*************************************************************************/
void matrixAdd(const int a[][N], const int b[][N],  int result[][N])
{

	// calculating the matrix addition
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			result[i][j] = a[i][j] + b[i][j];
	}


}


/************************************************************************
 * 
 * FUNCTION matrixMult
 * 	
 *-----------------------------------------------------------------------
 * This function will take in two 2D arrays as inputs and print the 
 * 		resulting matrix multiplication.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		- Three declared arrays:
 * 			- matrix 1: Q by R
 * 			- matrix 2: R by S
 * 			- result: Q by S
 *
 * POST-CONDITIONS
 * 		- the calculations made with two arrays with input values will
 * 			be stored in the result array
 *
*************************************************************************/
void matrixMult(const int a[][R], const int b[][S],  int result[][S])
{
	// PROCESSING - calculating the matrix multiplication
	for (int i = 0; i < Q; i++)
	{
		for (int j = 0; j < S; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < R; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}

}


