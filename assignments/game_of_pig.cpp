
/**************************************************************************
 *	AUTHOR	        : Eric Yun
 *	ASSIGNMENT # 4  : Game of Pig - Monte Carlo Method
 *	CLASS	        : CS 002
 *	SECTION         : MTRF: 7:00a - 12p
 *	Due Date        : June 28, 2019	
 **************************************************************************/
#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;
/**************************************************************************
 *
 * GAME OF PIG - MONTE CARLO METHOD
 *
 *--------------------------------------------------------------------------
 * This program will help you simulate the probability of gaining a 
 * 		particular score on a single turn
 *--------------------------------------------------------------------------
 * INPUT:
 * 		hold_score  :	user input on what value to hold at
 * 		simulations :	number of simulations to run
 *
 * OUTPUT:
 * 		hold_score  :   five scores incrementing by 1 from base.
 * 		probabilites:   respective probabilities for each hold_score
 ***************************************************************************/
// Returns single dice roll
int roll_dice() {
	return rand() % 6 + 1;
}

// Calculates and prints the scores and their respective probabilities
void roll_probability(int hold_score, int simulations) {

	// local variables
	int i;							// variable for for-loop
	int roll;						// store dice roll				
	int score;						// store incremementing score value
	map<int, double> score_map;		// key/value to hold score and score 
									// frequency

	// initialize score_map to have minimum of six probability outputs.
	score_map.insert(pair<int,float>(hold_score    , 0));
	score_map.insert(pair<int,float>(hold_score + 1, 0));
	score_map.insert(pair<int,float>(hold_score + 2, 0));
	score_map.insert(pair<int,float>(hold_score + 3, 0));
	score_map.insert(pair<int,float>(hold_score + 4, 0));
	score_map.insert(pair<int,float>(hold_score + 5, 0));


	// PROCESSING -- updates score_map with score and score frequency
	srand(333);										
	for (i = 0; i < simulations; i++) {
		roll = roll_dice();
		score = 0;
		if (roll == 1)
			score_map[score]++;
		else if (roll > 1) {
			score += roll;
			while (score > 0 && score < hold_score) {
				roll = roll_dice();
				if (roll == 1)
					score = 0;
				else
					score += roll;
			}
			score_map[score]++;
		}
	}
	
	// OUTPUT -- prints the table containing the scores and probabilites
	cout << "Score\t" << "Estimated Probability" << endl;
	for (auto elem : score_map) {
		cout << elem.first 
			 << "\t" 
			 << fixed 
			 << elem.second / simulations 
			 << endl; 
	}
}
	
int main()
{
	// variables
    int hold_score;		// desired hold score from user
	int simulations;    // desired number of times user would like to 
						// run the simulation

	// INPUT -- get desired hold score and number of simulations from user
    cout << "What value should we hold at? ";
    cin  >> hold_score;
    cout << endl;
    cout << "Hold-at-N turn simulations? ";
    cin  >> simulations;
    cout << endl;

	// OUTPUT -- prints table containing their scores and probabilites
    roll_probability(hold_score, simulations);
}
