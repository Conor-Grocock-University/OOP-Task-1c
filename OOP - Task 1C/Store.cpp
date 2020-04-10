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

List<Game*> Store::SearchByPriceRange(const double& min, const double &max) // unable to pass by reference due to error from returned value from Question function
{
	List<Game*> searchedGames;
	int minP, maxP;
	minP = (int)min * 100;
	maxP = (int)max * 100;
	for (int i = 0; i < games.length(); i++)
	{
		if (Utils::withinPriceRange(minP, maxP, games[i]->GetCost()))
		{
			searchedGames.addInFront(games[i]);
		}
	}

	return searchedGames;
}
