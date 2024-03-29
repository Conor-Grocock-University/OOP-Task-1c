#include "User.h"
#include "Player.h"

User::User(const std::string& username, const std::string& password, const Date& created)
	: username(username), password(password), created(created)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const UserLogins User::GetUserLogins() const
{

	return { username, password };
}

const Date User::GetCreated() const
{
	return created;
}
