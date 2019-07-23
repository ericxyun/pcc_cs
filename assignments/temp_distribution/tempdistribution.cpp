
/**************************************************************************
 *	AUTHOR	         : Eric Yun
 *	ASSIGNMENT 9	 : Temperature Distribution
 *	CLASS	         : CS 002
 *	SECTION          : MTRF: 7:00a - 12p
 *	Due Date         : June 20, 2019	
 *************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;
/**************************************************************************
 *
 * TEMPERATURE DISTRIBUTION
 *
 *--------------------------------------------------------------------------
 * This program will model the temperature equilibration of a thin sheet
 * 		of metal using a two dimensional array.
 *--------------------------------------------------------------------------
 * INPUT:
 * 		infile: input file name
 * 			- first row of file contains temperature four values: top, 
 * 			  right, bottom, and left, in that order
 * 			- the second row contains the tolerance threshold between the 
 * 			  temperature difference between the the current and previous 
 * 			  array while in the loop towards equilibration.
 *
 * OUTPUT:
 * 		outfile: output file name to save the results
 *
 **************************************************************************/

// FUNCTION Prototypes
/***************************************************************************
 * printArr
 * 		This function will take in an array as input and print the array.
 **************************************************************************/
void printAndSave(double arr[][8],      	// starting array;
		          ofstream& outfile, 		// file to write to
				  string outputFilename); 	// user inputer output file 
											// name

/***************************************************************************
 * initArr
 * 		This function will take in a declared array and initialize it to
 * 		the starting specifications depending on the values in the input
 * 		file.
 **************************************************************************/
void initArr(double grid[][8], 		// current grid
		     double top, 			// top row values
			 double right, 			// right side values
			 double bottom, 		// bottom row values
			 double left); 			// left side values

/***************************************************************************
 * avgAdjacent
 * 		This function will take the top, right, bottom, and left adjacent 
 * 		cells of a given array and return the average of those four values.
 **************************************************************************/
double avgAdjacent(double grid[][8], 	// current grid
		           int i, 				// ith row of array
				   int j);  			// jth row of array

/***************************************************************************
 * equilibrate
 * 		This function will take the grid and loop through the array and 
 * 		change the replace the values of each cell with the output of 
 * 		the avgAdjacent function.
 **************************************************************************/
void equilibrate(double grid[][8]); 	// current grid

/***************************************************************************
 * copyGrid
 * 		This function will make a copy of the original grid.
 **************************************************************************/
void copyGrid(double grid[][8], 		// current grid
		      double prevGrid[][8]); 	// previous grid

/***************************************************************************
 * maxTolerance
 * 		This function will take in the current grid and the previous grid 
 * 		and output a Boolean:
 * 			true: the max difference between the cells of two arrays is less
 * 				  than the tolerance threshold.
 * 			false: the max difference is greater than the tolerance 
 * 			       threshold
 **************************************************************************/
bool maxTolerance(double grid[][8],  		// current grid
		          double prevGrid[][8], 	// previous grid
				  double tolerance);

int main()
{
	// variables
	double top; 				// INPUT - top row array values
	double right; 				// INPUT - right side array values
	double bottom; 				// INPUT - bottom row array values
	double left; 				// INPUT - left side array values
	double tolerance; 			// INPUT - tolerance threshold
	ifstream infile; 			// reading from file
	ofstream outfile; 			// for saving results to a file
	string inputFilename; 		// INPUT - input file name
	string outputFilename; 		// INPUT - output file name
	double grid[6][8]; 			// current grid
	double prevGrid[6][8];  	// previous grid

	// INPUT - getting the input and output file names from user
	cout << "Enter input file name: " << endl;
	cin >> inputFilename;
	cout << endl;

	cout << "Enter output file name: " << endl;
	cin >> outputFilename;
	cout << endl;

	// store file contents into respective variables
	infile.open(inputFilename);
	infile >> top >> right >> bottom >> left >> tolerance;
	infile.close();

	// initialize array
	initArr(grid, top, right, bottom, left);

	// PROCESSING - perform the equilibration 
	do 
	{
		copyGrid(grid, prevGrid);
		equilibrate(grid);
	}
	while (!maxTolerance(grid, prevGrid, tolerance));

	// OUTPUT - print and save the results
	printAndSave(grid, outfile, outputFilename);

	return 0;
}

