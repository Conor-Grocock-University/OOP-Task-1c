#pragma once

#include <string>
#include <vector>

#include "Player.h"
#include "Admin.h"
#include "Date.h"
#include "List.h"
#include "Guest.h"
#include "Utils.h"
struct AccountLogins
{
	std::string email;
	std::string password;
};

class Account
{
	
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		const AccountLogins GetAccountLogins() const; // creating a vector which will contain a users username/password for validation
		List<User*> GetUsers();
		void AddPlayer(const std::string&, const std::string&);
		void AddAdmin(const std::string&, const std::string&);
		User* GetUser(const std::string&);
		Guest* GetGuest();
		Player* GetAdmin();
		void DeletePlayer(User*);
		
		List<User*> users;

		const Date& getCreated() const;
	private:
		
		std::string email;
		std::string password;
		Date created;
};