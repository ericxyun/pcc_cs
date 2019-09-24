User::User()
{
	username = "default";
	password = "default";
}

User::User(const string &uname,
		   const string &pass)
{
	username = uname;
	password = pass;
}

void User::display()
{
	cout << "Welcome back " << username << endl;
}


bool User::operator==(const User& ro) const
{
	if ((ro.username == username) &&
		(ro.password == password))
		return true;
	return false;
}

string User::get_name() const
{
	return username;
} 
