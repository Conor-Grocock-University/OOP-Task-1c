#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date,const Game*);
		~LibraryItem();
		const std::string& GetGameName();
		Date& GetDateOfPurchase();
		int GetPlayTime();
		void addPlayTime();
	private:
		const Game* game;
		Date purchased; 
		int playTimeMinutes;
};