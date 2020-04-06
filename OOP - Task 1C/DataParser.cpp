#include "DataParser.h"
#include "Utils.h"

namespace data
{
	DataParser::DataParser(const Application& app)
	{
		file.open("data.txt");
		error = !file.is_open();

		if (file.is_open()) {
			std::string line;
			while (getline(file, line)) {
				lines.emplace_back(line.c_str());
			}
			file.close();
		}
	}

	void DataParser::parseFile()
	{
		if (error) return;
		
		for (int i = 0; i < lines.size(); ++i)
		{
			std::string line = lines[i];
			
			if (line == "GAME")
				games.addAtEnd(processGame(Utils::splitVector(lines, i, 6)));
			else if (line == "ACCOUNT")
				accounts.addAtEnd(processAccount(Utils::splitVector(lines, i, 4)));
			else if (line == "ACCOUNT-PLAYER")
				accounts.last()->users.addAtEnd(processAccountPlayer(Utils::splitVector(lines, i, 4)));
			else if (line == "ACCOUNT-ADMIN")
				accounts.last()->users.addAtEnd(processAccountAdmin(Utils::splitVector(lines, i, 4)));
			else if (line == "LIBRARY-ITEM")
				accounts.last()->users.last()->library.addAtEnd(processOwnedGame(Utils::splitVector(lines, i, 3), games));
		}
	}

	List<Game*> DataParser::getGames()
	{
		return games;
	}

	List<Account*> DataParser::getAccounts()
	{
		return accounts;
	}

	Game* DataParser::processGame(const std::vector<std::string>& dataLines) const
	{
		// 0 - Cat
		// 1 - ID
		// 2 - Name
		// 3 - Description
		// 4 - Price
		// 5 - Rating

		const int id = std::stoi(dataLines[1]);
		return new Game(id, dataLines[2], dataLines[3], std::stoi(dataLines[4]), std::stoi(dataLines[5]));
	}

	Account* DataParser::processAccount(const std::vector<std::string>& dataLines) const
	{
		// 0 - Cat
		// 1 - Created date
		// 2 - Email
		// 3 - Password
		
		return new Account(dataLines[2], dataLines[3], Date(dataLines[1].c_str()));
	}

	Player* DataParser::processAccountPlayer(const std::vector<std::basic_string<char>>& cses)
	{
		// 0 - Cat
		// 1 - Created date
		// 2 - Name
		// 3 - Password
		// 4 - Credits - ???

		return new Player(cses[2], cses[3], Date(cses[1].c_str()));
	}

	Admin* DataParser::processAccountAdmin(const std::vector<std::basic_string<char>>& dataLines)
	{
		// 0 - Cat
		// 1 - Created date
		// 2 - Name
		// 3 - Password
		// 4 - Credits - ???

		return new Admin(dataLines[2], dataLines[3], Date(dataLines[1].c_str()));
	}

	LibraryItem* DataParser::processOwnedGame(const std::vector<std::basic_string<char>>& dataLines, List<Game*> games) const
	{
		// 0 - Cat
		// 1 - Game id
		// 2 - Purchase date
		
		Game* selected = nullptr;
		for (int i = 0; i < games.length(); ++i)
		{
			if (games[i]->GetId() == std::stoi(dataLines[1]))
				selected = games[i];
		}
		
		return new LibraryItem(Date(dataLines[2].c_str()), selected);
	}
}