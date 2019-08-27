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
 * 		row: row index
 * 		col: column index
 * 		orientation: vertical vs. horizontal ship placement
 *
 * OUTPUT:
 * 		Player 1 grid:
 * 		Player 2 grid:
 *
 ***************************************************************************/

int main()
{
	char menuSelect;
	do
	{
		displayMenu(menuSelect);
		if (menuSelect == 'a')
			twoPlayerMode();
		else if (menuSelect == 'b')
			computerMode();
		else if (menuSelect != 'a' || menuSelect != 'b')
			cout << "Please enter a valid input." << endl;
	}
	while (menuSelect != 'a' || menuSelect != 'b');

}

void initBoard(char p1[][SIZE],		// player 1 board
			   char p2[][SIZE])		// player 2 board
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			p1[i][j] = UNKNOWN;
			p2[i][j]   = UNKNOWN;
		}
}

void displayMenu(char &menuSelect)
{
	cout << "BATTLESHIP" << endl;
	cout << endl;
	cout << "a. Player vs. Player" << endl; 
	cout << "b. Player vs. Computer" << endl;
	cout << endl;
	cout << "Please make a selection: ";
	cin.get(menuSelect);

}

/************************************************************************
 * 
 * FUNCTION twoPlayerMode()
 * 	
 *-----------------------------------------------------------------------
 * The main two player mode function is consolodated into this 
 * 		function
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Starts the game in two player mode
 *
*************************************************************************/
void twoPlayerMode()
{
	PlayerBoard p1;		// player 1 board
	PlayerBoard p2;		// player 2 board


	// initialize boards
	initBoard(p1.board, p2.board);
	initFleet(p1);
	initFleet(p2);
	displayBoards(p1.board, p2.board);

	// initialize player 1
	int count = 0;
	cout << "Player 1 set your board." << endl;
	for (int i = 0; i < 5; i++)
	{
		getValidShipInfo(p1, i);
		displayHidden(p1, p2);
		// displayBoards(p1.board, p2.board);
	}

	// initialize player 2
	cout << string(4, '\n');
	cout << "Player 2 set your board." << endl;
	for (int i = 0; i < 5; i++)
	{
		getValidShipInfo(p2, i);
		displayHidden(p2, p1);
		// displayBoards(p1.board, p2.board);
	}


	// initialize turn for both players
	int PLAYER_1 = 1;
	int PLAYER_2 = 2;
	int turn = PLAYER_1;


	// PROCESSING - start game
	do
	{
		if (turn == PLAYER_1)
		{
			displayHidden(p1, p2);
			fireShot(p1, p2, turn);
			displayHidden(p1, p2);
		}

		else if (turn == PLAYER_2)
		{
			displayHidden(p2, p1);
			fireShot(p2, p1, turn);
			displayHidden(p2, p1);
		}
		switchPlayers(turn);
	}
	while (!gameOver(p1, p2, turn));
}



/************************************************************************
 * 
 * FUNCTION gameOver
 * 	
 *-----------------------------------------------------------------------
 * This function returns a boolean to check if a player has won
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The total hitCount of all ships from a player must equal
 * 		totalHitCount
 *
 * POST-CONDITIONS
 * 		Outputs the winner of the game
 *
*************************************************************************/
bool gameOver(PlayerBoard &p1, PlayerBoard &p2, int &turn)
{
	int p1Total;	// player 1 total hit count
	int p2Total;	// player 2 total hit count

	p1Total = 0;
	p2Total = 0;
	
	// PROCESSING - counts the number of hit counts
	for (int i = 0; i < FLEET_SIZE; i++)
	{
		p1Total += p1.fleet[i].hitCount;
	}

	for (int i = 0; i < FLEET_SIZE; i++)
	{
		p2Total = p2Total + p2.fleet[i].hitCount;
	}
	
	// OUTPUT - prints the winner
	if (p1Total == TOTAL_HIT_COUNT ||
		p2Total == TOTAL_HIT_COUNT)
	{
		switchPlayers(turn);
		cout << "Player " << turn << " wins!!!" << endl;
		return true;
	}
	return false;

}

