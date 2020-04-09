#include "LibraryItem.h"
#include "time.h"
#include "stdlib.h"
#include "Utils.h"

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

