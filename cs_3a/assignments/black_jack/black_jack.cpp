
/**************************************************************************
 *	AUTHOR       : Eric Yun
 *	ASSIGNMENT 1 : Black Jack
 *	CLASS	     : CS 002
 *	SECTION      : MTRF: 7:00a - 12p
 *	Due Date     : September 2, 2019	
 **************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
/**************************************************************************
 *
 * BLACK JACK
 *
 *--------------------------------------------------------------------------
 * Program Description
 *--------------------------------------------------------------------------
 * INPUT:
 *
 * OUTPUT:
 *
 *--------------------------------------------------------------------------

 ***************************************************************************/

// FUNCTION Prototypes
/**************************************************************************
 * convert_suite
 * 		This function will take in an integer and convert it into their 
 * 		respective suite.
 ***************************************************************************/
string convert_suite(int num);	// randomly generated number

/**************************************************************************
 * convert_rank
 * 		This function will take in an integer and convert it into their
 * 		respective rank
 ***************************************************************************/
string convert_rank(int num);	// randomly generated number

/**************************************************************************
 * draw_card
 * 		This function will randomly generate a card and output the value
 * 		of the card.
 ***************************************************************************/
int draw_card(string &card,			// name of card
		      int drawer_points);	// number of points the player has

/**************************************************************************
 * process_results
 * 		This function will 
 ***************************************************************************/
void process_results(int player_total, 		// total number of player points
		             int dealer_total, 		// total number of dealer points
					 int &player_funds, 	// total player money
					 int &bet);				// input - bet amount

int main()
{
	int player_total;	// player points
	int dealer_total;	// dealer points
	int player_funds;	// player money
	int bet;			// input - bet amount
	int count;			// for loop counter
	char another_card;	// input - ask for another card
	char another_game;	// input - ask to play again
	int bust;			// check if hand is bust
	string card;		// card name
	
	// initialize variables
	srand(333);
	count = 0;
	player_funds = 100;
	bust = 0;
	player_total = 0;
	dealer_total = 0;
	bool end_game;
	end_game = 0;

	// Start game
	do 
	{
		// PROCESSING - check to see that player has between $0 and $1000
		if (player_funds == 0)
		{
			cout << "You have $0. GAME OVER." << endl;
			break;
		}
		else if (player_funds > 1000)
		{
			cout << "You have exceeded $1000. GAME OVER." << endl;
			break;
		}

		// Player turn
		do
		{
			if (count == 0)
			{
				cout << "You have $" << player_funds << ". ";
				cout << "Enter bet: ";
				do
				{   
					cin >> bet;
					cout << endl;
					if (bet > player_funds)
					{
						cout << "Not enough funds. " << endl;
						cout << "Enter another bet again: ";
					}
				}
				while ((bet > player_funds));
				player_funds -= bet;

				cout << "Your cards are: " << endl;
				player_total = draw_card(card , player_total);
				cout << "  " + card << endl;
				player_total += draw_card(card , player_total);
				cout << "  " + card << endl;
				count++;
			}

			else if (count > 0)
			{
				do
				{
					if (count == 1)
					{
						cout << "Your total is " << player_total << ". ";
					}

					else if (count > 1)
					{
						player_total += draw_card(card , player_total);
						cout << "You draw a: " << endl;
						cout << "  " + card << endl;
						cout << "Your total is " << player_total << ". ";
					}


					if (player_total < 21)
					{
						cout << "Do you want another card (y/n)? ";
						cin >> another_card;
						cout << endl;
						if (another_card == 'n')
						{
							cout << "\n\n";
						}
					}

					else if (player_total > 20)
					{
						end_game = 1;
						another_card = 'n';
					}

					if (another_card == 'n')
					{
						end_game = 1;
					}
					count++;
				}
				while (another_card == 'y');
			}
		}
		while (end_game == 0);

		// Dealer turn
		if (player_total < 21)
		{
			count = 0;
			do
			{
				if (count == 0)
				{
					cout << "The dealer's cards are: " << endl;
					dealer_total += draw_card(card, dealer_total);
					cout << "  " << card << endl;
					dealer_total += draw_card(card, dealer_total);
					cout << "  " << card << endl;
					cout << "The dealer's total is " << dealer_total << ".";
					cout << endl;
					count++;
				}
				else
				{
					dealer_total += draw_card(card, dealer_total);
					cout << "The dealer draws a card." << endl;
					cout << "  " << card << endl;
					cout << "The dealer's total is " << dealer_total << ".";
					cout << endl;
					count++;
					// 
				}
			}
			while (dealer_total <= 16);

			process_results(player_total, dealer_total, player_funds, bet);


		}
		if (player_total > 21)
		{
			cout << "You busted!" << endl;
			cout << endl;
			if (player_funds == 0)
				cout << "You have $0. GAME OVER.\n";
		}
		if (player_funds > 0)
		{
			cout << "Play again? (y/n): ";
			cin >> another_game;
			cout << endl;
		}
		if (another_game == 'y')
		{
			// Reset game
			player_total = 0;
			dealer_total = 0;
			count = 0;
			bet = 0;
			end_game = 0;
		}
	}
	while (another_game == 'y');
}

