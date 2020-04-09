#pragma once

#include <string>
#include <vector>
#include "Date.h"
#include "LibraryItem.h"
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
	std::vector<LibraryItem*> library;
private:
	std::string username;
	std::string password;
	Date created;
};