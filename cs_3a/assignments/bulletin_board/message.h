#include <string>
#include <iostream>
using namespace std;

/****************************************************************
* Message Class
*   This class represents a Message object. It manages 3 attributes,
*   author, subject, and body
****************************************************************/
class Message
{
	private:
		string author;
		string subject;
		string body;

	public:
		/****************
		** CONSTRUCTOR **
		****************/

		/****************************************************************
		* Message();
		*   Constructor; Initialize class attributes
		*   Parameters: none
		*   Return: none
		****************************************************************/
		Message();

		/****************************************************************
		* Message();
		*   Constructor; Initialize class attributes
		*   Parameters: 
		*   	athr  - author
		*   	sbjct - subject
		*   	bdy   - body
		*   Return: none
		****************************************************************/
		Message(const string &athr,		// author
				const string &sbjct,	// subject
				const string &bdy);		// body

		/*************
		** ACCESSOR **
		*************/
		/****************************************************************
		* void display(int msg_num, 
		*	           string name) const;
		* 	
		* 	ACCESSOR; This method will display all the messages in the
		* 		message_list Message object
		*________________________________________________________________
	    * Parameter: 
		* 	msg_num - message number in the vector
		* 	name    - username
		*		
		*________________________________________________________________
		*	Return: none
		****************************************************************/
		void display(int msg_num, 			// message number in the vector
				     string name) const;	// username
};
