#include "doublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = head;
	// head = new IntNode(0);
	// tail = new IntNode(0);
	// head->prev = NULL;
	// head->next = tail;
	// tail->prev = head;
	// tail->next = NULL;

	cout << "DoublyLinkedList() called" << endl;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &D)
{
	IntNode *tmp;
	tmp = D.head;
	if (head == NULL)
	{
		head = tmp;
		tail = head;
		tail->next = NULL;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
		tail->prev = tmp->prev;
		tail->next = NULL;
		tmp = tmp->next;
	}
	// IntNode *tmp = new IntNode(0);
	// IntNode *tmpD = new IntNode(0);
	// if (D.head == NULL)
	// {
	// 	head = NULL;
	// 	tail = NULL;
	// }
	// else
	// {
	// 	head = new IntNode(0);
	// 	head->data = D.head->data;
	// 	tmp = head;
	// 	tmpD = D.head->next;
	// }
	// while (tmpD)
	// {
	// 	tmp->next = new IntNode(0);
	// 	tmp = tmp->next;
	// 	tmp->data = D.head->data;
	// 	tmpD = tmpD->next;
	// }

	// tmp->next = NULL;
	// IntNode *tail = tmp;
    // delete tmp;
	// delete tmpD;

	cout << "DoublyLinkedList(const DoublyLinkedList &D) called" << endl;
}

DoublyLinkedList::~DoublyLinkedList()
{
	// cur = head->next;
	IntNode *current = head;

    while (current)
    {
    	IntNode *next = current->next;
		delete current;
		current = next;
    }
		
    // delete head; // This deletes same object twice?
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
	head->next = head->prev = head;

	// copy nodes
	for (IntNode *cur = D.head->next; cur != D.head; cur = cur->next)
	{
		IntNode *tmp;
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
	IntNode *current = head;
	while (current != NULL)
	{
		cout << " " << current->data;
		if (current->next == NULL)
		{
			break;
		}
		current = current->next;
	}
	cout << endl;
}

void DoublyLinkedList::push_front( int value )
{
	IntNode *newNode = new IntNode(0);

	newNode->data = value;
	newNode->next = head;
	newNode->prev = NULL;

	if (head != NULL)
	 	head->prev = newNode;
	head = newNode;
	cout << "void DoublyLinkedList::push_front( int value ) called" << endl;
}

void DoublyLinkedList::push_back(int value)
{
	IntNode *newNode;
	newNode = new IntNode(value);

	if (head == NULL)
		head = newNode;
	if (tail != NULL)
		tail->next = newNode;
	newNode->next = NULL;
	newNode->prev = tail;
	tail = newNode;
	cout << "void DoublyLinkedList::push_back(int value) called" << endl;
}

void DoublyLinkedList::pop_front()
{
    IntNode *tmp = head;
	head = head->next;
	delete tmp;
	cout << "void DoublyLinkedList::pop_front() called" << endl;
}

void DoublyLinkedList::pop_back()
{
	IntNode *tmp = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete tmp;
}
// void DoublyLinkedList::sort()
// {}
// void DoublyLinkedList::insert_sorted(int value)
// {}
// bool DoublyLinkedList::remove(int value)
// {}
IntListIterator DoublyLinkedList::begin()
{
    // IntListIterator *begin = new IntListIterator(head);
	cout << "IntListIterator DoublyLinkedList::begin() called" << endl;
}
IntListIterator DoublyLinkedList::end()
{

}
// int DoublyLinkedList::front() const
// {}
// int DoublyLinkedList::back() const
// {}
// int DoublyLinkedList::length() const
// {}
