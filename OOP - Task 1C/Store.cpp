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

