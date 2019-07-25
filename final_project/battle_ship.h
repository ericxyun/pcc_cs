#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

char UNKNOWN = ' ';
char MISS = 'M';
char HIT = 'H';
const int SIZE = 10;
const int FLEET_SIZE = 5;
const int TOTAL_HIT_COUNT = 17;
const int CARRIER_SIZE = 5;
const int BATTLESHIP_SIZE = 4;
const int CRUISER_SIZE = 3;
const int SUBMARINE_SIZE = 3;
const int DESTROYER_SIZE = 2;
int p1TotalHitCount = 0;
int p2TotalHitCount = 0;

struct Point
{
	int rows;
	int cols;
};

struct Ship
{
	string name;
	int size;
	int hitCount;
	vector<Point> space;
};

struct PlayerBoard
{
	char board[10][10];
	Ship fleet[FLEET_SIZE];
};


/**********************************************************************
 * initBoard
 * 		takes in two PlayerBoard objects by reference and calls the 
 * 		setShip function for each ship in fleet
**********************************************************************/
void initBoard(char p1[][SIZE],
			   char p2[][SIZE]);

void displayBoards(char player[][SIZE],
			       char comp[][SIZE]);

/**********************************************************************
 * setShip
 * 		Takes in a PlayerBoard object by reference and an int variable
 * 		that stores the index of the ship that is currently being 
 * 		placed, and places the ship onto the board. Calls the
 * 		getValidShipInfo function to determine which spots on the 
 * 		board the ship will occupy.
**********************************************************************/
void setShip(PlayerBoard &, 
		     int shipIndex);

/**********************************************************************
 * initFleet
 * 		This function takes a PlayerBoard object by reference and calls
 * 		the setShip function for each ship in the fleet.
**********************************************************************/
void initFleet(PlayerBoard &);

void getValidShipInfo(PlayerBoard &,
					  int shipIndex);

bool spaceOccupied(PlayerBoard &, 
		           int row, 
			 	   int col, 
				   char orientation, 
				   int shipSize);
void switchPlayers(int &turn);



/**********************************************************************
 * convertAscii
 * 		converts Ascii letter to int row
**********************************************************************/
int convertAscii(int row);

void clearScreen();

void fireShot(PlayerBoard &,
		      PlayerBoard &, 
			  int turn);

bool isHit(PlayerBoard &, int row, int col);

int targetHit(PlayerBoard &,
		      int row,
			  int col);

bool gameOver(PlayerBoard &, PlayerBoard &);
