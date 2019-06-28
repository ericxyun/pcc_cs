
/**************************************************************************
 *	AUTHOR	      : Eric Yun
 *	LAB # 5       : MORE LOOPS
 *	CLASS	      : CS 002
 *	SECTION       : MTRF: 7:00a - 12p
 *	Due Date      : June 20, 2019	
 **************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
 *
 * MORE LOOPS
 *
 *--------------------------------------------------------------------------
 * Program Description
 *--------------------------------------------------------------------------
 * INPUT:

 * OUTPUT:
 *
 ***************************************************************************/

int main() {
	int ex;
	cout << "Which exercise? ";
	cin >> ex;
	cout << endl;

	if (ex == 1) {
		int i;
		int n1;		// INPUT: first user input
		int n2; 	// INTPUT; second user input
		int sign;	// alternate positive/negative
		int num;	// results
		// for loops
		cout << "Enter beinning and ending numbers, " 
		     << "separated by spaces: " << endl;
		cin >> n1 >> n2;
		cout << endl;
		sign = -1;
		while (n1<= n2) {
			cout << n1 << ", ";
			n1 = sign * n1 * n1;
			sign = sign * -1;
		}
	}
	else if (ex ==2 ) {
		// variables
		int g;	                // user grade input
		int a, b, c, d, f;	// counter for grades

		g = 0; 			// initialize grades to 0
		a = b = c = d = f = 0;  // initialize grade counts
		
		// INPUT -- gets user grade input
		// PROCESSING -- keeps track of grades 
		cout << "Enter one or more grades, or -1 to stop: " 
		     << endl;


		while (g != -1) {
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
	else if (ex == 3) {
		// Coin Flip
		string confirmation;
		int heads;
		int tails;
		int toss;

		confirmation = "yes";
		while (confirmation == "yes") {
				cout << "Toss the coin? ";
				cin >> confirmation;;
				cout << endl;
			if (confirmation == "yes") {
				toss = rand() % 2;
				if (toss == 0) 
					cout << "tails" << endl;
				else 
					cout << "heads" << endl;

			}
		}
	}
}
