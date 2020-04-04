#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const std::string& created)
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

bool Player::BuyGame(Game* game)
{
		if (game->GetCost() <= credit)
		{
			credit -= game->GetCost();
			library.addAtEnd(new LibraryItem("09/11/2001", game));
			return true;
		}
		else
		{
			return false;
		}

}
