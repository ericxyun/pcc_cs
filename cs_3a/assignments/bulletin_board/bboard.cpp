#include "bboard.h"

/**********************************************************
*
* Constructor BBoard: class BBoard
*_________________________________________________________
* This constructor initializes the User object to the 
* 	default values
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   none
* Post-conditions
*  none
***********************************************************/
BBoard::BBoard()
{
	title = "default";
	user_list = {};
	current_user = User();
	message_list = {};
}

/**********************************************************
*
* Constructor BBoard: class BBoard
*_________________________________________________________
* This constructor initializes the User object to the 
* 	user-defined values
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   	ttl - title
* Post-conditions
*  none
***********************************************************/
BBoard::BBoard(const string &ttl)	// title
{
	title = ttl;
	user_list = {};
	current_user = User();
	message_list = {};
}

/**********************************************************
*
* Method setup: Class BBoard
*_________________________________________________________
* This method will import all users from a input text
*	file and store them as User objects in a the vector 
* 	user_list
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* 		input_file: input filename
*
* POST-CONDITIONS
*     This function will update the user_list User object
***********************************************************/
void BBoard::setup(const string &input_file)	// filename
{
	string n; 		 	// name
	string p;		  	// password
	ifstream infile;	// input file

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

/**********************************************************
*
* Method login: Class BBoard
*_________________________________________________________
* this method will ask for valid username of password
* 	it will continue to ask until valid username and password
*_________________________________________________________
* pre-conditions
* 	none
*
* post-conditions
* 	this function will update the current_user if there is a
* 	matching username and password
***********************************************************/
void BBoard::login()
{
	string uname;	// input - username
	string passwd;	// password - password

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
			cout << "Invalid username or password!\n";
			cout << "Enter your username (\"q\" or \"q\" to quit): \n";
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

/**********************************************************
*
* method run: class bboard
*_________________________________________________________
* this method will present a menu selection for the user to
* 	choose from either display messags, add new messages, or
* 	quit
*_________________________________________________________
* pre-conditions
* 	none
*
* post-conditions
* 	this function relays the user to other functions depending
* 	on their selection
***********************************************************/
void BBoard::run()
{
	do
	{
		char selection;		// input - user selection

		cout << "Menu\n";
		cout << "  - Display Messages ('D' or 'd')\n";
		cout << "  - Add New Message ('N' or 'n')\n";
		cout << "  - Quit ('Q' or 'q')\n";
		cout << "Choose an action: \n";
		cin >> selection;
		if (tolower(selection) == 'd')
		{
			if (message_list.size() == 0)
				cout << "Nothing to display\n" ;
			else
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


/**********************************************************
*
* method user_exists: class bboard
*_________________________________________________________
* this function checks to see if there is a matching 
* 	username and password
*_________________________________________________________
* pre-conditions
*   the following need previously defined values:
*   	name - username
*   	pass - password
*
* post-conditions
* 	returns a boolean if there is a mtaching username and
* 	password
***********************************************************/
bool BBoard::user_exists(const string &name,		// username
				         const string &pass) const	// password
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

/**********************************************************
*
* method get_user: class bboard
*_________________________________________________________
* this function returns a user object of a user in the 
* 	user list
*_________________________________________________________
* pre-conditions
*   the following need previously defined values:
*   	name - username
*   	pass - password
*
* post-conditions
* 	returns a user object
***********************************************************/
User BBoard::get_user(const string &name, 	// username
		              const string &pass)	// password
{
	User u(name, pass);
	return u;
}

/**********************************************************
*
* Method display: class bboard
*_________________________________________________________
* This function displays the contents of the BBoard object
*_________________________________________________________
* Pre-conditions
* 	none
*
* Post-conditions
* 	none
***********************************************************/
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

/**********************************************************
*
* method add_messages: class bboard
*_________________________________________________________
* This function will add new messages to the message_list
* object
*_________________________________________________________
* pre-conditions
* 	none
*
* post-conditions
* 	Updates the contents of the message_list object
***********************************************************/
void BBoard::add_message()
{
	string subj;	// subject
	string bdy;		// body

	cin.ignore();
	cout << "Enter Subject: ";
	getline(cin, subj);
	cout << "Enter Body: ";
	getline(cin, bdy);
	Message m(current_user.get_name(), subj, bdy);
	message_list.push_back(m);
	cout << "Message Recorded!\n";
	cout << endl;
}
