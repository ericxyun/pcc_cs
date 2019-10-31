#include "intListIterator.h"

using namespace std;

class DoublyLinkedList
{
	private:
		IntNode *head;
		IntNode *tail;

	public:
		DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList &D);
		~DoublyLinkedList();
		DoublyLinkedList & operator=(const DoublyLinkedList &D);
		void display(bool) const;
		void push_front( int value );
		// void pop_front();
		// void push_back(int value);
		// void pop_back();
		// void sort();
		// void insert_sorted(int value);
		// bool remove(int value);
		// IntListIterator begin();
		// IntListIterator end();
		// int front() const;
		// int back() const;
		// int length() const;
 
};
