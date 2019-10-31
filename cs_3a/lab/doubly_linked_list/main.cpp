#include <iostream>
#include "doublyLinkedList.cpp"
// #include "intListIterator.h"
using namespace std;

int main()
{
	DoublyLinkedList L1;
	L1.push_back(3);
	L1.push_back(4);
	L1.display();

	DoublyLinkedList L2(L1);
	L2.display();
	// L1.pop_back();
	// L1.display();
	// L1.begin();
	//DoublyLinkedList L2(L1);
	// L2.display();

}
