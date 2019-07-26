
/**************************************************************************
 *	AUTHOR	         : Eric Yun
 *	FINAL PROJECT	 : Battleship
 *	CLASS	         : CS 002
 *	SECTION          : MTRF: 7:00a - 12p
 *	Due Date         : June 20, 2019	
 **************************************************************************/
#include "battle_ship.h"
#include <fstream>

/**************************************************************************
 *
 * BATTLESHIP
 *
 *--------------------------------------------------------------------------
 * This program emulates the game of Battleship
 *--------------------------------------------------------------------------
 * INPUT:
 *
 * OUTPUT:
 *
 ***************************************************************************/

int main()
{
	computerMode();
}
void computerMode()
{
	PlayerBoard p;
	PlayerBoard c;

	// initialize board
	initBoard(p.board, c.board);
	initFleet(p);
	initFleet(c);
	displayBoards(p.board, c.board);

	// Player 1 board set up
	// cout << "Player 1 set your board." << endl;
	// for (int i = 0; i < 5; i++)
    //	{
    //		getValidShipInfo(p, i);
    //		displayBoards(p.board, c.board);
    //	}
	initFleetComputer(c);
	displayBoards(p.board, c.board);

	// Computer board set up
	
	// TODO: set up vector for computer memory on what 
	//       which of player's target was hit
}

void initFleetComputer(PlayerBoard &c)

{
	srand(time(NULL));
	struct Array
	{
		vector<int> v[2];
	};

	int row;		        			// random choice row index
	int col; 		        			// random choice col index
	char orientation;					// random choice orientation
	int fleet[] = {5, 4, 3, 3, 2};  	// hold fleet size
	char orientations[] = {'h', 'v'};	// hold orientation options
	int count;
	vector<Point> l1;
	vector<Point> l2;
	bool check = true;

	vector<Point> lTemp;
	vector<Point> l3;

	
	int arrCount = 0; 	// counter for l3
	// random number between 0 and 9
	for (int i = 0; i < 5; i++)
	{
		do
		{
			row = rand() % 10;
			col = rand() % 10;
			orientation = orientations[rand() % 2];
			count = 0;

			if (orientation == 'v')
				if (row + fleet[i] <= 10)
				{
					int count1 = 0;
					for (int j = 0; j < fleet[i]; j++)
					{
						if (i == 0)
							count++;
						else
						{
							for (int k = 0; k < l2.size(); k++)
								if ((row + j != l2[k].rows) &&
									(col != l2[k].cols)     &&
									(row != l2[k].rows)     &&
									(col != l2[k].cols))
									count1++;
						}
					}
					if (count1 == l2.size())
						count++;
				}
		    else if (orientation == 'h')
			{
				if (col + fleet[i] <= 10)
				{
					count = 0;
					for (int j = 0; j < fleet[i]; j++)
					{
						if (i == 0)
							count++;
						else
						{
							for (int k = 0; k < l2.size(); k++)
							{
							
									if ((row != l2[k].rows)    &&
									   (col + j != l2[k].cols) &&
									   (row != l2[k].rows)     &&
									   (col != l2[k].cols))
											count++;
							}
						}
					}
				}

			}
			if (count == fleet[i])
			{
				cout << "Count: " << count << endl;
				check = false;
			}
		}
		while (check == true);
		check = true;

		cout << "Row: " << row << endl;
		cout << "Col: " << col << endl;
		cout << "Orientation: " << orientation << endl;

		for (int j = 0; j < fleet[i]; j++)
		{
			if (orientation == 'v')
			{

				l1.push_back({row, col});
				lTemp.push_back({row, col});
				c.board[row][col] = 'S';
				row++;
			}
			else if (orientation == 'h')
			{
				l1.push_back({row, col});
				lTemp.push_back({row, col});
				c.board[row][col] = 'S';
				col++;
			}
		}

		// increment arrCount because push_back was not possible.
	    int x;
		int y;
		for (int j = 0; j < lTemp.size(); j++)
			l3.push_back({lTemp[j].rows, lTemp[j].cols});
		lTemp.clear();

		for (int j = 0; j < l3.size(); j++)
		{
			x = l3[j].rows;
			y = l3[j].cols;

			if (orientation == 'v')
			{
				if (j == 0)
					l2.push_back({x - 1, y});
				if (j == l3.size() - 1)
					l2.push_back({x + 1, y});
				l2.push_back({x, y});
				l2.push_back({x, y - 1});
				l2.push_back({x, y + 1});
			}

			else if (orientation == 'h')
			{
				if (j == 0)
					l2.push_back({x, y - 1});
				if (j == l3.size() - 1)
					l2.push_back({x, y + 1});
				l2.push_back({x, y});
				l2.push_back({x - 1, y});
				l2.push_back({x + 1, y});
			}
		}
	}
}

