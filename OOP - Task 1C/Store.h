#pragma once
#include "Utils.h"
#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> SearchByName(std::string&);
		List<Game*> SearchByPriceRange(int, int);
		List<Game*> games;
	private:
};
