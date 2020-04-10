#pragma once

#include <string>
#include <vector>

#include "Date.h"
#include "LibraryItem.h"
#include "List.h"

struct UserLogins
{
	std::string username;
	std::string password;
};

class User
{
	public:
		User(const std::string&, const std::string&, const Date&);
		virtual ~User();
		const std::string& GetUsername() const;
		const UserLogins GetUserLogins() const;
		const Date GetCreated() const;
		std::vector<LibraryItem*> library;
	private:
		std::string username;
		std::string password;
		Date created; 
};