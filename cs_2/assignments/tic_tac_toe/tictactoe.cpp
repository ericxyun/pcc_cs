/**************************************************************************
 *	AUTHOR	      : Eric Yun
 *	ASSIGNMENT 10 : Tic Tac Toe
 *	CLASS	  	  : CS 002
 *	SECTION  	  : MTRF: 7:00a - 12p
 *	Due Date 	  : July 20, 2019
 **************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
/**************************************************************************
 *
 * TIC TAC TOE
 *
 *--------------------------------------------------------------------------
 * This program emulates the game of tic tac toe.
 * 		- allows two players
 *--------------------------------------------------------------------------
 * INPUT:
 * 		character inputs [a-i]
 *
 * OUTPUT:
 * 		prints updating board has the game is progressing
 *
 ***************************************************************************/
// Global constants
const bool CLEAR_SCREEN = true; 	// clear screen boolean
const int PLAYER1 = 0;				// player 1 representation
const int PLAYER2 = 1;				// player 2 representation

// FUNCTION PROTOTYPES
/**************************************************************************
 * clearScreen
 *		Utilizes an escape character sequence to clear the screen
 ***************************************************************************/
void clearScreen();

/**************************************************************************
 * drawBoard
 * 		Clears the screen and draws the current state of the board
 ***************************************************************************/
void drawBoard(const vector <char> &board);	// current board

/**************************************************************************
 * initVector
 * 		initializes the starting board
 ***************************************************************************/
void initVector(vector <char> &v);	// declared vector to start as board

/**************************************************************************
 * convertPosition
 * 		converts the position into the appropriate vector index
 ***************************************************************************/
int convertPosition(char position);	// user input character

/**************************************************************************
 * validPlacement
 * 		checks to see if user board selection is valid
 ***************************************************************************/
bool validPlacement(const vector <char> &board,  // current board
					int position);				 // converted position

/**************************************************************************
 * getPlay
 * 		returns the index of the vector to convert to 'x' or 'o'
 ***************************************************************************/
int getPlay(const vector <char> &board,  // current board
		    char position);				 // INPUT - character position

/**************************************************************************
 * gameWon
 * 		checks to see which user as won
 ***************************************************************************/
bool gameWon(const vector <char> &board);	// current board

/**************************************************************************
 * boardFull
 * 		checks to see if all spaces on the board has been filled
 ***************************************************************************/
bool boardFull(const vector <char> &board); 	// current board

int main()
{
    // Variables that you may find useful to utilize
    vector <char> board(9);
    int curPlay;		// current player
    int turn = PLAYER1; // Player 1 always goes first and is 'x'
	char position;		// INPUT player position choice

    /// Initialize board to empty state
	initVector(board);

    /// Display empty board
	drawBoard(board);


    /// Play until game is over
	while (!boardFull(board) && !gameWon(board))
	{
        /// Get a play
		do
		{
			cout << "Please choose a position: ";
			cin >> position;
			cout << endl;
		}
		while (!validPlacement(board, position));

        /// Set the play on the board
		if (turn == 0)
			board[getPlay(board, position)] = 'x';
		else if (turn == 1)
			board[getPlay(board, position)] = 'o';
		
        /// Switch the turn to the other player
		if (turn == PLAYER1)
			turn = PLAYER2;
		else 
			turn = PLAYER1;
        
        /// Output the updated board
		drawBoard(board);
	}

    /// Determine winner and output appropriate message
	if (gameWon(board))
	{
		if (turn == 0)
			cout << "Player 2 wins!!\n";
		else if (turn == 1)
			cout << "Player 1 wins!!\n";
	}
	else if (boardFull(board))
		cout << "No one wins.\n";



    return 0;
}
/************************************************************************
 * FUNCTION clearScreen 
 * 	
 *-----------------------------------------------------------------------
 * Utilizes an escape character sequence to clear the screen
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		clears screen
 *
*************************************************************************/
void clearScreen()
{
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;
}


