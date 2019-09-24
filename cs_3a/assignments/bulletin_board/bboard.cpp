BBoard::BBoard()
{
	title = "default";
	user_list = {};
	current_user = User();
	message_list = {};
}

BBoard::BBoard(const string &ttl)	// title
{
	title = ttl;
	user_list = {};
	current_user = User();
	message_list = {};
}


void BBoard::setup(const string &input_file)
{
	string n;
	string p;
	string end;
	ifstream infile;
	infile.open(input_file);
	int i = 0;
	while (!infile.eof())
	{
		infile >> n;
		infile >> p;
		User user(n,p);
		if (n != "end")
		{
			this->user_list.push_back(user);
		}
	}
}

void BBoard::login()
{
	string uname;
	string passwd;
	cout << "Enter your username (\"Q\" or \"q\" to quit): \n";
	cin >> uname;
	if ((uname != "Q") && (uname != "q"))
	{
		cout << "Enter your password: \n";
		cin >> passwd;
		if (!user_exists(uname, passwd))
		{
			do
			{
			cout << "Invalid Username or Password!\n";
			cout << "Enter your username (\"Q\" or \"q\" to quit): \n";
			cin >> uname;
			cout << "Enter your password: \n";
			cin >> passwd;
			}
			while (!user_exists(uname,passwd));
		}
		current_user = get_user(uname, passwd);
		current_user.display();
		run();
	}
	else
	{
		cout << "Bye!\n";
		exit(0);
	}
}

void BBoard::run()
{
	do
	{
		char selection;
		cout << "Menu\n";
		cout << " - Display Messages ('D' or 'd')\n";
		cout << " - Add New Message ('N' or 'n')\n";
		cout << " - Quit ('Q' or 'q')\n";
		cout << "Choose an action:\n";
		cin >> selection;
		if (tolower(selection) == 'd')
		{
			// message.display
			display();
		}
		else if (tolower(selection) == 'n')
		{
			add_message();
		}
		else if (tolower(selection) == 'q')
		{
			cout << "Bye!\n";
			exit(0);
		}
	}
	while (true);

}
void BBoard::add_user(istream &infile, 
			  const string &name, 
			  const string &pass)
{}


bool BBoard::user_exists(const string &name,
				         const string &pass) const
{
	User usr(name, pass);
	for (int i = 0; i < user_list.size(); i++)
	{
		if (user_list[i] == usr)
		{
			return true;
		}
	}
	return false;
}

User BBoard::get_user(const string &name, 
		              const string &pass)
{
	User u(name, pass);
	return u;
}
void BBoard::display() const
{
	string author;
	for (int i = 0; i < message_list.size(); i++)
	{
		author = current_user.get_name();
		message_list[i].display(i, author);
	}
	cout << "-----------------------------------------------\n";
	cout << endl;

}
void BBoard::add_message()
{
	string subj;
	string bdy;
	cin.ignore();
	cout << "Enter Subject: ";
	getline(cin, subj);
	cout << "Enter Body: ";
	getline(cin, bdy);
	Message m(current_user.get_name(), subj, bdy);
	// TODO: remove
	message_list.push_back(m);
	cout << "Message Recorded!\n";
}
