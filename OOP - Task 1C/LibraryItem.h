#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&,const Game*);
		~LibraryItem();
		std::string GetGameName();
	private:
		const Game* game;
		const Date purchased; 
};