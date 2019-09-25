#include "message.h"

/**********************************************************
*
* Constructor Message: class Message
*_________________________________________________________
* This constructor initializes the Message object to the 
* 	default values
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
* Post-conditions
*  none
***********************************************************/
Message::Message()
{
	author = "default";
	subject = "default";
	body = "default";
}

/**********************************************************
*
* Constructor Message: class Message
*_________________________________________________________
* This constructor initializes the Message object to the 
* 	user-defined values
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   	athr  - author name
*   	sbjct - subject
*   	bdy   - body
*
* Post-conditions
*  none
***********************************************************/
Message::Message(const string &athr,	// author
			     const string &sbjct,	// subject
		         const string &bdy)		// body
{
	author = athr;
	subject = sbjct;
	body = bdy;
}

/**********************************************************
*
* Method display: class Message
*_________________________________________________________
* This function will display the contents of the Message
* 	object
*_________________________________________________________
* Pre-conditions
*   the following need previously defined values:
*   	msg_num - message number
*   	name    - username
*
* Post-conditions
*  none
***********************************************************/
void Message::display(int msg_num, 			// message number
		              string name) const	// user name
{
	cout << "-----------------------------------------------\n";
	cout << "Message #" << msg_num + 1 << " : " << subject 
		 << endl;
	cout << "from " << name << ": " << body << endl;
}
