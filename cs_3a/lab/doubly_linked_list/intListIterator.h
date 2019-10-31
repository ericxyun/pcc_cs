#include "intNode.h"

using namespace std;

class IntListIterator
{
	private:
		IntNode *current;
	
	public:
		IntListIterator();
		IntListIterator( IntNode *ptr);
		int operator*();
		IntListIterator operator++();
		IntListIterator operator--();
		bool operator==(const IntListIterator& right) const;
		bool operator!=(const IntListIterator& right) const;

};
