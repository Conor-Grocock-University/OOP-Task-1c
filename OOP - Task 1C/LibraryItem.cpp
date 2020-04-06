#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date,const Game* game, int playTime)
	: game(game), purchased(date), playtime(playTime)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::GetGame() const
{
	return game;
}

const int LibraryItem::GetPlaytime() const
{
	return playtime;
}

Date LibraryItem::GetPurchaseDate() const
{
	return purchased;
}
