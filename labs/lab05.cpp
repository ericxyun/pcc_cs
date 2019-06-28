
/**************************************************************************
 *	AUTHOR	      : Eric Yun
 *	LAB # 5       : MORE LOOPS
 *	CLASS	      : CS 002
 *	SECTION       : MTRF: 7:00a - 12p
 *	Due Date      : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;
/**************************************************************************
 *
 * MORE LOOPS
 *
 *--------------------------------------------------------------------------
 * This program involves three exercises:
 *	1: three loops to generate a series of numbers given a starting
 * 	   and ending number.
 *	2: takes in a user inputs as integers and bins them into
 * 	   academic letter grades
 * 	3: coin flip generator
 *--------------------------------------------------------------------------
 * INPUT:
 *	Exercise1:
 *	    num1        : lower range of number
 *	    num2        : upper range of number	
 *	Exercise2:
 *	    g           : integer numeric academic grade
 *	Exercise3:
 *          confirmation: "yes" or "no" for coin flips
 *
 * OUTPUT:
 *	Exercise1:
 *	    prints three different sequences of numbers
 *	Exercise2:
 *          prints binned academic letter grades
 *	Exercise3:
 *	    prints "heads" or "tails"
 *
 ***************************************************************************/

int main() {
	// variables
	int ex;	 		// excercise number

	// INPUT - asks user for exercise number
	cout << "Which exercise? ";
	cin >> ex;
	cout << endl;

	// Exercise 1: for loops
	if (ex == 1) {
	    int num1; 		// first user input
	    int num2;		// second user input 
            int i;		// variable for for-loop

	     // INPUT - gets the two user inputs
	     cout << "Enter beginning and ending numbers, separated by "
		  << "space: " << endl;
	     cin >> num1 >> num2 ;

	     // PROCESSING/OUTPUT - outputs ordered numerical sequence
	     for (i=num1; i <= num2; i++) {
		     cout << i;
		     if (i < num2)
		     cout << ", " ;
	     }
	     cout << endl;
	     
	     // INPUT - gets the two user inputs
	     cout << "Enter beginning and ending numbers, separated by "
		  << "space: " << endl;
	     cin >> num1 >> num2 ;

	     // PROCESSING/OUTPUT - outputs odd sequences
	     for (i=num1; i <= num2; i+=2) {
		     cout << i ;
		     if (i < num2-1)
		     cout << ", " ;
	     }
	     cout << endl;

	     // INPUT - gets the two user inputs
	     cout << "Enter the beginning and largest positive numbers, " 
		     "separated by space: ";
	     cin >> num1 >> num2 ;
	     cout << endl;

	     // PROCESSING/OUTPUT - outputs alternating sign sqaures
	    for (i=num1; i*2 <= num2; i *= -2) {
		    cout << i;
		    cout << ", " ;
	    }
	    if (i==num2)
	    cout << num2;
	    cout << endl;
	}

	// Exercise 2: Sentinel-controlled loops
	else if (ex ==2 ) {
		// variables
		int g;	                // user grade input
		int a, b, c, d, f;	// counter for grades

		g = 0; 			// initialize grades to 0
		a = b = c = d = f = 0;  // initialize grade counts
		
		// INPUT -- gets user grade input
		// PROCESSING -- keeps track of grades 
		while (g != -1) {
			cout << "Enter one or more grades, or -1 to stop: " 
			     << endl;
			cin >> g;
			if (g >= 90) 
				a++;
			else if (g >= 80 && g < 90)
				b++;
			else if (g >= 70 && g < 80)
				c++;
			else if (g >= 60 && g < 70)
				d++;
			else if (g >= 0 && g < 60)
				f++;
		}

		// OUTPUT -- prints grade breakdown
		cout << "The grades breakdown is: " << endl;
		cout << "As: " << a << endl; 
		cout << "Bs: " << b << endl;
		cout << "Cs: " << c << endl;
		cout << "Ds: " << d << endl;
		cout << "Fs: " << f << endl;
	}

	// Exercise 3: Coin Flip
	else if (ex == 3) {
		string confirmation;	// user responses
		int toss;		// random coin toss

		confirmation = "yes";
		while (confirmation == "yes") {

		// INPUT -- asks user for coin toss
				cout << "Toss the coin? ";
				cin >> confirmation;;
				cout << endl;

		// PROCESSING/OUTPUT -- prints random coin results
			if (confirmation == "yes") {
				toss = rand() % 2;
				if (toss == 0) 
					cout << "heads" << endl;
				else 
					cout << "tails" << endl;

			}
		}
	}
}
