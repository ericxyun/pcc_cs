#include <iostream>
#include <string>
using namespace std;

/****************************************************************
* Date Class
*   This class represents a Date object. It manages four attributes
*   day, month, monthName, and year.
****************************************************************/
class Date
{
	private:
		unsigned day;
		unsigned month;
		string monthName;
		unsigned year;

		/**************
		 ** MUTATORS **
		 **************/

		/*******************************************************************
		 * bool isLeap(unsigned) const;
		 *
		 *   Mutator; This method will check to see if a year is a leap year
		 *------------------------------------------------------------------
		 *   Parameter: year (unsigned) 
		 *------------------------------------------------------------------
		 *   Return: none
		 *******************************************************************/
		bool isLeap(unsigned) const;

		/*******************************************************************
		 * unsigned daysPerMonth(unsigned m, unsigned y) const;
		 *
		 *   Mutator; This method will return the number of days in a given
		 *   	month
		 *------------------------------------------------------------------
		 *   Parameter: 
		 *   	month (unsigned)
		 *   	year (unsigned)
		 *------------------------------------------------------------------
		 *   Return: int
		 *******************************************************************/
		unsigned daysPerMonth(unsigned m, unsigned y) const;

		/*******************************************************************
		 * string name(unsigned m) const;
		 *
		 *   Mutator; This method will return the string name of the given
		 *   	month
		 *
		 *------------------------------------------------------------------
		 *   Parameter: month (unsigned) 
		 *------------------------------------------------------------------
		 *   Return: string
		 *******************************************************************/
		string name(unsigned m) const;

		/*******************************************************************
		 * unsigned number(const string &mn) const;
		 *
		 *   Mutator; This method will return the numerical month
		 *
		 *------------------------------------------------------------------
		 *   Parameter: mn string
		 *------------------------------------------------------------------
		 *   Return: string
		 *******************************************************************/
		unsigned number(const string &mn) const;

	public:
		/******************************
		 ** CONSTRUCTOR & DESTRUCTOR **
		 ******************************/

		Date();
		Date(unsigned m, unsigned d, unsigned y);
		Date(const string &mn, unsigned d, unsigned y);

		/***************
		 ** ACCESSORS **
		 ***************/

		/*******************************************************************
		 * void printNumeric() const;
		 *
		 *   Accessor; This method will print the numerical form of the Date
		 *   	object
		 *
		 *------------------------------------------------------------------
		 *   Parameter: None
		 *------------------------------------------------------------------
		 *   Return: None
		 *******************************************************************/
		void printNumeric() const;

		/*******************************************************************
		 * void printAlpha() const;
		 *
		 *   Accessor; This method will print the Alphanumeric form of the
		 *   	Date object
		 *
		 *------------------------------------------------------------------
		 *   Parameter: None
		 *------------------------------------------------------------------
		 *   Return: None
		 *******************************************************************/
		void printAlpha() const;
};

