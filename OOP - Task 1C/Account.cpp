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
const std::vector<std::string> Account::GetLoginCredentials() const
{
	std::vector<std::string> login; // creating a 2-item vector to store a username/password combination

	login.push_back(email);
	login.push_back(password);

	return login;
}