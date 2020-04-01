#include "Application.h"


Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < accounts.length(); ++i)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
    return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
    return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
    return currentAccount;
}

User* Application::GetCurrentUser() const
{
    return currentUser;
}

Store& Application::GetStore()
{
    return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	for (int i = 0; i <= accounts.length() - 1; i++) // looping through vector to verify login credentials
	{
		Account* temp = accounts[i]; // temp account for looping
		std::vector<std::string> logins = temp->GetLoginCredentials();

		if (email == logins[0] && password == logins[1])
		{
			currentAccount = accounts[i]; // set current account only if credentials are correct
			return true; // return true if login credentials match
		}
	}
	return false;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{

	for (int i = 0; i <= currentAccount->users.length() - 1; i++)
	{
		User* temp = currentAccount->users[i]; // getting next user
		std::vector<std::string> logins = temp->GetUserLogins(); // getting user logins

		if (username == logins[0] && password == logins[1])
		{
			currentUser = currentAccount->users[i];
			return true;
		}
	}
    return false;
}

void Application::LogoutUser()
{
    currentUser = nullptr;
}
