#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"

class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;

		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		
		std::vector<Account* > accounts;
		//Account* accounts[1] = { }; // TODO: this needs changing to a dynamic collection
		//std::vector<std::string> login(1);
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
};