/************************************************************************
 * FUNCTION drawBoard
 * 	
 *-----------------------------------------------------------------------
 * Draws the provided tic-tac-toe board to the screen
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		 board is the tic-tac-toe board that should be drawn
 *
 * POST-CONDITIONS
 * 		screen is cleared and current state of board is printed
 *
*************************************************************************/
void drawBoard(const vector <char> &board)
{
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << board.at(i) << "  |  " << board.at(i + 1) << "  |  "
            << board.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}



/************************************************************************
 * FUNCTION initVector
 * 	
 *-----------------------------------------------------------------------
 * Fills vector with characters starting at lower case a.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		parameters must be a vector
 *
 * POST-CONDITIONS
 * 		vector is initialized to alphabetical order
 *
*************************************************************************/
void initVector(vector <char> &v)
{
	string alphabet; 	// alphabet to fill inital board
	alphabet = "abcdefghi";	

	//fill board
	for (int i = 0; i < alphabet.size(); i++)
		v[i] = alphabet[i];
}


/************************************************************************
 * FUNCTION convertPosition
 * 	
 *-----------------------------------------------------------------------
 * Converts a character representing a cell to associated vector index
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		param must be type char
 *
 * POST-CONDITIONS
 * 		return the integer index in the vector, should be 0 to 
 * 		(vector size - 1)
*************************************************************************/
int convertPosition(char position) 		// the position to be converted 
										// to a vector index
{
	string alphabet = "abcdefghi";	// alphabet to fill initial board

	// PROCESSING - converts players choice (letter) to int index
	for (int i = 0; i < alphabet.size(); i++)
		if (position == alphabet[i])
			return i;
	return -1;
}


/************************************************************************
 * FUNTION validPlacement
 * 	
 *-----------------------------------------------------------------------
 * Predicate function to determine if a spot in board is available.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 *		return true if position's state is available (not marked) AND 
 *		is in bounds
*************************************************************************/
bool validPlacement(const vector <char> &board, // board the current 
												// tic-tac-toe board 
		            int position)               // position is an index 
												// into vector to check 
												// if available
{
	for (int i = 0; i < board.size(); i++)
	{
		if (position == board[i] &&
			position != 'x'      &&
			position != 'o')
			return true;
	}
    return false;
}

/************************************************************************
 * FUNCTION getPlay
 * 	
 *-----------------------------------------------------------------------
 * Acquires a play from the user as to where to put her mark
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		return an integer index in board vector of a chosen available board 
 * 		spot		
 *
*************************************************************************/
int getPlay(const vector <char> &board, // current board
		    char position)				// INPUT - character input
{
	if (validPlacement(board, position))
	{
		return convertPosition(position);
	}
	return -1;
}

/************************************************************************
 * FUNCTION gameWon
 * 	
 *-----------------------------------------------------------------------
 * Predicate function to determine if the game has been won
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		return true if the game has been won, false otherwise
*************************************************************************/
bool gameWon(const vector <char> &board)	// current board
{
	// Horizontal
	if (board[0] == board[1] && board[1] == board[2])
		return true;
	if (board[3] == board[4] && board[4] == board[5])
		return true;
	if (board[6] == board[7] && board[7] == board[8])
		return true;

	// Vertical
	if (board[0] == board[3] && board[3] == board[6])
		return true;
	if (board[1] == board[4] && board[4] == board[7])
		return true;
	if (board[2] == board[5] && board[5] == board[8])
		return true;

	// Diagonal
	if (board[0] == board[4] && board[4] == board[8])
		return true;
	if (board[2] == board[4] && board[4] == board[6])
		return true;
	return false;
}

/************************************************************************
 * FUNCTION boardFull
 * 	
 *-----------------------------------------------------------------------
 * Predicate function to determine if the board is full
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		return true iff the board is full (no cell is available)
*************************************************************************/
bool boardFull(const vector <char> &board) // current board
{
	int count = 0; 		// counter to keep track of 'x' and 'o'
	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] == 'o' ||
			board[i] == 'x')
			count++;
		if (count == board.size())
			return true;
	}
    return false;
}


