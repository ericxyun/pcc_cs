#include <string>
using namespace std;

class User
{
	private:
		string username;
		string password;

	public:
		User();
		User(const string &uname,
			 const string &pass);
		string get_username() const;
		bool check(const string &uname,
				   const string &pass) const;
		void set_password(const string &newpass);
		void display();
		bool operator==(const User& ro) const;
		string get_name() const;

};