/************************************************************************
 * 
 * FUNCTION fireShot
 * 	
 *-----------------------------------------------------------------------
 * This function will take in the two player boards and fire a 
 * 		target depending whose board is the origin and whose board is
 * 		the target
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Calls the isHit function to execute the hit
 *
*************************************************************************/
void fireShot(PlayerBoard &origin, 	// player taking shot
		      PlayerBoard &target, 	// player receiving shot
		      int turn)				// player turn
{
	char ch;				// INPUT - row char
	int row, col;			// tart hit row and col
	int shipIdx;			// ship index
	int targetHitCount;	    // hit count per ship
	int shipHitCapacity;	// ship hit capacity
	string targetShipName;	// ship name

	// INTPUT - gets user input target points
	cout << "Player " << turn << ": \n";
	cout << "Fire a shot: ";
	cin >> ch >> col;
	row = toupper(ch) - 65;
	col = col - 1;
	
	// PROCESSING - calls iHit to execute the hit
	if (isHit(target, row, col))
	{
        shipIdx = targetHit(target, row, col);
        targetHitCount = ++target.fleet[shipIdx].hitCount;
	    shipHitCapacity = target.fleet[shipIdx].size;
		targetShipName = target.fleet[shipIdx].name;

		// OUTPUT - prints the ship name if sunk
		if (targetHitCount == shipHitCapacity)
		{
			cout << "You sunk the " 
				 << targetShipName << "!!!\n";
		}
	}
}

