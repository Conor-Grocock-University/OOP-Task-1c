#include "LibraryItem.h"
#include "time.h"
#include "stdlib.h"
#include "Utils.h"

LibraryItem::LibraryItem(const Date date,const Game* game)
	: purchased(date), game(game), playTimeMinutes(0)
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

int LibraryItem::GetPlayTimeMinutes()
{
	return playTimeMinutes;
}

void LibraryItem::addPlayTime()
{
	int rand = Utils::randomWithinRange(10, 60);
	playTimeMinutes +=rand;
}

const Game* LibraryItem::GetGame()
{
	return game;
}

