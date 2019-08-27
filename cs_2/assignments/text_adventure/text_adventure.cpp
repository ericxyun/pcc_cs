
/**************************************************************************
 *	AUTHOR	         : Eric Yun
 *	ASSIGNMENT #7	 : Text Adventure 
 *	CLASS	         : CS 002
 *	SECTION          : MTRF: 7:00a - 12p
 *	Due Date         : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
/**************************************************************************
 *
 * TEXT ADVENTURE
 *
 *--------------------------------------------------------------------------
 * This program is a game that involves choosing between four doors to pass
 * 		through. The doors can lead to: a monster room, genie room, picture
 * 		room, or an exit. Each room will have different functions.
 * 		- Monster: Loose items
 * 		- Genie  : Gain items
 * 		- Picture: Shows picture
 * 		- Exit   : Exits room
 * 		
 *--------------------------------------------------------------------------
 * INPUT:
 * 		name       : user name
 * 		monsterName: name of monster
 * 		direction  : one of four character inputs (N/E/S/W)
 *
 * OUTPUT:
 * 		numBananas: number of bananas
 * 		numOranges: number of oranges
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

// FUNCTION Prototypes
/****************************************************************************
 * statusMessage
 * 		This function prints the current counts of banans and oranges
 ***************************************************************************/
void statusMessage(string name,       // INPUT - user name
		           int& numBananas,   // current number of bananas
				   int& numOranges);  // current number of oranges

/****************************************************************************
 * monsterRoom
 * 		This function inputs takes the current count of bananas and oranges 
 * 		then decreases both values to 0.
 ***************************************************************************/
void monsterRoom(string name,         // INPUT - user name
		         string monsterName,  // INPUT - monster name
		         int& numBananas,     // current number of bananas
				 int& numOranges);    // current number of oranges

/****************************************************************************
 * genieRoom
 * 		This function inputs takes the current count of bananas and oranges 
 * 		then increase the values by 2 and 1, respectively.
 ***************************************************************************/
void genieRoom(int& numBananas, int& numOranges);

/****************************************************************************
 * exitRoom
 * 		This function ends the program and outputs the total count of 
 * 		bananas and oranges
 ***************************************************************************/
void exitRoom(int& numBananas, int& numOranges);

/****************************************************************************
 * drawPictures
 * 		This function outputs a picture of R2D2
 ***************************************************************************/
void drawPicture(string name, int& numBananas, int& numOranges);

/****************************************************************************
 * randomNum
 * 		This function generates a random number between 0 and 1
 ***************************************************************************/
int randomNum();

/****************************************************************************
 * alignMap
 * 		This function takes in a declared map and maps the direction 
 * 		with its respective alignment, depending on an input of 0 or 1
 * 		- 0: Alignment 0
 * 		- 1: Alignment 1
 ***************************************************************************/
void alignMap(map<char, string>& align);


int main()
{
	// variables
	string name; 				// INPUT - user name
	string monsterName; 		// INPUT - monster name
	string door; 				// map to room type
	char direction; 			// INPUT - direction character
	int numOranges; 			// number of oranges
	int numBananas; 			// number of bananas
	int random; 				// stores random number between 0 and 1
	map<char, string> align;    // maps direction charcater to room type


	// Randomly choose an alignment
	srand(500);

	// initlize number of items carried
	numBananas = 5;
	numOranges = 3;

	// INPUT - get user name and monster name.
	cout << "Please enter your name: ";
	cin >> name;
	cout << endl;

	cout << "Name your scariest monster: ";
	cin >> monsterName;
	cout << endl;

	// OUTPUT - prints current information about user and items
	statusMessage(name, numBananas, numOranges);

	// random alignment assignment
	alignMap(align);

	do
	{
		do
		{
			// INPUT - get direction character input from user
			cout << "Pick a door to enter by typing the direction "; 
			cout << "it is in (N/E/S/W): ";
			cin >> direction;
			cout << endl;
		}
		// PROCESSING - gets the direction input and redirects to a room
		while (direction != 'N' &&
			   direction != 'E' &&
			   direction != 'S' &&
			   direction != 'W');

		// door assignment based on character input
		door = align[direction];
		cout << endl;

		if (door == "Monster")
			monsterRoom(name, monsterName, numBananas, numOranges);
		else if (door == "Genie")
		{
			genieRoom(numBananas, numOranges);
			statusMessage(name, numBananas, numOranges);
		}
		else if (door == "Picture")
			drawPicture(name, numBananas, numOranges);
		else if (door == "Exit")
			exitRoom(numBananas, numOranges);

		// random alignment assignemnt
		alignMap(align);

	}
	while (door != "Exit");
}


