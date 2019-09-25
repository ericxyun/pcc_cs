#include <string>
#include <iostream>
using namespace std;

/****************************************************************
* User Class
* 	This class represents the User object. It manages two 
* 	attributes: username and password
****************************************************************/
class User
{
	private:
		string username;
		string password;

	public:
		/****************
		 ** CONSTRUCTOR **
		 ****************/

		/****************************************************************
		 * User ();
		 *   Constructor; Initialize class attributes
		 *   Parameters: none
		 *   Return: none
		 ****************************************************************/
		User();

		/****************************************************************
		 * User ();
		 *   Constructor; Initialize class attributes
		 *   Parameters: 
		 *   	uname - username
		 *   	pass  - password
		 *   Return: none
		 ****************************************************************/
		User(const string &uname,
			 const string &pass);

		/**************
		 ** MUTATORS **
		 **************/

		/**************
		 ** ACCESSOR **
		 **************/
		/****************************************************************
		 * void display();
		 * 	
		 * 	Mutator; This method will display the contents of the User
		 * 		object
		 *________________________________________________________________
		 * 	Parameter: none
		 *________________________________________________________________
		 *	Return: none
		 ****************************************************************/
		void display();

		/****************************************************************
		 * bool operator==(const User& ro) const;
		 * 	
		 * 	Operator Overload; This function will allow a comparison between
		 * 		two User objects
		 *________________________________________________________________
		 * 	Parameter: User object
		 *________________________________________________________________
		 *	Return: boolean
		 ****************************************************************/
		bool operator==(const User& ro) const;

		/****************************************************************
		 * string get_name() const;
		 * 	
		 * 	Mutator; This method will allow access to the username
		 * 		of the User function
		 *________________________________________________________________
		 * 	Parameter: none
		 *________________________________________________________________
		 *	Return: username
		 ****************************************************************/
		string get_name() const;

		void set_password(const string &newpass);
		string get_username() const;
		bool check(const string &uname,
				   const string &pass) const;

};
