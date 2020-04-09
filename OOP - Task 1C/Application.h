#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "List.h"
#include "Admin.h"
#include "Guest.h"

class Application
{
public:
    Application();
    ~Application();

    bool IsAccountLoggedIn() const;
    bool IsUserLoggedIn() const;
    bool IsUserAdmin(User* user) const;
	bool IsUserGuest(User*) const;
	bool isUserPlayer(User*) const;
    Account* GetCurrentAccount() const;
    User* GetCurrentUser() const;
	
    Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		void LogoutAccount();
		List<Account*> accounts;

	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
};
