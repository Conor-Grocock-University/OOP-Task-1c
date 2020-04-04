#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
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

List<User*> Account::GetUsers()
{
	return users;
}

void Account::AddPlayer(const std::string& username, const std::string& password)
{
	users.addInFront(new Player(username, password, Date::CurrentDate()));
}
void Account::AddAdmin(const std::string& username, const std::string& password)
{
	users.addInFront(new Admin(username, password, Date::CurrentDate()));
}
