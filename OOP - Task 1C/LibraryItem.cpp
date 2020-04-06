#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date,const Game* game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

const std::string& LibraryItem::GetGameName()
{
	return game->GetName();
}

Date& LibraryItem::GetDateOfPurchase()
{
	return purchased;
}