/************************************************************************
 * 
 * FUNCTION targetHit
 * 	
 *-----------------------------------------------------------------------
 * This function will return the index of the ship that has been
 * 		hit	
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Returns the index of the ship that has been hit
 *
*************************************************************************/
// return the index of the ship that has been hit
int targetHit(PlayerBoard &p,	// target player
			  int row,			// row index
			  int col)			// column index
{
	// variables
	int shipSize;	// size of ship
	int targetRow;	// row index
	int targetCol;	// column index

	// PROCESSING - get the index of the ship that has been hit
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

/************************************************************************
 * 
 * FUNCTION isHit
 * 	
 *-----------------------------------------------------------------------
 * This function will return a boolean to check is a target has
 * 		successfully been hit
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Converts an array value to the appropirate value
 * 		
 *
*************************************************************************/
bool isHit(PlayerBoard &p, int row, int col)
{
	// PROCESSING - converts array value
	// ship placement
	if (p.board[row][col] == 'S')
	{
		p.board[row][col] = 'H';
		cout << "You hit a ship!";
		return true;
	}

	// target hit
	else if (p.board[row][col] == 'H')
	{
		cout << "You already hit that target." << endl;
		return false;
	}

	// missed target
	else 
	{
		cout << "You missed." << endl;
		p.board[row][col] = 'M';
	}

	return false;

}

/************************************************************************
 * 
 * FUNCTION switchPlayers
 * 	
 *-----------------------------------------------------------------------
 * This function will take in the turn variable by reference
 * 		and switch from player 1 to player 2 and vice versa	
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Changes the value of turn
 *
*************************************************************************/
void switchPlayers(int &turn)	// player turn
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
 * This function checks if the row and column index is from
 *		user is appropriate.	
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Returns bool to see if space can be used
 *
*************************************************************************/
bool spaceOccupied(PlayerBoard &p, 		// player board
		           int row, 			// INDEX - row index
			 	   int col, 			// INDEX - col index	
				   char orientation, 	// INDEX - orientation
				   int shipSize)		// ship size
{
	// check vertical placement
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

/************************************************************************
 * 
 * FUNCTION setShip
 * 	
 *-----------------------------------------------------------------------
 * Takes in the row, index, and orientation information from
 * 		the getValidShipInfo and places the ship row and column
 * 		index appropriately
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		spaceOccupied Function must return true
 *
 * POST-CONDITIONS
 * 		Player's board will have values changed to 'S'
 *
*************************************************************************/
void setShip(PlayerBoard & p, 	// player board
		     int shipIndex)		// ship fleet index
{
	// PROCESSING - converts array value to 'S'
	for (int i = 0; i < p.fleet[shipIndex].space.size(); i++)
	{
		int r = p.fleet[shipIndex].space[i].rows;
		int c = p.fleet[shipIndex].space[i].cols;
		p.board[r][c] = 'S';
	}
}

/************************************************************************
 * 
 * FUNCTION getValidShipInfo
 * 	
 *-----------------------------------------------------------------------
 * Takes in a PlayerBoard object by reference and an int variable
 * 		that stores the index of the ship that is currently being 
 * 		placed, and places the ship onto the board. Calls the
 * 		setShip function to determine which spots on the 
 * 		board the ship will occupy.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Fills in values in struct PlayerBoards
 *
*************************************************************************/
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
	row = toupper(ch) - 65;
	col = col - 1;
	cout << endl;

	while (row < 0 ||
		   row > 9 || 
		   col < 0 ||
		   col > 9)
	{
		cout << "Enter a valid starting coordinate: " << endl;
		cin >> ch;
		cin	>> col;
		row = toupper(ch) - 65;
		col = col - 1;
		cout << endl;
	}


	cout << "Enter the orientation of your carrier "
		 << "(horizontal(h) or vertical(v)): ";
	cin >> orientation;
	cout << endl;
	
	while (orientation != 'v' && orientation != 'h')
	{
		cout << "Enter a valid orientation: " << endl;
		cin >> orientation;
		cout << endl;
	}


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

/************************************************************************
 * 
 * FUNCTION initFleet 
 * 	
 *-----------------------------------------------------------------------
 * This function takes a PlayerBoard object by reference and calls
 * 		the setShip function for each ship in the fleet.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		struct PlayerBoard.fleet information is filled in 
 *
*************************************************************************/
void initFleet(PlayerBoard &p)		// player board
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

/************************************************************************
 * 
 * FUNCTION displayHidden
 * 	
 *-----------------------------------------------------------------------
 * This function will hide the opponents UNKNOWN ship placements
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Prints board
 *
*************************************************************************/
void displayHidden(PlayerBoard &origin, 	// player board taking shot
		           PlayerBoard &target)		// player receiving shot
{
	PlayerBoard hidden;		// hidden board

	hidden = target;

	// PROCESSING - create board to print
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (hidden.board[i][j] == 'S')
			{
				hidden.board[i][j] = UNKNOWN;
			}
		}

	// OUTPUT - prints board
	displayBoards(origin.board, hidden.board);
}

/************************************************************************
 * 
 * FUNCTION displayBoards
 * 	
 *-----------------------------------------------------------------------
 * takes in two PlayerBoard objects by reference and calls the 
 * 		setShip function for each ship in fleet
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Prints given arrays
 *
*************************************************************************/
void displayBoards(char p1[][SIZE],	// player 1 board
			       char p2[][SIZE])	// player 2 board
{
	// initialize row title
	char row = 'A';
	
	// OUTPUT - heading
	cout << string(18, ' ') << "Your Board";
	cout << string(4, '\t');
	cout << string(12, ' ') << "Enemy Board";
	cout << endl;
	cout << "    ";
	
	// OUTPUT - numbers on top row
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

	// OUTPUt - print first set of dashed lines
	cout << setw(1);
	cout << string(2, ' ');
	cout << string(41, '-');
	cout << string(10, ' ');
	cout << string(41, '-');
	cout << endl;

	// OUTPUT  -print alternating array values and dashed lines
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


/************************************************************************
 * 
 * FUNCTION clearScreen
 * 	
 *-----------------------------------------------------------------------
 *	This function will clear the terminal outputs
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Clears screen
 *
*************************************************************************/
void clearScreen()
{ 
	cout << endl;
	cout << "\033c";
	cout << endl;
}

/************************************************************************
 * 
 * FUNCTION initFleetComputer
 * 	
 *-----------------------------------------------------------------------
 * This function will automate the ship placement for the 
 * 		computer
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Changes PlayerBoard array values
 *
*************************************************************************/
void initFleetComputer(PlayerBoard &c)	// computer player board

{
	struct Array
	{
		vector<int> v[2];
	};

	int row;		        			// random choice row index
	int col; 		        			// random choice col index
	char orientation;					// random choice orientation
	int fleet[] = {5, 4, 3, 3, 2};  	// hold fleet size
	char orientations[] = {'h', 'v'};	// hold orientation options
	int count;							// counter for loop
	vector<Point> l1;					// vector to hold row, col
	vector<Point> l2;					// vector to hold row, col
	vector<Point> l3;					// vector to hold row, col
	vector<Point> lTemp; 				// vector to hold row, col
	Point onePoint;						// single Point variable

	bool check = true;					// bool to exit loop
	int arrCount = 0; 					// counter for l3


	
	// random number between 0 and 9
	for (int i = 0; i < 5; i++)
	{
		do
		{
			row = rand() % 10;
			col = rand() % 10;
			orientation = orientations[rand() % 2];
			count = 0;
			onePoint.rows = row;
			onePoint.cols = col;

			if (orientation == 'v')
			{
				if (row + fleet[i] <= 10)
				{
						for (int j = 0; j < fleet[i]; j++)
						{
							if (i == 0)
							{
								count++;
							}
							else if ((checkInList(l2, onePoint.rows,
										onePoint.cols))
								     && (checkInList(l2, row + j, col)))
								count++;
						}
				}
			}
		    else if (orientation == 'h')
			{
				if (col + fleet[i] <= 10)
				{
					count = 0;
					for (int j = 0; j < fleet[i]; j++)
					{
						if (i == 0)
						{
							count++;
						}
						else if ((checkInList(l2, onePoint.rows, onePoint.cols))
								 && (checkInList(l2, row, col + j)))
							count++;
					}
				}

			}
			if (count == fleet[i])
			{
				check = false;
			}
		}
		while (check == true);
		check = true;

		for (int j = 0; j < fleet[i]; j++)
		{
			if (orientation == 'v')
			{

				l1.push_back({row, col});
				lTemp.push_back({row, col});
				c.fleet[i].space.push_back({row, col});
				c.board[row][col] = 'S';
				row++;
			}
			else if (orientation == 'h')
			{
				l1.push_back({row, col});
				lTemp.push_back({row, col});
				c.fleet[i].space.push_back({row, col});
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

/************************************************************************
 * 
 * FUNCTION checkInList
 * 	
 *-----------------------------------------------------------------------
 * This function checks to see if a Point is in a vector of 
 * 		Points
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Returns bool to check if Point is in vector of Points
 *
*************************************************************************/
bool checkInList(vector<Point> &l, int row, int col)
{
	vector<Point> p; 			// vector of points
	int count = 0;				// counter for loop

	p.push_back({row, col});
	if (l.size() > 0)
	{
		for (int i = 0; i < l.size(); i++)
		{
			if (p[0] == l[i])
			{
				return false;
			}
			else
			{
				count++;
			}
		}
		if (count == l.size())
			return true;
		return false;
	}
	return true;
}
/************************************************************************
 * 
 * FUNCTION compFireShot
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
void compFireShot(PlayerBoard &target,
		          int row,
				  int col,
				  vector<Point> &compMemory)
{
	int lastElem;
	int shipIdx;
	int targetHitCount;
	int shipHitCapacity;
	string targetShipName;

	if (isHit(target, row, col))
	{
        shipIdx = targetHit(target, row, col);
        targetHitCount = ++target.fleet[shipIdx].hitCount;
	    shipHitCapacity = target.fleet[shipIdx].size;
		targetShipName = target.fleet[shipIdx].name;

		if (targetHitCount == shipHitCapacity)
		{
			cout << "You sunk the " 
				 << targetShipName << "!!!\n";
		}
	}
		
}

/************************************************************************
 * 
 * FUNCTION compFire
 * 	
 *-----------------------------------------------------------------------
 * This function is responsible for how the computer shot is
 * 		fired
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Fires shots depending on conditions
 *
*************************************************************************/
void compFire(PlayerBoard &target, 			// target board
		      vector<Point> &compMemory, 	// computer shots
			  string &compDirection,		// last direction
			  int &compMoveCount,			// computer move counter
			  char &fireMode)				// keep track of hunt
											// vs target mode
{
	int x;			// row index
	int y;			// col index	
	int lastElem;	// last element index of compMemeory
	
 
	// PROCESSING - rules for firing
	if (compMemory.size() == 0)
	{
		compHunt(target, compMemory, compDirection);
		return;
	}

	lastElem = compMemory.size() - 1;
	x = compMemory[lastElem].rows;
	y = compMemory[lastElem].cols;

	compHunt(target, compMemory, compDirection);

}

/************************************************************************
 * 
 * FUNCTION compHunt
 * 	
 *-----------------------------------------------------------------------
 * This function will random selected a area on the board and 
 * 		fire a shot
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Changes the player 1 board array avlues
 *
*************************************************************************/
void compHunt(PlayerBoard &target, 			// target's board
			  vector<Point> &compMemory,	// vector to store 
			  								// computer memory
			  string &compDirection)		// computer direction
{
	int row;	// row index
	int col;	// col index

	// PROCESSING - random choice of row and col values
	row = rand() % 10;
	do
	{
		if (row % 2 == 0)
		{
			do 
			{
				col = rand() % 10;
			}
			while ( col % 2 == 0 );
		}
		else if ( row % 2 != 0  )
		{
			do 
			{
				col = rand() % 10;
			}
			while ( col % 2 != 0 );
		}
	}
	while (!checkInList(compMemory, row, col));
	compFireShot(target, row, col, compMemory);
	compMemory.push_back({row, col});
}

/************************************************************************
 * 
 * FUNCTION computerMode
 * 	
 *-----------------------------------------------------------------------
 * The main player vs computer mode function is consolodated 
 * 		into this function
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Starts the game in player vs computer mode
 *
*************************************************************************/
void computerMode()
{
	PlayerBoard p;					// player board
	PlayerBoard c;					// computer board
	vector<Point> compMemory;		// computer play memory
	int compMoveCount = 0;			// counter for computer moves
	string compDirection = " ";		// last direction
	char fireMode = 'H';			// tracker for hunt vs target mode

	// initialize board
	initBoard(p.board, c.board);
	initFleet(p);
	initFleet(c);
	// displayBoards(p.board, c.board);

	// Player 1 board set up
	// cout << "Player 1 set your board." << endl;
	// for (int i = 0; i < 5; i++)
    //	{
    //		getValidShipInfo(p, i);
    //		displayBoards(p.board, c.board);
    //	}
	
	// for (int i = 0; i < FLEET_SIZE; i++)
	//	getValidShipInfo(p, i);

	initFleetComputer(p);
	initFleetComputer(c);
	displayBoards(p.board, c.board);

	// Computer board set up
	
	//	PROCESSING - start game
	// initialize player 1 and computer turn
	int PLAYER = 1;
	int COMPUTER = 2;
	int turn = PLAYER;
	int turnCount = 0;

	do
	{
		if (turn == PLAYER)
		{
			// displayHidden(p, c);
			fireShot(p, c, turn);
			// displayHidden(p, c);
			displayBoards(p.board, c.board);
			cout << string(100, '*') << endl;
			cout << string(100, '*') << endl;
		}

		else if (turn == COMPUTER)
		{
			compFire(p, compMemory, compDirection, compMoveCount, fireMode);
			displayBoards(p.board, c.board);
			// displayHidden(p, c);
			cout << string(100, '*') << endl;
			cout << string(100, '*') << endl;
			
		}
		switchPlayers(turn);
	}
	while (!gameOver(p, c, turn));
}