void twoPlayerMode()
{
	PlayerBoard p1;
	PlayerBoard p2;

	// initialize boards
	initBoard(p1.board, p2.board);
	initFleet(p1);
	initFleet(p2);
	displayBoards(p1.board, p2.board);

	int count = 0;
	// initialize player 1
	cout << "Player 1 set your board." << endl;
	for (int i = 0; i < 5; i++)
	{
		getValidShipInfo(p1, i);
		displayBoards(p1.board, p2.board);
	}

	// initialize player 2
	cout << string(4, '\n');
	cout << "Player 2 set your board." << endl;
	for (int i = 0; i < 5; i++)
	{
		getValidShipInfo(p2, i);
		displayBoards(p1.board, p2.board);
	}

	int x;

	// start game
	int PLAYER_1 = 1;
	int PLAYER_2 = 2;
	int turn = PLAYER_1;


	// hit target
	do
	{
		if (turn == PLAYER_1)
		{
			fireShot(p1, p2, turn);
			displayBoards(p1.board, p2.board);
		}

		else if (turn == PLAYER_2)
		{
			fireShot(p2, p1, turn);
			displayBoards(p1.board, p2.board);
		}
		switchPlayers(turn);
	}
	while (!gameOver(p1, p2, turn));
}


bool gameOver(PlayerBoard &p1, PlayerBoard &p2, int &turn)
{
	int p1Total;
	int p2Total;
	p1Total = 0;
	p2Total = 0;
	
	cout << "Player 1 Stats: " << endl;
	for (int i = 0; i < FLEET_SIZE; i++)
	{
		cout << p1.fleet[i].name << " hit count: "
		     << p1.fleet[i].hitCount << endl;
		p1Total += p1.fleet[i].hitCount;
	}

	cout << endl;
	cout << "Player 2 Stats: " << endl;
	for (int i = 0; i < FLEET_SIZE; i++)
	{
		cout << p2.fleet[i].name << " hit count: "
		     << p2.fleet[i].hitCount << endl;
		p2Total = p2Total + p2.fleet[i].hitCount;
	}
	cout << endl;
	
	cout << "Player 1 total: " << p1Total << endl;
	cout << "Player 2 total: " << p2Total << endl;
	cout << endl;

	if (p1Total == TOTAL_HIT_COUNT ||
		p2Total == TOTAL_HIT_COUNT)
	{
		switchPlayers(turn);
		cout << "Player " << turn << " wins!!!" << endl;
		return true;
	}
	return false;

}

void fireShot(PlayerBoard &origin, 
		      PlayerBoard &target, 
		      int turn)
{
	char ch;				// INPUT - row char
	int row, col;			// tart hit row and col
	int shipIdx;			// ship index
	int targetHitCount;	    // hit count per ship
	int shipHitCapacity;	// ship hit capacity
	string targetShipName;	// ship name

	cout << "Player " << turn << ": \n";
	cout << "Fire a shot: ";
	cin >> ch >> col;
	row = toupper(ch) - 65;
	col = col - 1;
	if (isHit(target, row, col))
	{
        shipIdx = targetHit(target, row, col);
        targetHitCount = ++target.fleet[shipIdx].hitCount;
	    shipHitCapacity = target.fleet[shipIdx].size;
		targetShipName = target.fleet[shipIdx].name;

	//	cout << string(100, '-') << endl;
	//	cout << "Player " << turn << " hit a " << targetShipName << endl;
	//  cout << "shipIdx: " << shipIdx << endl;
	//	cout << "shipHitCapacity: " << shipHitCapacity << endl;
	//  cout << "targetHitCount: " << targetHitCount << endl;

		if (targetHitCount == shipHitCapacity)
		{
			cout << "You sunk the " 
				 << targetShipName << "!!!\n";
		}
	}
}

// return the index of the ship that has been hit
int targetHit(PlayerBoard &p,
			  int row,
			  int col)
{
	int shipSize;
	int targetRow;
	int targetCol;
	for (int i = 0; i < FLEET_SIZE; i++)
	{
		shipSize = p.fleet[i].size;
		for (int j = 0; j < shipSize; j++)
		{
			targetRow = p.fleet[i].space[j].rows;
			targetCol = p.fleet[i].space[j].cols;
			if (row == targetRow &&
				col == targetCol)
				return i;
		}
	}
	return -1;
}

bool isHit(PlayerBoard &p, int row, int col)
{
	if (p.board[row][col] == 'S')
	{
		p.board[row][col] = 'H';
		return true;
	}

	else if (p.board[row][col] == 'H')
	{
		cout << "You already hit that target." << endl;
		return false;
	}
	else 
	{
		cout << "You missed." << endl;
		p.board[row][col] = 'M';
	}

	return false;

}