/***************************************************************************
 * 
 * FUNCTION initArr
 * 	
 *--------------------------------------------------------------------------
 *This function will take in a declared array and initialize it to
 * 		the starting specifications depending on the values in the input
 * 		file.
 *
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		grid  : declared grid
 * 		top   : value for top row from input file
 * 		right : value for right side from input file
 * 		bottom: value for bottom row from input file
 * 		left  : value for left side from input file
 *
 * POST-CONDITIONS
 * 		Takes the declared grid and fills in respective files from input
 * 		file and fills in the rest of the elements with zeros
 *
****************************************************************************/
void initArr(double grid[][8], 		// current grid
		     double top, 			// INPUT - top row values
			 double right, 			// INPUT - right side values
			 double bottom, 		// INPUT - bottom row values
			 double left) 			// INPUT - left side values
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// insert top row values
			if (i == 0)
				grid[i][j] = top;

			// insert bottom row values
			else if (i == 5)
				grid[i][j] = bottom;

			// insert left side values
			else if (j == 0)
				grid[i][j] = left;

			// insert left side values
			else if (j == 7)
				grid[i][j] = right;
			
			// insert zero for everything else.
			else
				grid[i][j] = 0;
		}
	}
}

/***************************************************************************
 * 
 * FUNCTION printAndSave
 * 	
 *--------------------------------------------------------------------------
 *This function will take in an array as input and print the array.
 *
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		grid: declared array
 * 		outputFilename: user input file name
 *
 * POST-CONDITIONS
 * 		outfile: writes resulting array to file.
 *
****************************************************************************/
void printAndSave(double grid[][8], ofstream& outfile, string outputFilename)
{

	// open file for writing
	outfile.open(outputFilename);

	// OUTPUT - print and write results to file
	int count = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			{
				// save to file
				// outfile << grid[i][j] << string(1, '\t');

				// print to terminal
				cout << grid[i][j] << " ";
				count++;
				if (count == 6)
				{
					outfile << endl;
					cout << endl;
					count = 0;
				}
			}
		}
	}

	outfile.close();
}

/***************************************************************************
 * 
 * FUNCTION equilibrate
 * 	
 *--------------------------------------------------------------------------
 *This function will take the grid and loop through the array and 
 * 		change the replace the values of each cell with the output of 
 * 		the avgAdjacent function.
 *
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		grid: current grid
 *
 * POST-CONDITIONS
 * 		the value of each element is replaced by the average of its four 
 * 		adjacent elements
 *
****************************************************************************/
void equilibrate(double grid[][8]) 		// current grid
{
	double avg;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 7; j++) 
			grid[i][j] = avgAdjacent(grid, i, j);
	}
}

/***************************************************************************
 * 
 * FUNCTION avgAdjacent
 * 	
 *--------------------------------------------------------------------------
 *This function will take the top, right, bottom, and left adjacent 
 * 		cells of a given array and return the average of those four values.
 *
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		grid: current grid
 * 		int i: row index
 * 		int j: column index
 *
 * POST-CONDITIONS
 * 		performs the single function of calculating the average of four
 * 		adjacent elements
 *
****************************************************************************/
double avgAdjacent(double grid[][8], int i, int j)
{
	double sum; 		// accumulate sum of four sides before calculation
	double avg; 		// calculate average

	// PROCESSING - calculate the average of the four adjacent sides
	sum = grid[i - 1][j] + 		// top
		  grid[i][j + 1] +  	// right
		  grid[i + 1][j] + 		// down
		  grid[i][j - 1]; 		// left
	avg = sum / 4;

	return avg;
}

/***************************************************************************
 * 
 * FUNCTION copyGrid
 * 	
 *--------------------------------------------------------------------------
 * This function will make a copy of the original grid.
 *
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		grid    : current grid
 * 		prevGrid: previous grid 
 *
 * POST-CONDITIONS
 * 		makes a duplicate of the grid array and stores in prevGrid
 *
****************************************************************************/
void copyGrid(double grid[][8],  		// current grid
		      double prevGrid[][8]) 	// previous grid
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 1; j < 8; j++)
			prevGrid[i][j] = grid[i][j];
	}
}

/***************************************************************************
 * 
 * FUNCTION maxTolerance
 * 	
 *--------------------------------------------------------------------------
 * This function will take in the current grid and the previous grid 
 * 		and output a Boolean:
 * 			true: the max difference between the cells of two arrays is less
 * 				  than the tolerance threshold.
 * 			false: the max difference is greater than the tolerance 
 *
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		grid     : current grid
 * 		prevGrid : previous grid
 * 		tolerance: user input of tolerance threshold
 *
 * POST-CONDITIONS
 * 		returns a boolean value
 *
****************************************************************************/
bool maxTolerance(double grid[][8],  		// current grid
		          double prevGrid[][8],     // previous grid
				  double tolerance) 		// user input tolerance
{
	double difference; 		// compares the current cell to previous cell
	double max;    			// variable to store the updating max difference

	max = 0.0;

	// PROCESSING - iterates through the arrays and finds the difference
	// 				in the cell values between the current and previous
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			difference = grid[i][j] - prevGrid[i][j];
			if (difference > max)
				max = difference;
		}
	}

	if (max < tolerance)
		return true;
	
	return false;
}

