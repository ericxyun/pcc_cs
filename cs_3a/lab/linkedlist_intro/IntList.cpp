IntList::IntList()
{
	head = NULL;
	tail = NULL;
}

IntList::~IntList()
{
	delete head;
	delete tail;
}

void IntList::display() const
{
	IntNode *current = head;

	if ( current->next ==  NULL )
	{
		cout << current->data;
	}

	else 
	{
		while (current->next != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
}

void IntList::push_front( int value )
{
	IntNode *newNode = new IntNode(value);
	newNode->next = head; 
	head = newNode; 
}

void IntList::pop_front()
{
	IntNode *tmp = head;
	if (head->data != NULL)
	{
		head = head->next;
		delete tmp;
	}
}

