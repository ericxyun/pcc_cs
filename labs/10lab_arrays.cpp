/*******************************************************************************
 * AUTHOR       : Eric Yun
 * LAB #8       : Functions
 * CLASS        : CS02
 * SECTION      : MTRF: 7a-12p
 * DUE DATE     : 07/08/2019
*******************************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void sequence(double seq[], double SIZE);
double randFloat(double a, double b);
double practicalMean(double seq[], double SIZE);
double theoreticalMean(double a, double b);
double practicalVariance(double seq[], int SIZE, double mean);
double theoreticalVariance(double a, double b);
void coutTest(float pMean1,
		      float pMean2, 
			  float pVar1,
			  float pVar2,
			  float tMean,
			  float tVar);

int main()
{
	double pMean1, pMean2;
	double pVar1, pVar2;
	double tMean;
	double tVar;
	
	srand(500);
	double seq1[100];
	double seq2[10000];

	
	// making the two arrays
	sequence(seq1, 100);
	sequence(seq2, 10000);

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
	coutTest(pMean1,
			 pMean2,
			 pVar1,
			 pVar2,
			 tMean,
			 tVar);

	
	
}
void coutTest(float pMean1,
		      float pMean2, 
			  float pVar1,
			  float pVar2,
			  float tMean,
			  float tVar)
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

// function to make the arrays
void sequence(double seq[], double SIZE)
{
	for (int i = 0; i < SIZE; i++)
		seq[i] = randFloat(4, 10);
}

double randFloat(double a, double b)
{
	return a + (static_cast<double>(rand()) / RAND_MAX) * (b -a);
}

double practicalMean(double seq[], double SIZE)
{
	double sum = 0;
	double mean;
	for(int i = 0; i < SIZE; i++)
		sum += seq[i];
	mean = sum / SIZE;
	return mean;
}
	
// double theoreticalMean()
double theoreticalMean(double a, double b)
{
	double mean;
	mean = (b + a) / 2;
	return mean;
}


// double practicalVariance()
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


// double theoreticalVariance()
double theoreticalVariance(double a, double b)
{
	double variance;
	variance = ((b-a) * (b-a)) / 12;	
	return variance;
}

