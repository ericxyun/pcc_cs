#include "intList.h"
IntList::IntList() 
{
	head = new IntNode;
	tail = new IntNode;
	head = NULL;
	tail = NULL;
}
IntList::IntList( const IntList &list) 
{
	IntNode node = list.head;
	while (node != nullptr)
	{
		node
		node = tail
	}
}
// IntList::~IntList() 
// {
// }
// void IntList::display() const 
// {
// }
// void IntList::push_front( int value ) 
// {
// }
// void IntList::push_back( int value ) 
// {
// }
// void IntList::pop_front() 
// {
// }
// void IntList::select_sort() 
// {
// }
// void IntList::insert_sorted( int value ) 
// {
// }
// void IntList::remove_duplicates() 
// {
// }
// IntListIterator begin() 
// {
// }
// IntListIterator end() 
// {
// }
// int IntList::front() const 
// {
// }
// int IntList::back() const 
// {
// }
// int IntList::length() const; 
// {
// }
// int IntList::sum() const; 
// {
// }
// void IntList::reverseDisplay() const; 
// {
// }
// IntList & IntList::operator=( const IntList &list ) 
// {
// }
