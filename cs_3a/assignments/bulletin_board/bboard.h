#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "user.h"
#include "message.h"
#include "cstdlib"
using namespace std;

/****************************************************************
* BBoard Class
*   This class represents a BBoard object. It manages 4 attributes,
*   title, user_list, current_user, and message_list 
****************************************************************/
class BBoard
{
	private:
		string title;					// user title
		vector<User> user_list;			// list of all users
		User current_user;				// current user
		vector<Message> message_list;	// list of messages for one user

	public:
		/****************
		** CONSTRUCTOR **
		****************/

		/****************************************************************
		* BBoard ();
		*   Constructor; Initialize class attributes
		*   Parameters: none
		*   Return: none
		****************************************************************/
		BBoard();

		/****************************************************************
		* BBoard ();
		*   Constructor; Initialize class attributes
		*   Parameters: user title
		*   Return: none
		****************************************************************/
		BBoard(const string &ttl);	// title

		/**************
		** MUTATORS **
		**************/
		/****************************************************************
		* void setup(const string &input_file);
		* 	
		* 	Mutator; This method will import all users from a input text
		* 		file and store them as User objects in a the vector 
		* 		user_list
		*________________________________________________________________
		* 	Parameter: input_file - name of file
		*________________________________________________________________
		*	Return: none
		****************************************************************/
		void setup(const string &input_file);	// file name

		/****************************************************************
		* void login()
		* 	
		* 	Mutator; This method will ask for valid username of password
		* 		It will continue to ask until valid username and password
		*________________________________________________________________
		* 	Parameter: none
		*________________________________________________________________
		*	Return: none
		****************************************************************/
		void login();

		/****************************************************************
		* void run()
		* 	
		* 	Mutator; This method contains the main loop for the program.
		* 		This method presents a menu selection for user to either
		* 		display messages, add new messages, or quit
		*________________________________________________________________
		* 	Parameter: none
		*________________________________________________________________
		*	Return: none
		****************************************************************/
		void run();

		/****************************************************************
		* void add_user()
		* 	
		* 	Mutator; This helper function can be used to add users from
		* 		the input file to the user_list
		*________________________________________________________________
		* 	Parameter:
		* 		infile - filename
		* 		name   - username
		* 		pass   - pass
		*________________________________________________________________
		*	Return: none
		****************************************************************/
		void add_user(istream &infile, 		// file name
				      const string &name, 	// username
					  const string &pass);	// password

		/**************
		** ACCESSORS **
		**************/
		/****************************************************************
		* bool user_exists(const string &name,
		*		           const string &pass) const;
		* 	
		* 	Accessor; This helper function will test to see if there is a
		* 		matching username and password
		*________________________________________________________________
		* 	Parameter:
		* 		name - username
		* 		pass - password
		*________________________________________________________________
		*	Return: boolean
		****************************************************************/
		bool user_exists(const string &name,			// username
				         const string &pass) const;		// password

		/****************************************************************
		* User get_user(const string &name,
		*		        const string &pass);
		* 	
		* 	Accessor; This method will return the User object of a 
		* 		user name in the list
		*________________________________________________________________
		* 	Parameter:
		* 		name - username
		* 		pass - password
		*________________________________________________________________
		*	Return: User object
		****************************************************************/
		User get_user(const string &name,	// username
				      const string &pass);	// password

		/****************************************************************
		* void display() const;
		* 	
		* 	Accessor; This helper function will display the contents of
		* 		the board.
		*________________________________________________________________
		* 	Parameter: none
		*________________________________________________________________
		*	Return: none
		****************************************************************/
		void display() const;

		/****************************************************************
		* void add_message();
		* 	
		* 	Accessor; This help function will add new messages to the 
		* 		message_list
		*________________________________________________________________
		* 	Parameter: none
		*________________________________________________________________
		*	Return: none
		****************************************************************/
		void add_message();
};

