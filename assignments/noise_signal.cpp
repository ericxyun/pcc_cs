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
 * There are four parts to this program:
 *		Part 1: Takes sequence arrays of size 100 and 10,000 between the
 *				the numbers 4 and 10 and compares their respective mean and
 *              variance the the theorectical mean and theoretical 
 *				variance.
 *		Part 2: Generates two sequences of arrays of size 500 with 
 *				same mean(4) but differing variances(0.5 and 2) and 
 * 				compares the results as done in part 1.
 *  	Part 3: This is a variation of part two except the means are -4.0 
 *				and 0.0 and the variance is 3.0 for both
 * 		Part 4:
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
void sequence(double seq[], double SIZE, double a, double b);

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

/**************************************************************************
 * rand_mv
 * 		This function takes in a mean value and a variance value from the 
 * 		user, calculates the range and generates a random floating point 
 * 		number using the FUNCTION randFloat().
**************************************************************************/
double rand_mv(double mean, double var);

int main()
{
// PART I
	// variables
	double pMean1, pMean2; 			// practical means of arrays
	double pVar1, pVar2; 			// practical variances of arrays
	double tMean; 					// theoretical mean
	double tVar; 					// theoretical variance
	double seq1[100]; 				// array of size 100
	double seq2[10000]; 			// array of size 10000
	double a1, b1; 					// two ranges for first array
	double a2, b2; 					// two ranges for second array

	// setting random seed to 500
	srand(500);

	// creating two arrays of different sizes
	sequence(seq1, 100, 4, 10);
	sequence(seq2, 10000, 4, 10);

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

// PART 2
	double seq3[500]; 			// first array
	double seq4[500]; 			// second array

	// the solved unknowns
	// 		tMean = 4; tVar = 0.5
	//		tMean = 4; tVar = 2
	a1 = 4 - (sqrt(6)/2);
	b1 = 4 + (sqrt(6)/2);
	a2 = 4 - sqrt(6);
	b2 = 4 + sqrt(6);

	// two sequences
	sequence(seq3, 500, a1, b1);
	sequence(seq4, 500, a2, b2);

	// PROCESSING - calculate mean/variance for first array
	pMean1 = practicalMean(seq3, 500);
	pVar1  = practicalVariance(seq3, 500, practicalMean(seq3, 500));
	tMean = theoreticalMean(a1, b1);
	tVar  = theoreticalVariance(a1, b1);

	// OUTPUT - print results of first array
	cout << tMean << " ";
	cout << pMean1 << " ";
	cout << tVar << " ";
	cout << pVar1 << endl;
	
	// PROCESSING - calculate mean/variance for second  array
    pMean2 = practicalMean(seq4, 500);
	pVar2  = practicalVariance(seq4, 500, practicalMean(seq4, 500));
	tMean = theoreticalMean(a2, b2);
	tVar  = theoreticalVariance(a2, b2);
	
	// OUTPUT - print results of second array
	cout << tMean << " ";
	cout << pMean2 << " ";
	cout << tVar << " ";
	cout << pVar2 << endl;
	cout << endl;

// PART 3
	double seq5[500]; 			// first array
	double seq6[500]; 			// second array

	// the solved unknowns
	// 		tMean = 3.0; tVar = 0.0
	//		tMean = -4.0; tVar = 0.0
	a1 = -3;
	b1 = 3;
	a2 = -7;
	b2 = -1;

	// two sequences
	sequence(seq5, 500, a1, b1);
	sequence(seq6, 500, a2, b2);

	
	// PROCESSING - calculate mean/variance for first array
	pMean1 = practicalMean(seq5, 500);
	pVar1  = practicalVariance(seq5, 500, practicalMean(seq5, 500));
	tMean = theoreticalMean(a1, b1);
	tVar  = theoreticalVariance(a1, b1);

	// OUTPUT - print results of first array
	cout << tMean << " ";
	cout << pMean1 << " ";
	cout << tVar << " ";
	cout << pVar1 << endl;
	
	// PROCESSING - calculate mean/variance for second array
    pMean2 = practicalMean(seq6, 500);
	pVar2  = practicalVariance(seq6, 500, practicalMean(seq6, 500));
	tMean = theoreticalMean(a2, b2);
	tVar  = theoreticalVariance(a2, b2);

	// OUTPUT - print results of first array
	cout << tMean << " ";
	cout << pMean2 << " ";
	cout << tVar << " ";
	cout << pVar2 << endl;
	cout << endl;


// PART 4
	//variables
	double mean; 		// user input mean
	double variance; 	// user input variance

	// INPUT - get mean and variance values from user input
	cout << "Enter Mean: " << endl;
	cout << "Enter Variance: " << endl;
	cin >> mean >>  variance;

	// OUTPUT - print random floating point.
	cout << rand_mv(mean, variance) << endl;



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
	return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
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
	cout << endl;
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
void sequence(double seq[], double SIZE, double a, double b)
{
	for (int i = 0; i < SIZE; i++)
		seq[i] = randFloat(a, b);
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
 * POST-CONDITIONS
 * 		returns calculated theoretical variance
**************************************************************************/
double theoreticalVariance(double a, double b)
{
	double variance;
	variance = ((b-a) * (b-a)) / 12;	
	return variance;
}

/**************************************************************************
 * FUNCTION randMV
 *   	
 *-------------------------------------------------------------------------
 * This function takes in a mean value and a variance value from the user,
 * 		calculates the range and generates a random floating point number 
 * 		using the FUNCTION randFloat().
 *    
 *-------------------------------------------------------------------------
 * PRE-CONDITIONS
 *		mean:     user input mean
 *		variance: user input variance
 *		output from the randFloat function.
 *
 * POST-CONDITIONS
 * 		returns a random floating point number
**************************************************************************/
double rand_mv(double mean, double var)
{
	// PROCESSING - get the two range to feed into randFloat
	double a = mean - sqrt(3 * var);
	double b = mean + sqrt(3 * var);

	// OUTPUT - print the resulting two values
	cout << a << " " << b << endl;
	return randFloat(a, b);
}
