#include "User.h"
#include "Player.h"

User::User(const std::string& username, const std::string& password, const std::string& created)
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



const std::vector<std::string> User::GetUserLogins() const
{
	std::vector<std::string> login; // creating a 2-item vector to store a username/password combination

	login.push_back(username);
	login.push_back(password);

	return login;
}
