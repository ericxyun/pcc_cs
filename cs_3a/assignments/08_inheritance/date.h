#include <string>
using namespace std;
class Date
{
	private:
		unsigned day;
		unsigned month;
		unsigned monthName;
		unsigned year;
		bool isLeap(unsigned) const;
		unsigned daysPerMonth(unsigned m, unsigned y) const;
		string name(unsigned m) const;
		unsigned number(const string &mn) const;

	
	public:
		Date();
		Date(unsigned m, unsigned d, unsigned y);
		Date(const string &mn, unsigned d, unsigned y);
		void printNumeric() const;
		void printAlpha() const;
};
