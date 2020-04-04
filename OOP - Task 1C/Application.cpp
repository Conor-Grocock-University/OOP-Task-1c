#include "Application.h"
#include "Admin.h"


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

bool Application::IsUserAdmin(User* user) const
{
	try
	{
		if(dynamic_cast<Admin*>(user)== NULL)
		{ 
			return false;
		}
	}
	catch (const std::bad_cast)
	{
		return false;
	}
	return true;
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
		AccountLogins logins = accounts[i]->GetAccountLogins();

		if (email == logins.email && password == logins.password)
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
		UserLogins logins = currentAccount->users[i]->GetUserLogins(); // getting user logins

		if (username == logins.username && password == logins.password)
		{
			currentUser = currentAccount->users[i];
			return true;
		}
	}
    return false;
}

bool Application::DeleteUser(User* user)
{
	try
	{
		currentAccount->users.deleteOne(user);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

void Application::CreateNewUser(const std::string& username, const std::string& password)
{
}

void Application::LogoutUser()
{
    currentUser = nullptr;
}

void Application::LogoutAccount()
{
	currentAccount = nullptr;
}
