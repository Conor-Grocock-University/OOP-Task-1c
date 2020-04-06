#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created)
	: User(username, password, created)
{
}

Player::~Player()
{
	for (int i = 0; i < library.length(); ++i)
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
		if (game->GetCost() <= credit)
		{
			credit -= game->GetCost();
			library.addAtEnd(new LibraryItem(Date::CurrentDate(), game));
			return true;
		}
		else
		{
			return false;
		}
}

bool Player::OwnsGame(const Game* game)
{
	for (int item_index = 0; item_index < library.length(); ++item_index)
	{
		if (library[item_index]->GetGame() == game) { return true; }		
	}
	return false;
}