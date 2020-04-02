#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const std::string& created)
    : email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < users.length(); ++i)
	{
		delete users[i];
	}
}


// function to return a struct containing an email/password combination for validation
const AccountLogins Account::GetAccountLogins() const
{
	return { email, password };
}
