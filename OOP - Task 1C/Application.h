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
	
    void save();
    void processGame(const std::vector<char*>& lines) const;
    void load() const;

    std::vector<Account* > accounts;

private:
	Store store;
	Account* currentAccount;
	User* currentUser;
};
