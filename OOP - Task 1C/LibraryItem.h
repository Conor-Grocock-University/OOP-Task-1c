#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date,const Game*);
		~LibraryItem();
		const std::string& GetGameName();
		const Game* GetGame();
		Date& GetDateOfPurchase();
	private:
		const Game* game;
		Date purchased; 
};