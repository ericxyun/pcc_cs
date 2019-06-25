/*************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #3	 : Time Calculator
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 *************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
*
*
* TIME CALCULATOR
*
*--------------------------------------------------------------------------
* This program will calculate the amount of each coins needed as change for
* 	an item purchased	
*
*--------------------------------------------------------------------------
* INPUT:
*	ex: excercise number
*	sec: number of seconds
*
* OUPUT:
*	min: calculated number of minutes given sec input
*	hours: calculated number of hours given sec input
*	days: calculated number of days given sec input	
*	
**************************************************************************/
int main()
{
	int ex;
	cout << "Which exercise? " << endl;
	cin >> ex;
	if (ex == 1)
	{
		// variables
		int sec;
		int min;
		int hours;
		int days;
			
		// INPUT --
		cout << "Enter a number of seconds: " << endl;
		cin >> sec;
		
		// PROCESSING --
		min = sec / 60;
		hours = sec / 3600;
		days =  sec / 86400;
	
		// OUTPUT -- 
		// minutes
		if (sec >= 60 && sec < 3600)
		{
			if (min <= 1)
			{
				cout << "There is "
		                     << min 
		                     << " minute in "
		                     << sec
				     << " seconds."
				     << endl;
			}
			else
			{
				cout << "There are "
		                     << min 
		                     << " minutes in "
		                     << sec
				     << " seconds."
				     << endl;
			}	
		}	
		// hours
		else if (sec >= 3600 && sec < 86400)
		{
			if (hours <= 1)
			{
				cout << "There is "
		                     << hours
		                     << " hour in "
		                     << sec
				     << " seconds."
				     << endl;
			}
			else
			{
				cout << "There are "
		                     << hours 
		                     << " hours in "
		                     << sec
				     << " seconds."
				     << endl;
			}	
		}
		// days
		else if (sec >= 86400)
		{
			if (days <= 1)
			{
				cout << "There is "
		                     << days 
		                     << " day in "
		                     << sec
				     << " seconds."
				     << endl;
			}
			else
			{
				cout << "There are "
		                     << days 
		                     << " days in "
		                     << sec
				     << " seconds."
				     << endl;
			}	
		}
		
	}
	else if (ex == 2) 
	{
		// variables
		char response;

		// OUTPUT -- user selectable options
		cout << "What do you want to do tonight?" << endl;
		cout << "a. Go to the movies" << endl;
		cout << "b. Eat out" << endl;
		cout << "c. Hang out at the Mall" << endl;
		cout << "d. Go watch the Dodgers" << endl;
		cin  >> response;
		
		// INPUT -- user inputs
		if (response == 'a' || response == 'A')
		{
		//
			cout << "I know just the movie to see!" << endl;
		}
		else if (response == 'b' || response == 'B')
		{
		//
			cout << "Great! "
			     << "I've been wanting to try that "
                             << "new Tuvaluan restaurant!" << endl;
		}
		else if (response == 'c' || response == 'C')
		{
		//
			cout << "You bring the cash!"	
			     << endl;
		}
		else if (response == 'd' || response == 'D')
		{
		//
			cout << "Take me out to the ball game ..."
                             << endl;
		}
		else 
			cout << "Nothing suits you, then? "
			     << "I guess we'll just stay and program!"
			     << endl;

		return 0;
		
	}
	return 0;

}
