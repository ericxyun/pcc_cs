/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab 15	 : Structures - Movie Data
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/**************************************************************************
 *
 * STRUCTURES MOVIE DATA
 *
 *--------------------------------------------------------------------------
 * This program will take in movie information from three different ways
 * 		and will output the results
 *--------------------------------------------------------------------------
 * INPUT:
 *		mov1.title   : movie title
 *		mov1.director: movie director name
 *		mov1.year    : year made
 *		mov1.runTime : move runTime
 *
 * OUTPUT:
 *		outputs the title, director, year, and runtime for each movie 
 *		stored in the array
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

struct MovieData
{
	string title;		// movie title
	string director;	// movie director
	string year;		// year movie was made
	string runTime; 	// move runtime
	string blank;		// variable to hold blank
};

// FUNCTION Prototypes
/**************************************************************************
 * printMovieData
 * 		This function will take in a the user created struct variable
 *		and print its contents
 ***************************************************************************/
void printMovieData(const MovieData &m);

int main()
{
	MovieData mov1[12];		// array to store movies from "movie.txt"
	MovieData mov2;			// variable to hold hardcoded values
	MovieData mov3; 		// variable to hold user input values
	ifstream infile;		// opens movie.txt

	// hard coded values
	mov2.title = "Apollo 13";
	mov1[0].title = mov2.title;
	mov2.director = "Ron Howard";
	mov1[0].director = mov2.director;
	mov2.year = "1995";
	mov1[0].year = mov2.year;
	mov2.runTime = "140";
	mov1[0].runTime = mov2.runTime;

	// INPUT - get movie info from user 
	cout << "Enter Title: ";
	cout << endl;
	getline(cin, mov3.title);
	mov1[1].title = mov3.title;

	cout << "Enter Director: ";
	cout << endl;
	getline(cin, mov3.director);
	mov1[1].director = mov3.director;

	cout << "Enter Year Released: ";
	cout << endl;
	getline(cin, mov3.year);
	mov1[1].year = mov3.year;

	cout << "Enter Running Time (in minutes): ";
	cout << endl;
	getline(cin, mov3.runTime);
	mov1[1].runTime = mov3.runTime;

	// INTPUT - get movie info from "movie.txt"
	infile.open("movies.txt");
	for (int i = 2; i < 12; i++)
	{
		getline(infile, mov1[i].title);
		getline(infile, mov1[i].director);
		getline(infile, mov1[i].year);
		getline(infile, mov1[i].runTime);
		getline(infile, mov1[i].blank);
	}

	// OUTPUT - print contents of the array
	for (int i = 0; i < 12; i++)
	{
		printMovieData(mov1[i]);
	}
}

/************************************************************************
 * 
 * FUNCTION printMovieData
 * 	
 *-----------------------------------------------------------------------
 * This function will take in a the user created struct variable
 *		and print its contents
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		m: user define struct variable
 *
 * POST-CONDITIONS
 *		outputs the content of the variable.
 *
*************************************************************************/
void printMovieData(const MovieData &m)
{
	cout << "Title: " << m.title << endl;
	cout << "Director: " << m.director << endl;
	cout << "Year released: " << m.year << endl;
	cout << "Running Time: " << m.runTime << endl;
	cout << endl;
}
