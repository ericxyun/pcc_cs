#include <iostream>
#include <iomanip>
using namespace std;

char UNKNOWN = '3';
const int SIZE = 10;
enum Ship
{
	CARRIER = 5,
	BATTLESHIP = 4,
	CRUISER = 3,
	SUBMARINE = 3,
	DESTROYER = 2
};


void initBoards(char playerHidden[][SIZE],
		       char playerReveal[][SIZE],
			   char compHidden[][SIZE],
			   char compReveal[][SIZE]);

void displayBoards(char playerReveal[][SIZE],
			   char compHidden[][SIZE]);

void initFleet();
void setShip();
void getValidShipInfo();
bool spaceOccupid();


