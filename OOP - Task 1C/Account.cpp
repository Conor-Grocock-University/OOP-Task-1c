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

const Date& Account::getCreated() const
{
	return created;
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

User* Account::GetUser(const std::string& username)
{
	User* user = nullptr;
	for (int i = 0; i <= users.length() - 1; i++)
	{
		if (users[i]->GetUserLogins().username == username)
		{
			user = users[i];
		}
	}
	return user;
}

Guest* Account::GetGuest()
{
	Guest* guest;
	for(int i =0; i <= users.length() - 1; i++)
	{
		if (users[i]->GetUsername() == "Guest")
		{
			guest = (Guest*)users[i];
			return guest;
		}
	}
}

Player* Account::GetAdmin()
{
	for (int i = 0; i <= users.length() - 1; i++)
	{
		if (Utils::isUserAdmin(users[i]))
			return dynamic_cast<Player*>(users[i]);
		
	}
	return nullptr;
}

void Account::DeletePlayer(User* user)
{
	users.deleteOne(user);
}