/************************************************************************
 * 
 * FUNCTION process_results
 * 	
 *-----------------------------------------------------------------------
 * This function will take in various information about both players and
 * 		will add and deduct the respective winning or losing amount.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		player_total: total number of player points
 * 		dealer_total: total number of dealer points
 * 		player_funds: total player's money
 * 		bet: player's bet
 *
 * POST-CONDITIONS
 * 		this function will change the values of the player_funds and bet.
 *
*************************************************************************/
void process_results(int player_total, 		// total number of player points
		             int dealer_total, 		// total number of dealer points
					 int &player_funds, 	// total player money
					 int &bet)				// input - bet amount
{
	if ((player_total > 21) || (dealer_total > 21))
	{
		if ((player_total > 21) && (dealer_total > 21))
		{
			cout << "Both Player and Dealer Busts!" << endl;
		}
		else if ((player_total < 21) && (dealer_total > 21))
		{
			cout << "Player wins! Dealer Busts!" << endl;
			player_funds += bet;
		}
		else if ((player_total > 21) && (dealer_total < 21))
		{
			cout << "Dealer wins! Player Busts!" << endl;
			player_funds -= bet;
		}
	}
	else if (player_total > dealer_total)
	{
		cout << "You win $" << bet << "." << endl;
		cout << endl;
		player_funds += 2 * bet;
	}
	else if (player_total < dealer_total)
	{
		cout << "Too bad.  You lose $" << bet << "." << endl;
		cout << endl;
	}

}

/************************************************************************
 * 
 * FUNCTION convert_suite
 * 	
 *-----------------------------------------------------------------------
 * This function will take in an integer and convert it into their 
 * 		respective suite.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		num: randomly generated number
 *
 * POST-CONDITIONS
 * 		passes a randomly generated integer and outputs its respective 
 * 		suite
 *
*************************************************************************/
string convert_suite(int num) // random integer
{
	if (num == 0)
		return "Spades";
	else if (num == 1)
		return "Clubs";
	else if (num == 2)
		return "Diamonds";
	else 
		return "Hearts";
}

/************************************************************************
 * 
 * FUNCTION convert_rank
 * 	
 *-----------------------------------------------------------------------
 * This function will take in an integer and convert it into their
 * 		respective rank
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		num: randomly generated number
 *
 * POST-CONDITIONS
 * 		pass in a randomly generated integer and outputs the outputs the
 * 		respective ranking.
 *
*************************************************************************/
string convert_rank(int num) // random integer
{
	if (num == 1)
		return "Ace";
	else if (num == 2)
		return "Two";
	else if (num == 3)
		return "Three";
	else if (num == 4)
		return "Four";
	else if (num == 5)
		return "Five";
	else if (num == 6)
		return "Six";
	else if (num == 7)
		return "Seven";
	else if (num == 8)
		return "Eight";
	else if (num == 9)
		return "Nine";
	else if (num == 10)
		return "Ten";
	else if (num == 11)
		return "Jack";
	else if (num == 12)
		return "Queen";
	else if (num == 13)
		return "King";
	return 0;
}

/************************************************************************
 * 
 * FUNCTION draw_card
 * 	
 *-----------------------------------------------------------------------
 * This function will randomly generate a card and output the value
 * 		of the card.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		&card: passes card info
 * 		drawer_points: reads current drawer's points to determine
 * 					   value of ace
 *
 * POST-CONDITIONS
 * 		passes card info by reference, returns card numerical value
 *
*************************************************************************/
int draw_card(string &card,			// name of card
		      int drawer_points)	// number of points the player has
{
	int rank;			// value of card
	int suite;			// card's suite
	int rank_min = 1;	// minimum rank value
	int rank_max = 13;	// maximum rank value
	int suite_min = 0;	// minimum suite value
	int suite_max = 3;	// maximum suite value

	// PROCESSING - random number generation
	rank = rand() % (rank_max - rank_min + 1 ) + rank_min;
	suite = rand() % (suite_max - suite_min + 1 ) + suite_min;
	card =  convert_rank(rank) + " of " + convert_suite(suite);

	
	// Ace
	if (rank == 1)
	{
		if (drawer_points <= 11)
			return 11;
		else
			return 1;
	}

	// Face cards
	else if ((rank >= 11) && (rank <= 13))
		return 10;

	// Number cards
	else
		return rank;
}