void switchPlayers(int &turn)
{
	if (turn == 1)
		turn = 2;
	else
		turn = 1;
}
/************************************************************************
 * 
 * FUNCTION spaceOccupied
 * 	
 *-----------------------------------------------------------------------
 * Function description
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		- ship length must not exceed the boundaries of the board
 *
 * POST-CONDITIONS
 *
*************************************************************************/
bool spaceOccupied(PlayerBoard &p, 
		           int row, 
			 	   int col, 
				   char orientation, 
				   int shipSize)
{
	// check vertical placement
	// TODO: checking for out of bounds can be done sooner
	if (orientation == 'v')
	{
		for (int i = 0; i <shipSize; i++)
		{
			if  ((p.board[row][col] != UNKNOWN) ||
				row > 9)
				return true;
			row++;
		}
	}

	// check horizontal placement
	else if (orientation == 'h')
	{
		for (int i = 0; i <shipSize; i++)
		{
			if ((p.board[row][col] != UNKNOWN) ||
				col > 9)
				return true;
			col++;
		}
	}

	return false;
}

void setShip(PlayerBoard & p, 
		     int shipIndex)
{
	for (int i = 0; i < p.fleet[shipIndex].space.size(); i++)
	{
		int r = p.fleet[shipIndex].space[i].rows;
		int c = p.fleet[shipIndex].space[i].cols;
		p.board[r][c] = 'S';
	}
}

void getValidShipInfo(PlayerBoard & p,
					  int shipIndex)
{
	char ch; 			// INPUT - row as char first before conversion
	int row, col;  		// INPUT - row and col for ship position
	char orientation;	// INPUT - ship orientation


	ifstream infile;
	infile.open("test.txt");

//	do 
//	{
//		// INPUT - get necessary values to place ships
//		cout << "Enter the starting coordinates of your "
//			 << p.fleet[shipIndex].name << ": ";
//		infile >> ch;
//		infile	>> col;
//		row = ch - 65;
//		col = col - 1;
//		cout << endl;
//
//		cout << "Enter the orientation of your carrier "
//			 << "(horizontal(h) or vertical(v)): ";
//		infile >> orientation;
//		cout << endl;
//
//		if (spaceOccupied(p,
//						  row,
//						  col,
//						  orientation,
//						  p.fleet[shipIndex].size))
//	    {
//			cout << "Error: Ship placement is outside the board.";
//			cout << endl;
//	    }
//	}
//	while (spaceOccupied(p,
//				         row,
//						 col,
//						 orientation,
//						 p.fleet[shipIndex].size));


	cout << "Enter the starting coordinates of your "
		 << p.fleet[shipIndex].name << ": ";
	cin >> ch;
	cin	>> col;
	row = ch - 65;
	col = col - 1;
	cout << endl;

	cout << "Enter the orientation of your carrier "
		 << "(horizontal(h) or vertical(v)): ";
	cin >> orientation;
	cout << endl;

	if (spaceOccupied(p,
					  row,
					  col,
					  orientation,
					  p.fleet[shipIndex].size))
	{
		cout << "Error: Ship placement is outside the board.";
		cout << endl;
	}

	// determine which spaces will be taken
	// and save to PlayerBoard space
	if (orientation == 'v')
	{
		for (int i = 0; i < p.fleet[shipIndex].size; i++)
		{
			p.fleet[shipIndex].space.push_back({row, col});
			row++;
		}
	}

	else if (orientation == 'h')
	{
		for (int i = 0; i < p.fleet[shipIndex].size; i++)
		{
			p.fleet[shipIndex].space.push_back({row, col});
			col++;
		}

	}
	setShip(p, shipIndex);
	

}

void initFleet(PlayerBoard &p)
{
	p.fleet[0].name = "Carrier";
	p.fleet[0].size = CARRIER_SIZE;
	p.fleet[0].hitCount = 0;

	p.fleet[1].name = "Battleship";
	p.fleet[1].size = BATTLESHIP_SIZE;
	p.fleet[1].hitCount = 0;

	p.fleet[2].name = "Cruiser";
	p.fleet[2].size = CRUISER_SIZE;
	p.fleet[2].hitCount = 0;

	p.fleet[3].name = "Submarine";
	p.fleet[3].size = SUBMARINE_SIZE;
	p.fleet[3].hitCount = 0;

	p.fleet[4].name = "Destroyer";
	p.fleet[4].size = DESTROYER_SIZE;
	p.fleet[4].hitCount = 0;

}


int convertAscii(int row)
{
	return row - 65;
}

// initialize the board
void initBoard(char p1[][SIZE],
			   char p2[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			p1[i][j] = UNKNOWN;
			p2[i][j]   = UNKNOWN;
		}
}

void displayBoards(char p1[][SIZE],
			       char p2[][SIZE])
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
			cout << p1[i][j] << "|";
			cout << " ";
		}

		cout << string(7, ' ');
		cout << row;
		cout << " | ";

		// player 2
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(2) << setfill(' ') << left;
			cout << p2[i][j] << "|";
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


void clearScreen()
{ 
	cout << endl;
	cout << "\033c";
	cout << endl;
}
