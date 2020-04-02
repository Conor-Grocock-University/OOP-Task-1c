#include "Utils.h"

std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

bool Utils::startsWith(std::string& searchText, std::string& gameName)
{
	if (gameName.find(searchText) == 0) // if the search text is found at the beginning of game name (if the game name starts with search text)
	{
		return true;
	}
	else
	{
		return false;
	}
}