/************************************************************************
 * 
 * FUNCTION alignMap
 * 	
 *-----------------------------------------------------------------------
 * This function maps one of two possible alignments depending on input 
 * 		of 0 or 1 from the random number generator function
 * 		0: alignment0
 * 		1: alignment1
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		randNum(random): 0 or 1 
 *
 * POST-CONDITIONS
 * 		updates map align to one of two configurations.
 *
*************************************************************************/
void alignMap(map<char, string>& align)
{

	int random; 			// stores a random number between 0 and 1
	
	// initializes a random number
	random = randomNum();

	// PROCESSING - maps variable align to one of two options
	if (random == 0)
	{
		align['N'] = "Monster";
		align['S'] = "Genie";
		align['E'] = "Picture";
		align['W'] = "Exit";
	}

	else 
	{
		align['N'] = "Exit";
		align['S'] = "Monster";
		align['E'] = "Genie";
		align['W'] = "Picture";
	}

}

/************************************************************************
 * 
 * FUNCTION randomNum
 * 	
 *-----------------------------------------------------------------------
 * This function generates a random number between 0 and 1
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Returns 0 or 1
 *
*************************************************************************/
int randomNum()
{
	// return rand() / (RAND_MAX / 2);
	return rand() % 2;
}
/************************************************************************
 * 
 * FUNCTION statusMessage
 * 	
 *-----------------------------------------------------------------------
 * This function takes in the current number of bananas and oranges
 * 		and prints a message that includes their values
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		name      : assigned user name
 * 		numBananas: call by reference number of bananas
 * 		numOranges: call by reference number of oranges 
 *
 * POST-CONDITIONS
 * 		Outputs a messages that prints the user name, number of bananas,
 * 		and the number of oranges
 *
*************************************************************************/
void statusMessage(string name,
		           int& numBananas,
				   int& numOranges)
{
	cout << name << ", you are in a room with 4 doors." << endl;
	cout << endl;
	cout << "You are carrying " << numBananas << " bananas and ";
	cout << numOranges << " oranges." << endl;


}

/************************************************************************
 * 
 * FUNCTION monsterRoom
 * 	
 *-----------------------------------------------------------------------
 * This function inputs takes the current count of bananas and oranges 
 * 		then decreases both values to 0.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		name       : assigned user name
 * 		monsterName: assigned monster name
 * 		numBananas: call by reference number of bananas
 * 		numOranges: call by reference number of oranges 
 *
 * POST-CONDITIONS
 * 		Changes the values of bananas and oranges to 0.
 *
*************************************************************************/
void monsterRoom(string name,         
		         string monsterName, 
				 int& numBananas, 
				 int& numOranges)
{
	cout << "WATCH OUT!!!" << endl;
	cout << monsterName << " attacks you and steals all of your ";
	cout << "bananas and oranges." << endl;

	numBananas = 0;
	numOranges = 0;

	statusMessage(name, numBananas, numOranges);
}

/************************************************************************
 * 
 * FUNCTION genieRoom
 * 	
 *-----------------------------------------------------------------------
 * This function inputs takes the current count of bananas and oranges 
 * 		then increase the values by 2 and 1, respectively.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		numBananas: call by reference number of bananas
 * 		numOranges: call by reference number of oranges 
 *
 * POST-CONDITIONS
 * 		Increases the value of bananas by 2 and value of oranges by 1 
 *
*************************************************************************/
void genieRoom(int& numBananas, int& numOranges)
{
	cout << "!!Poof!! A Genie pops out and grants you ";
	cout << "2 bananas and 1 orange." << endl;
	numBananas += 2;
	numOranges += 1;
}

/************************************************************************
 * 
 * FUNCTION exitRoom
 * 	
 *-----------------------------------------------------------------------
 * This function ends the program and outputs the total count of 
 * 		bananas and oranges
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		numBananas: call by reference number of bananas
 * 		numOranges: call by reference number of oranges 
 *
 * POST-CONDITIONS
 * 		prints the final count of bananas and oranges
 *
*************************************************************************/
void exitRoom(int& numBananas, int& numOranges)
{
	int score; 		// sum of bananas and oranges
	score = numBananas + numOranges;

	// OUTPUT - prints exit message and scores
	cout << "You found the exit!" << endl;
	cout << "Your score is " << score << "(";
	cout << numBananas << " bananas and ";
	cout << numOranges << " oranges)." << endl;
	cout << "Bye bye!!!"<< endl;


}

/************************************************************************
 * 
 * FUNCTION drawPicture
 * 	
 *-----------------------------------------------------------------------
 * This function draws a picture of R2D2
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Outputs a picture of R2D2
 *
*************************************************************************/
void drawPicture(string name, int& numBananas, int& numOranges)
{
	// OUTPUT - draws a picture of R2D2
	cout << "You found a picture!"     << endl;
    cout << "        _--~~--_"         << endl;
    cout << "      /~/_|  |_\\~\\"     << endl;
    cout << "     |____________|"      << endl;
    cout << "     |[][][][][][]|"      << endl;
    cout << "   __| __         |__"    << endl;
    cout << "  |  ||. |   ==   |  |"   << endl;
    cout << " (|  ||__|   ==   |  |)"  << endl;
    cout << "  |  |[] []  ==   |  |"   << endl;
    cout << "  |  |____________|  |"   << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ "   << endl;
    cout << endl;
	statusMessage(name, numBananas, numOranges);
}
