Message::Message()
{
	author = "default";
	subject = "default";
	body = "default";
}

Message::Message(const string &athr,	// author
			     const string &sbjct,	// subject
		         const string &bdy)		// body
{
	author = athr;
	subject = sbjct;
	body = bdy;
}

void Message::display(int msg_num, 
		              string name) const
{
	cout << "-----------------------------------------------\n";
	cout << "Message #" << msg_num + 1 << " : " << subject << endl;
	cout << "from " << name << " : " << body << endl;
}
