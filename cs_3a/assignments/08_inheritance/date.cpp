#include "date.h"
/** 
 * PRIVATE FUNCTIONS
 */
Date::Date()
{
	day = 1;
	month = 1;
	cout << name(1) << endl;
	year = 2000;

}
Date::Date(unsigned m, unsigned d, unsigned y)
{}
Date::Date(const string &mn, unsigned d, unsigned y)
{}
bool Date::isLeap(unsigned) const
{}
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{}
string Date::name(unsigned m) const
{
	string months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"};

	return months[m];
}
unsigned Date::number(const string &mn) const
{}

/** 
 * PUBLIC FUNCTIONS
 */
void Date::printNumeric() const
{}
void Date::printAlpha() const
{}
