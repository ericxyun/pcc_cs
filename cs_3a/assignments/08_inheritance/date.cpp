/** 
 * PRIVATE FUNCTIONS
 */
Date::Date()
{
	day = 1;

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
{}
unsigned Date::number(const string &mn) const
{}

/** 
 * PUBLIC FUNCTIONS
 */
void Date::printNumeric() const
{}
void Date::printAlpha() const
{}
