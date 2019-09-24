#include <string>
#include <iostream>
using namespace std;

class Message
{
	private:
		string author;
		string subject;
		string body;

	public:
		Message();
		Message(const string &athr,
				const string &sbjct,
				const string &bdy);
		void display(int msg_num, 
				     string name) const;
};
