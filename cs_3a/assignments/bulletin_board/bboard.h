#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "user.h"
#include "user.cpp"
#include "message.h"
#include "message.cpp"
using namespace std;

/****************************************************************
* BBoard Class
*   This class represents a BBoard object. It manages 4 attributes,
*   title, user_list, current_user, and message_list 
***************************************************************/
class BBoard
{
	private:
		string title;					// user title
		vector<User> user_list;			 
		User current_user;
		vector<Message> message_list;
	public:
		/******************************
		** CONSTRUCTOR & DESTRUCTOR **
		******************************/
		/****************************************************************
		* BBoard ();
		*   Constructor; Initialize class attributes
		*   Parameters: none
		*   Return: none
		***************************************************************/
		BBoard();
		BBoard(const string &ttl);
		void setup(const string &input_file);
		void login();
		void run();
		void add_user(istream &infile, 
				      const string &name, 
					  const string &pass);
		bool user_exists(const string &name,
				         const string &pass) const;
		User get_user(const string &name,
				      const string &pass);
		void display() const;
		void add_message();
};

