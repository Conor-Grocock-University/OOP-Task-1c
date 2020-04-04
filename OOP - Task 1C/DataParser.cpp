#include "DataParser.h"

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
		}
	}

	void DataParser::parseFile()
	{
		if (error) return;
		int userIndex;
		
		for (int i = 0; i < lines.size(); ++i)
		{
			std::string line = lines[i];
			if (line == "GAME")
				games.push_back(processGame(std::vector<std::string>(lines.begin() + i, lines.begin() + i + 5)));
			if (line == "ACCOUNT") {
				accounts.push_back(processAccount(std::vector<std::string>(lines.begin() + i, lines.begin() + i + 4)));
				userIndex = 0;
			}
			if (line == "ACCOUNT-PLAYER")
				accounts.back->users[userIndex] = processAccountPlayer(std::vector<std::string>(lines.begin() + i, lines.begin() + i + 4));
			if (line == "ACCOUNT-ADMIN")
				accounts.back->users[userIndex] = processAccountAdmin(std::vector<std::string>(lines.begin() + i, lines.begin() + i + 4));


		}
	}

	Game DataParser::processGame(const std::vector<std::string>& dataLines) const
	{
		// 0 - Cat
		// 1 - ID
		// 2 - Name
		// 3 - Description
		// 4 - ???
		// 5 - Price

		int id = std::stoi(dataLines[1]);
		return Game(dataLines[2], dataLines[3], std::stoi(dataLines[4]), std::stoi(dataLines[5]));
	}


	Account processAccount(const std::vector<std::string>& dataLines)
	{
		// 0 - Created date
		// 1 - Email
		// 2 - Password

		Account account = Account(dataLines[1], dataLines[1], dataLines[2]);
		return account;
	}

	Player DataParser::processAccountPlayer(const std::vector<std::basic_string<char>>& cses)
	{
		// 0 - Created date
		// 1 - Name
		// 2 - Password
		// 3 - Credits - ???

		Player player = Player(cses[1], cses[2], cses[0]);
		return player;
	}

	Admin DataParser::processAccountAdmin(const std::vector<std::basic_string<char>>& dataLines)
	{

		// 0 - Created date
		// 1 - Name
		// 2 - Password
		// 3 - Credits - ???

		Admin admin = Admin(dataLines[1], dataLines[2], dataLines[0]);
		return admin;
	}
}
