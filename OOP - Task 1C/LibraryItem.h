#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date,const Game*, int = 0);
		~LibraryItem();

		const Game* GetGame() const;
		const int GetPlaytime() const;
		Date GetPurchaseDate() const;
	private:
		const Game* game;
		Date purchased;
		int playtime;
};