#pragma once

#include <string>

#include "LibraryItem.h"
#include "User.h"
#include "Date.h"
#include "List.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
	
		List<LibraryItem*> library;

		int GetCredit();
		void AddCredit(int deposit);
		bool BuyGame(const Game* game);
		bool OwnsGame(const Game*);
	private:
		int credit = 0;
};