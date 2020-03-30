#include "Application.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
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
	// TODO: This currently always logs you in as the first account (FIXED)

	for (int i = 0; i <= accounts.size(); i++) // looping through vector to verify login credentials
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
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->users[0];

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}