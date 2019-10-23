#include <iostream>
#include "IntList.h"
#include "IntList.cpp"

using namespace std;

//This test file will test test the following functions for the IntList
//Intro assignment:
//IntList() - default constructor
//~IntList() - destructor
//void display() const 
//void push_front(int value)
//void pop_front()

int main()
{
	IntList list;
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);

	list.display();
}
