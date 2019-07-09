/**************************************************************************
 * AUTHOR       : Eric Yun
 * LAB 10       : Arrays - Intro to Noise Signals
 * CLASS        : CS02
 * SECTION      : MTRF: 7a-12p
 * DUE DATE     : 07/09/2019
**************************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
/**************************************************************************
 * 
 * ARRAYS - INTRO TO NOISE SIGNALS
 *
 *_________________________________________________________________________
 * This program will generate and array of random numbers between 4 and 6
 * 		and will calculate the mean and variance for comparison.
 *
 *_________________________________________________________________________
 * INPUTS:
 * 		No user inputs     
 *
 * OUTPUTS:
 * 		This program will output:
 * 			- Theoretical mean
 * 			- Practical mean
 * 			- Theoretical variance
 * 			- Practical mean
 *     
**************************************************************************/

// FUNCTION PROTOTYPES
/**************************************************************************
 * sequence
 * 		This function recieves an empty array and its size and outputs
 * 		fills the array with random numbers between 4 and 10.
**************************************************************************/
void sequence(double seq[], double SIZE);

/**************************************************************************
 * randFLoat
 * 		This function inputs two double variables and generates a random
 * 		number between those two numbers.
**************************************************************************/
double randFloat(double a, double b);

/**************************************************************************
 * practicalMean
 * 		This function takes in an array and its size and returns the 
 * 		practical mean.
**************************************************************************/
double practicalMean(double seq[], double SIZE);

/**************************************************************************
 * theoreticalMean
 * 		This function takes in two double variables and returns the 
 * 		calculated theoretical mean
**************************************************************************/
double theoreticalMean(double a, double b);

/**************************************************************************
 * practicalVariance
 * 		This function takes in three parameters:
 * 			- an array
 * 			- array size
 * 			- calculated practical mean
 * 		Returns the calculated practical variance
**************************************************************************/
double practicalVariance(double seq[], int SIZE, double mean);

/**************************************************************************
 * theoreticalVariance
 * 		This function takes in two double variables and returns the 
 * 		calculated theoretical variance.
**************************************************************************/
double theoreticalVariance(double a, double b);

/**************************************************************************
 * coutTest
 * 		This function prints the results of the calculations
**************************************************************************/
void coutTest(float pMean1, 	// practical mean first array
		      float pMean2, 	// practical mean second array
			  float pVar1, 		// practical variance first array
			  float pVar2, 		// practical variance second array
			  float tMean, 		// theoretical mean
			  float tVar); 		// theorectical variance

int main()
{
	// variables
	double pMean1, pMean2; 			// practical means of arrays
	double pVar1, pVar2; 			// practical variances of arrays
	double tMean; 					// theoretical mean
	double tVar; 					// theoretical variance
	double seq1[100]; 				// array of size 100
	double seq2[10000]; 			// array of size 10000

	// setting random seed to 500
	srand(500);

	// creating two arrays of different sizes
	sequence(seq1, 100);
	sequence(seq2, 10000);

	// PROCESSING
	// practical mean
	pMean1 = practicalMean(seq1, 100);
	pMean2 = practicalMean(seq2, 10000);

	// practical variance
	pVar1 = practicalVariance(seq1, 100, pMean1);
	pVar2 = practicalVariance(seq2, 10000, pMean2);

	// theoretical mean
	tMean = theoreticalMean(4, 10);

	// theoretical variance
	tVar = theoreticalVariance(4, 10);
	
	// OUTPUT - prints the results
	coutTest(pMean1,
			 pMean2,
			 pVar1,
			 pVar2,
			 tMean,
			 tVar);
}

