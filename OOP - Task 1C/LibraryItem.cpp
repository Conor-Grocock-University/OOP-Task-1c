#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date,const Game* game)
	: game(game), purchased(date)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::GetGame() const
{
	return game;
}

const Date LibraryItem::GetPurchaseDate() const
{
	return purchased;
}
