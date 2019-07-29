#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

char UNKNOWN = ' ';					// mark the unknown
const int SIZE = 10;				// size of row and col
const int FLEET_SIZE = 5;			// ship position
const int TOTAL_HIT_COUNT = 17;		// total hits 
const int CARRIER_SIZE = 5;			// carrier total hit
const int BATTLESHIP_SIZE = 4;		// battleship total hit
const int CRUISER_SIZE = 3;			// cruiser total hit
const int SUBMARINE_SIZE = 3;		// submarine total hit
const int DESTROYER_SIZE = 2;		// destroyer total hit
int p1TotalHitCount = 0;			// player 1 hit count
int p2TotalHitCount = 0;			// player 2 hit count

// coordinate on board
struct Point
{
	int rows;	// x axis
	int cols;	// y axis	
	bool operator==(const Point& rhs){return (rows == rhs.rows && cols ==
			rhs.cols);}
};

// individual ship information
struct Ship
{
	string name;			// ship name
	int size;				// size of ship	
	int hitCount;			// hit count per ship	
	vector<Point> space;	// p
};

// player board
struct PlayerBoard
{
	char board[10][10]; 		// board array
	Ship fleet[FLEET_SIZE];		// ship information
};


/**********************************************************************
 * initBoard
 * 		takes in two PlayerBoard objects by reference and calls the 
 * 		setShip function for each ship in fleet
**********************************************************************/
void initBoard(char p1[][SIZE],		// player 1 board array
			   char p2[][SIZE]);	// player 2 board array

/**********************************************************************
 * displayBoards
 * 		takes in two PlayerBoard objects by reference and calls the 
 * 		setShip function for each ship in fleet
**********************************************************************/
void displayBoards(char player[][SIZE],		// player 1 board
			       char comp[][SIZE]);		// player 2 board

/**********************************************************************
 * displayHidden
 * 		This function will hide the opponents UNKNOWN ship placements
**********************************************************************/
void displayHidden(PlayerBoard &origin, 	// origin board
		           PlayerBoard &target);	// target baord

/**********************************************************************
 * setShip
 * 		Takes in the row, index, and orientation information from
 * 		the getValidShipInfo and places the ship row and column
 * 		index appropriately
**********************************************************************/
void setShip(PlayerBoard &, 	// player board
		     int shipIndex);	// ship index 

/**********************************************************************
 * initFleet
 * 		This function takes a PlayerBoard object by reference and calls
 * 		the setShip function for each ship in the fleet.
**********************************************************************/
void initFleet(PlayerBoard &);	// player board


/**********************************************************************
 * getValidShipInfo
 * 		Takes in a PlayerBoard object by reference and an int variable
 * 		that stores the index of the ship that is currently being 
 * 		placed, and places the ship onto the board. Calls the
 * 		setShip function to determine which spots on the 
 * 		board the ship will occupy.
**********************************************************************/
void getValidShipInfo(PlayerBoard &,	//player board
					  int shipIndex);	// ship index

/**********************************************************************
 * spaceOccupied
 *		This function checks if the row and column index is from
 *		user is appropriate.	
**********************************************************************/
bool spaceOccupied(PlayerBoard &, 		// player board
		           int row, 			// INPUT - row index
			 	   int col, 			// INPUT - column index
				   char orientation, 	// INPUT- orientation
				   int shipSize);		// size of ship	

/**********************************************************************
 * switchPlayers
 * 		This function will take in the turn variable by reference
 * 		and switch from player 1 to player 2 and vice versa	
**********************************************************************/
void switchPlayers(int &turn);	// player turn

/**********************************************************************
 * clearScreen();
 *		This function will clear the terminal outputs
**********************************************************************/
void clearScreen();

/**********************************************************************
 * fireShot
 * 		This function will take in the two player boards and fire a 
 * 		target depending whose board is the origin and whose board is
 * 		the target
**********************************************************************/
void fireShot(PlayerBoard &,	// player 1 
		      PlayerBoard &, 	// player 2
			  int turn);

/**********************************************************************
 * isHit
 * 		This function will return a boolean to check is a target has
 * 		successfully been hit
**********************************************************************/
bool isHit(PlayerBoard &,  	// target player
		   int row, 	   	// row index
		   int col);	    // column index

/**********************************************************************
 * targetHit
 * 		This function will return the index of the ship that has been
 * 		hit	
**********************************************************************/
int targetHit(PlayerBoard &,	// player board
		      int row,			// row index
			  int col);			// col index

/**********************************************************************
 * gameOver
 * 		This function returns a boolean to check if a player has won
**********************************************************************/
bool gameOver(PlayerBoard &,	// player 1 
		      PlayerBoard &, 	// player 2	
			  int &turn);		// player turn

/**********************************************************************
 * twoPlayerMode
 * 		The main two player mode function is consolodated into this 
 * 		function
**********************************************************************/
void twoPlayerMode();

/**********************************************************************
 * computerMode
 * 		The main player vs computer mode function is consolodated 
 * 		into this function
**********************************************************************/
void computerMode();

/**********************************************************************
 * initFleetComputer
 * 		This function will automate the ship placement for the 
 * 		computer
**********************************************************************/
void initFleetComputer(PlayerBoard &); // computer board

/**********************************************************************
 * checkInList
 * 		This function checks to see if a Point is in a vector of 
 * 		Points
**********************************************************************/
bool checkInList(vector<Point> &l, 	// vector of Points
		         int row, 			// row index
				 int col);			// col index

/**********************************************************************
 * compFireShot
 * 		This function will fire an individual shot
**********************************************************************/
void compFireShot(PlayerBoard &target,		// target's board
				  int row,					// row index
				  int col,					// col index
				  vector<Point> &); 		// vector of Points

/**********************************************************************
 * compHunt
 * 		This function will random selected a area on the board and 
 * 		fire a shot
**********************************************************************/
void compHunt(PlayerBoard &target, 			// target's board
			  vector<Point> &compMemory,	// vector to store
			  								// computer moves
			  string &compDirection);		// most recent direction

/**********************************************************************
 * compFire
 * 		This function is responsible for how the computer shot is
 * 		fired
**********************************************************************/
void compFire(PlayerBoard &target, 			// target board
		      vector<Point> &compMemory, 	// computer shots
			  string &compDirection,		// last direction
			  int &compMoveCount,			// computer move counter
			  char &fireMode);				// keep track of hunt
											// vs target mode
											
/**********************************************************************
 * displayMenu
 * 		This function will display the main menu
**********************************************************************/
void displayMenu(char &menuSelect);	// INPUT - menu selection

