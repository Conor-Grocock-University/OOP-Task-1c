#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < games.length(); ++i)
	{
		delete games[i];
	}
}

List<Game*> Store::SearchByName(std::string &searchText)
{
	List<Game*> searchedGames;
	for (int i = 0; i < games.length(); i++)
	{
		if (Utils::startsWith(searchText, games[i]->GetName()))
		{
			searchedGames.addInFront(games[i]);
		}
	}

	return searchedGames;
}

List<Game*> Store::SearchByPriceRange(int min, int max) // unable to pass by reference due to error from returned value from Question function
{
	List<Game*> searchedGames;
	for (int i = 0; i < games.length(); i++)
	{
		if (Utils::withinPriceRange(min, max, games[i]->GetCreditValue()))
		{
			searchedGames.addInFront(games[i]);
		}
	}

	return searchedGames;
}