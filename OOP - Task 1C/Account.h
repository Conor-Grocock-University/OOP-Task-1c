#pragma once

#include <string>
#include "Player.h"
#include <vector>

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		const std::vector<std::string> GetLoginCredentials() const; // creating a vector which will contain a users username/password for validation
		User* users[3] = { }; // TODO: replace with custom List<T> class

        std::string getEmail() const;
	private:
		std::string email;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};