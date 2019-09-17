#include "date.h"
/****************************************************************
* Date ();
*   Constructor; Creates the date January 1, 2000
*   Parameters: none
*   Return: none
****************************************************************/
Date::Date()
{
	month = 1;
	monthName = name(month);
	day = 1;
	year = 2000;
}

/****************************************************************
* Date(unsigned m, unsigned d, unsigned y);
*   Constructor; Creates month number, day, year with parameters
*   Parameters: 
*   	unsigned m        : month
*   	unsigned d        : day
*   	unsigned y        : year
*   Return: none
****************************************************************/
Date::Date(unsigned m, 	// month
		   unsigned d, 	// day
		   unsigned y)	// year
{
	int invalid = 0;
	if (m < 1)
	{
		invalid = 1;
		month = 1;
	}


	else
		month = m;


	monthName = name(month);
	day = d;
	year = y;

	if (d > 31)
	{
		invalid = 1;
		day = daysPerMonth(m, y);
	}
	else if (d < 1)
	{
		invalid = 1;
		day = 1;
	}

	if (invalid == 1)
	{
		cout << "Invalid date values: Date corrected to "
			 << month << "/" << day << "/" << year << "."
    	     << endl;
	}

}
/****************************************************************
* Date(const string &mn, unsigned d, unsigned y);
*   Constructor; creates month name, day, year with parameters
*   Parameters: 
*   	const string  &mn :
*   	unsigned d        :
*   	unsigned y        :
*   Return: none
****************************************************************/
Date::Date(const string &mn, 	// string month
		   unsigned d, 			// day
		   unsigned y)			// year
{
	int invalid_month = 0;	// checks invalid month input
	int invalid_day = 0;	// checks invalid day input

	month = number(mn);
	if (month == 13)
	{
		invalid_month = 1;
		month = 1;
		monthName = name(month);
		day = 1;
		year = 2000;
	}

	else
	{
		monthName = name(month);
		day = d;
		year = y;
	}

	if (d > 31)
	{
		invalid_day = 1;
		day = daysPerMonth(month, y);
	}

	else if (d < 1)
	{
		invalid_day = 1;
		day = 1;
	}

	if (invalid_day == 1)
	{
		cout << "Invalid date values: Date corrected to "
			 << month << "/" << day << "/" << year << "."
    	     << endl;
	}
	else if (invalid_month == 1)
	{
		cout << "Invalid month name: the Date was set to "
			 << month << "/" << day << "/" << year << "."
			 << endl;
	}
}

/**********************************************************
*
* FUNCTION printNumeric
*_________________________________________________________
* This function prints the numeric version of the date
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   	None
*
* POST-CONDITIONS
*     This function will output the numeric version of the
*     date object
***********************************************************/
void Date::printNumeric() const
{
	cout << month << "/" << day << "/" << year;
}

/**********************************************************
*
* FUNCTION printAlpha
*_________________________________________________________
* This function prints the alphnumeric version of the date
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   	None
*
* POST-CONDITIONS
*     This function will output the numeric version of the
*     date object
***********************************************************/
void Date::printAlpha() const
{
	cout << monthName << " " << day << ", " << year;
}

/**********************************************************
*
* FUNCTION isLeap
*_________________________________________________________
* This function tests for leap year 
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   	year: unsigned numeric year
*
* POST-CONDITIONS
* 	This function returns a boolean. True if leap year
* 	and false if not.
***********************************************************/
bool Date::isLeap(unsigned year) const
{

	if ( (year % 4 == 0) && (year % 100 != 0) )
		return true;
	else if ( (year % 100 == 0) && (year % 400 == 0) )
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}

/**********************************************************
*
* FUNCTION daysPerMonth
*_________________________________________________________
* This function returns the number of days allowed in a 
* 	given month
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   	m: month
*   	y: year
*
* POST-CONDITIONS
* 	Returns the number of days allowed in a given month
***********************************************************/
unsigned Date::daysPerMonth(unsigned m,		// month
		                    unsigned y) 	// year
	                        const
{
	if (m == 2)
	{
		if (isLeap(y))
			return 29;
		else if (!isLeap(y))
			return 28;
	}
	else
	{
		if (m == 8)
			return 31;
		else if (m % 2 == 0)
			return 30;
		else
			return 31;
	}
	return 0;
}

/**********************************************************
*
* FUNCTION name
*_________________________________________________________
* This function returns the name of a given month
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   	m: month
*
* POST-CONDITIONS
* 	Returns the name of a given month
***********************************************************/
string Date::name(unsigned m) const
{
	string month[12];

	month[0] = "January";
	month[1] = "February";
	month[2] = "March";
	month[3] = "April";
	month[4] = "May";
	month[5] = "June";
	month[6] = "July";
	month[7] = "August";
	month[8] = "September";
	month[9] = "Octobor";
	month[10] = "November";
	month[11] = "December";

	return month[m - 1];
}

/**********************************************************
*
* FUNCTION number
*_________________________________________________________
* Returns the number of a given named month
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   	mn: string month
*
* POST-CONDITIONS
* 	Returns the number of a given named month
***********************************************************/
unsigned Date::number(const string &mn) const
{

	if (mn == "January")
		return 1;
	else if (mn == "February")
		return 2;
	else if (mn == "March")
		return 3;
	else if (mn == "April")
		return 4;
	else if (mn == "May")
		return 5;
	else if (mn == "June")
		return 6;
	else if (mn == "July")
		return 7;
	else if (mn == "August")
		return 8;
	else if (mn == "September")
		return 9;
	else if (mn == "Octobor")
		return 10;
	else if (mn == "November")
		return 11;
	else if (mn == "December")
		return 12;
	else 
		return 13;
}
