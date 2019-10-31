#include "intListIterator.h"

IntListIterator::IntListIterator()
{
	current = NULL;
	cout << "IntListIterator::IntListIterator() called" << endl;
}
IntListIterator::IntListIterator( IntNode *ptr)
{
	current = ptr;
	cout << "IntListIterator::IntListIterator( IntNode *ptr ) called" << endl;
}
int IntListIterator::operator*()
{

}
IntListIterator IntListIterator::operator++()
{

}
IntListIterator IntListIterator::operator--()
{

}
bool IntListIterator::operator==(const IntListIterator& right) const
{

}
bool IntListIterator::operator!=(const IntListIterator& right) const
{

}
