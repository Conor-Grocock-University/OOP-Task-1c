#pragma once

#include <string>
#include <vector>

#include "Player.h"
#include "Date.h"
#include "List.h"

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
		List<User*> users;

		const Date& getCreated() const;
	private:
		
		std::string email;
		std::string password;
		Date created;  
};