/**************************************************************************
 * FUNCTION coutTest
 *-------------------------------------------------------------------------
 * This function prints the results of the calculations
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		pMean1: results from practicalMean
 * 		pMean2: results from practicalMean
 * 		pVar1 : results from practicalVariance
 * 		pVar2 : results from practicalVariance
 * 		tMean : results from theoreticalMean
 * 		tVar  : results from theoreticalVariance
 *
 * POST-CONDITIONS
 * 		Outputs the results described above.
**************************************************************************/
void coutTest(float pMean1, 	// practical mean first array
		      float pMean2, 	// practical mean second array
			  float pVar1, 		// practical variance first array
			  float pVar2, 		// practical variance second array
			  float tMean, 		// theoretical mean
			  float tVar) 		// theorectical variance
{
	cout << tMean << " ";
	cout << pMean1 << " ";
	cout << tVar << " ";
	cout << pVar1 << endl;

	cout << tMean << " ";
	cout << pMean2 << " ";
	cout << tVar << " ";
	cout << pVar2 << endl;
}

/**************************************************************************
 * FUNCTION sequence
 *   	
 *-------------------------------------------------------------------------
 * This function recieves an empty array and its size and outputs
 * 		fills the array with random numbers between 4 and 10.
 *    
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		seq[]: Declared empty array
 * 		SIZE : assigned size
 *
 * POST-CONDITIONS
 * 		Fills in array with random numbers between 4 and 10
**************************************************************************/
void sequence(double seq[], double SIZE)
{
	for (int i = 0; i < SIZE; i++)
		seq[i] = randFloat(4, 10);
}

/**************************************************************************
 * FUNCTION randFloat
 *   	
 *-------------------------------------------------------------------------
 * This function inputs two double variables and generates a random
 * 		number between those two numbers.
 *    
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		a: lower bound number
 * 		b: upper bound number
 *
 * POST-CONDITIONS
 * 		Returns a random number between 4 and 10
**************************************************************************/
double randFloat(double a, double b)
{
	return a + (static_cast<double>(rand()) / RAND_MAX) * (b -a);
}

/**************************************************************************
 * FUNCTION practicalMean
 *   	
 *-------------------------------------------------------------------------
 * This function takes in an array and its size and returns the 
 * 		practical mean.
 *    
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		seq[]: array result from FUNCTION sequence()
 * 		SIZE : assigned size of array
 *
 * POST-CONDITIONS
 * 		returns the practical mean of the numbers in the array.
**************************************************************************/
double practicalMean(double seq[], double SIZE)
{
	double sum = 0;
	double mean;
	for(int i = 0; i < SIZE; i++)
		sum += seq[i];
	mean = sum / SIZE;
	return mean;
}
	
/**************************************************************************
 * FUNCTION theoreticalMean 
 *   	
 *-------------------------------------------------------------------------
 * This function takes in two double variables and returns the 
 * 		calculated theoretical mean
 *    
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		a: lower bound number
 * 		b: upper bound number
 *
 * POST-CONDITIONS
 * 		returns calculated theoretical mean
**************************************************************************/
double theoreticalMean(double a, double b)
{
	double mean;
	mean = (b + a) / 2;
	return mean;
}


/**************************************************************************
 * FUNCTION practicalVariance 
 * 		seq[]: array result from FUNCTION sequence()
 * 		SIZE : assigned size of array
 *   	
 *-------------------------------------------------------------------------
 * This function takes in three parameters:
 * 	        - an array
 * 			- array size
 * 			- calculated practical mean
 * 		Returns the calculated practical variance
 *    
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		seq[]: array result from FUNCTION sequence()
 * 		SIZE : assigned size of array
 *
 * POST-CONDITIONS
 * 		Returns calculated practical variance
**************************************************************************/
double practicalVariance(double seq[], int SIZE, double mean)
{
	double sum = 0;
	double variance;

	for (int i = 0; i < SIZE; i++)
	{
		sum += pow((seq[i] - mean), 2);
	}
	variance = sum / (SIZE);
	return variance;
}


/**************************************************************************
 * FUNCTION theoreticalVariance
 *   	
 *-------------------------------------------------------------------------
 * This function takes in two double variables and returns the 
 * 		calculated theoretical variance.
 *    
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		a: lower bound number
 * 		b: upper bound number
 *
 * POST-CONDITIOS
 * 		returns calculated theoretical variance
**************************************************************************/
double theoreticalVariance(double a, double b)
{
	double variance;
	variance = ((b-a) * (b-a)) / 12;	
	return variance;
}

