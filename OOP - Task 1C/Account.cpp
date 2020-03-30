#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const std::string& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users[i];
	}
}


// function to return a vector containing an email/password combination for validation
std::vector<std::string> Account::GetLoginCredentials()
{
	std::vector<std::string> login(1); // creating a 2-item vector to store a username/password combination

	login[0] = email;
	login[1] = password;

	return login;
}