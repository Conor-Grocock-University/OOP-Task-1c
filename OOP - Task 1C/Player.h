#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&);
		~Player();
		List<LibraryItem*> library;
		//Player* getUser
		int GetCredit();
		void AddCredit(int deposit);
	private:
		int credit = 0;
};