#include "battle_ship.h"

int main()
{
	char playerHidden[SIZE][SIZE];
	char playerReveal[SIZE][SIZE];
	char compHidden[SIZE][SIZE];
	char compReveal[SIZE][SIZE];

	initBoards(playerHidden,
			   playerReveal,
			   compHidden,
			   compReveal);
	displayBoards(playerHidden,
				  compHidden);
}

// initialize the board
void initBoards(char playerHidden[][SIZE],
		        char playerReveal[][SIZE],
			    char compHidden[][SIZE],
			    char compReveal[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			playerHidden[i][j] = UNKNOWN;
			playerReveal[i][j] = UNKNOWN;
			compHidden[i][j]   = UNKNOWN;
			compHidden[i][j]   = UNKNOWN;
		}
}

void displayBoards(char playerReveal[][SIZE],
			       char compReveal[][SIZE])
{
	// initialize row title
	char row = 'A';
	
	// print heading
	cout << string(18, ' ') << "Your Board";
	cout << string(4, '\t');
	cout << string(12, ' ') << "Enemy Board";
	cout << endl;
	cout << "    ";
	
	// print numbers on top row
	int count = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << j + 1;
			count++;

			// remove one space before the "10" on the top column
			if (count == 9)
			{
				cout << string(2, ' ');
				count = -1;
			}
			else
				cout << string(3, ' ');
		}
		cout << string(11, ' ');
	}
	cout << endl;

	// print first set of dashed lines
	cout << setw(1);
	cout << string(2, ' ');
	cout << string(41, '-');
	cout << string(10, ' ');
	cout << string(41, '-');
	cout << endl;

	// print rows: alternating array values and dashed lines
	for (int i = 0; i < SIZE; i++)
	{
		cout << row;
		cout << " | ";

		// player 1 
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(2) << setfill(' ') << left;
			cout << playerReveal[i][j] << "|";
			cout << " ";
		}

		cout << string(7, ' ');
		cout << row;
		cout << " | ";

		// player 2
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(2) << setfill(' ') << left;
			cout << compReveal[i][j] << "|";
			cout << " ";
		}

		cout << endl;
		row++;
		
		cout << setw(1);
		cout << string(2, ' ');
		cout << string(41, '-');
		cout << string(10, ' ');
		cout << string(41, '-');
		cout << endl;
	}
}
