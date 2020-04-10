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
		int GetCredit();
		void AddCredit(int deposit);
		bool BuyGame(const Game* game);
		bool OwnsGame(const Game*);
		void AddGuestGame(LibraryItem*);
		std::vector<LibraryItem*> library;	// libraries need to be public to use the std::sort function
		std::vector<LibraryItem*> guestLibrary;

	private:
	
		int credit = 0;
};