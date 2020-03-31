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