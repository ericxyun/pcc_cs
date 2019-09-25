#include "user.h"

/**********************************************************
*
* Constructor User: class User
*_________________________________________________________
* This constructor initializes the User object to the 
* 	default values
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
* Post-conditions
*  none
***********************************************************/
User::User()
{
	username = "default";
	password = "default";
}

/**********************************************************
*
* Constructor User: class User
*_________________________________________________________
* This constructor initializes the User object to the 
* 	user-defined values
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   	uname - username
*   	pass  - password
* Post-conditions
*  none
***********************************************************/
User::User(const string &uname,
		   const string &pass)
{
	username = uname ;
	password = pass;
}

/**********************************************************
*
* Method display: class User
*_________________________________________________________
* This function will display the contents of the user object
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   	none
*
* Post-conditions
*  none
***********************************************************/
void User::display()
{
	cout << "Welcome back " << username << "!" << endl;
	cout << endl;
}

/**********************************************************
*
* method operator: class User
*_________________________________________________________
* This function will allow a comparison between two 
* 	User objects
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   	ro: right object should be User object
*
* Post-conditions
* 	Returns a boolean
***********************************************************/
bool User::operator==(const User& ro) const
{
	if ((ro.username == username) &&
		(ro.password == password))
		return true;
	return false;
}

/**********************************************************
*
* Method get_name: class User
*_________________________________________________________
* This function will allow access to the username in the
* 	User object
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   	none
*
* Post-conditions
* 	returns a string form of the user name
***********************************************************/
string User::get_name() const
{
	return username;
} 
