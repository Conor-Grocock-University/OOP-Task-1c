#include "LibraryItem.h"
#include "Utils.h"

LibraryItem::LibraryItem(const Date date,const Game* game, int playTime)
	: game(game), purchased(date), playtime(playTime)
{
}

void LibraryItem::addPlayTime()
{
	playtime += Utils::randomWithinRange(10, 60);
}

const Game* LibraryItem::GetGame() const
{

	return game;
}

Date LibraryItem::GetPurchaseDate() const
{
	return purchased;
}

const int LibraryItem::GetPlaytime() const
{
	return playtime;
}

