#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&,const Game*);
		~LibraryItem();

		const Game* GetGame() const;
		const Date& GetPurchaseDate() const;
	private:
		const Game* game;
		const Date& purchased; 
};