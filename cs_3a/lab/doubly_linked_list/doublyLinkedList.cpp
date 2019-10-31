#include "doublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	head = new IntNode;
	head->next = head->prev = head;
	// tail = NULL;

	cout << "DoublyLinkedList() called" << endl;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &D)
{
	// dummy header
	head = new IntNode;
	head->next = head->prev = head;

	// copy nodes
	for (IntNode *cur = D.head->next; cur != D.head; cur = cur->next)
	{
		IntNode *tmp = new IntNode;
		tmp->data = cur->data;

		// insert at end of list
		tmp->next = head;
		tmp->prev = head->prev;
		tmp->prev->next = tmp;	
		tmp->next->prev = tmp;
	}
	cout << "DoublyLinkedList(const DoublyLinkedList &D) called" << endl;
}

DoublyLinkedList::~DoublyLinkedList()
{
	IntNode *cur = new IntNode;
	cur = head->next;
    while (cur != head)
    {
    	IntNode *next = new IntNode;
		next = cur->next;
    	delete cur;
    	cur = next;
    }
    delete head;
	cout << "~DoublyLinkedList called" << endl;
}

DoublyLinkedList & DoublyLinkedList::operator=(const DoublyLinkedList &D)
{
	if (this == &D)
		return *this;

	// delete head
	IntNode *cur = head->next;
	while (cur != head)
	{
		IntNode *next = cur ->next;
		delete cur;
		cur = next;
	}
	delete head;

	// copy D
	// dummy header
	head = new IntNode;
	head->next = head->prev = head;

	// copy nodes
	for (IntNode *cur = D.head->next; cur != D.head; cur = cur->next)
	{
		IntNode *tmp = new IntNode;
		tmp->data = cur->data;

		// insert at end of list
		tmp->next = head;
		tmp->prev = head->prev;
		tmp->prev->next = tmp;	
		tmp->next->prev = tmp;
	}
	cout << "DoublyLinkedList & DoublyLinkedList::operator=(const DoublyLinkedList &D) called" << endl;
	return *this;
}
void DoublyLinkedList::display(bool forward = true) const
{
	IntNode *cur = new IntNode;
	cur = head;
	while (cur != NULL)
	{
		cout << " " << cur->data;
		if (cur->next == NULL)
		{
			break;
		}
		cur = cur->next;
	}
}

void DoublyLinkedList::push_front( int value )
{
	IntNode *newNode = new IntNode;

	newNode->data = value;
	newNode->next = head;
	newNode->prev = NULL;

	if (head != NULL)
	 	head->prev = newNode;
	head = newNode;
	// head = newNode;
	cout << "void DoublyLinkedList::push_front( int value ) called" << endl;
}
// void DoublyLinkedList::pop_front()
// {}
// void DoublyLinkedList::push_back(int value)
// {}
// void DoublyLinkedList::pop_back()
// {}
// void DoublyLinkedList::sort()
// {}
// void DoublyLinkedList::insert_sorted(int value)
// {}
// bool DoublyLinkedList::remove(int value)
// {}
// IntListIterator DoublyLinkedList::begin()
// {}
// IntListIterator DoublyLinkedList::end()
// {}
// int DoublyLinkedList::front() const
// {}
// int DoublyLinkedList::back() const
// {}
// int DoublyLinkedList::length() const
// {}
