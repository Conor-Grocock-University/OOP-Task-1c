#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "Admin.h"
#include "Application.h"
#include "Game.h"

namespace data
{
	class DataParser
	{
	public:
		DataParser(const Application& app);
		//~DataParser();

		void parseFile();
		List<Game*> getGames();
		List<Account*> getAccounts();

	private:
		Game* processGame(const std::vector<std::string>& dataLines) const;
		Account* processAccount(const std::vector<std::string>& dataLines) const;
		Player* processAccountPlayer(const std::vector<std::basic_string<char>>& dataLines);
		Admin* processAccountAdmin(const std::vector<std::basic_string<char>>& dataLines);
		LibraryItem* processOwnedGame(const std::vector<std::basic_string<char>>& dataLines, List<Game*> games) const;
		
	private:
		bool error;
		std::ifstream file;
		std::vector<std::string> lines;
		List<Game*> games;
		List<Account*> accounts;
	};
}

