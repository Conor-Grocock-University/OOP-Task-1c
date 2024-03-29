#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created)
	: User(username, password, created)
{
}

Player::~Player()
{
	for (int i = 0; i < library.size(); ++i)
	{
		delete library[i];
	}
}

int Player::GetCredit()
{
	return credit;
}

void Player::AddCredit(int deposit)
{
	credit += deposit;
}

bool Player::BuyGame(const Game* game)
{
	if (game->GetCost()/100 > credit) return false;
	
	credit -= game->GetCost()/100;
	library.push_back(new LibraryItem(Date::CurrentDate(), game));
	return true;
}

void Player::AddGuestGame(LibraryItem* game)
{
    guestLibrary.push_back(game);
}

bool Player::OwnsGame(const Game* game)
{
	for (int item_index = 0; item_index < library.size(); ++item_index)
	{
		if (library[item_index]->GetGame() == game) { return true; }		
	}
	return false;
}

