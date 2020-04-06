#include "DataWriter.h"

namespace data
{
	DataWriter::DataWriter(Application& app)
	{
		this->app = &app;
		file.open("data.txt", std::ios::out);
		writeFile();
		file.close();
	}

	void DataWriter::writeToLineToFile(const std::vector<std::string>& lines)
	{
		for (const std::string& line : lines)
		{
			const char* output = line.c_str();
			file << output << std::endl;
		}
	}

	void DataWriter::writeFile()
	{
		const List<Game*> games = app->GetStore().games;
		for (int i = 0; i < games.length(); i++)
			writeGame(app->GetStore().games[i]);
		
		List<Account*> accounts = app->accounts;
		for (int account_index = 0; account_index < accounts.length(); account_index++)
		{
			Account* account = accounts[account_index];
			writeAccount(account);

			List<User*> users = account->users;
			for (int user_index = 0; user_index < users.length(); user_index++)
			{
				User* user = users[user_index];
				
				if(Application::IsUserAdmin(user))
					writeAccountAdmin(dynamic_cast<Admin*>(user));
				else
					writeAccountPlayer(dynamic_cast<Player*>(user));

				std::vector<LibraryItem*> library = user->library;
				for (int lib_index = 0; lib_index < library.size(); lib_index++)
					writeOwnedGame(library[lib_index]);
			}
		}
	}
	
	void DataWriter::writeGame(Game* game)
	{
		std::vector<std::string> fileLines;

		fileLines.push_back("GAME");
		fileLines.push_back(std::to_string(game->GetId()));
		fileLines.push_back(game->GetName());
		fileLines.push_back(game->GetDescription());
		fileLines.push_back(std::to_string(game->GetCost()));
		fileLines.push_back(std::to_string(game->GetAgeRating()));
		
		writeToLineToFile(fileLines);
	}

	void DataWriter::writeAccount(Account* account)
	{
		std::vector<std::string> fileLines;
		const AccountLogins logins = account->GetAccountLogins();

		fileLines.push_back("ACCOUNT");
		fileLines.push_back(account->getCreated().ToFormattedString('/'));
		fileLines.push_back(logins.email);
		fileLines.push_back(logins.password);

		writeToLineToFile(fileLines);
	}

	void DataWriter::writeAccountPlayer(Player* player)
	{
		std::vector<std::string> fileLines;
		const UserLogins logins = player->GetUserLogins();

		fileLines.push_back("ACCOUNT-PLAYER");
		fileLines.push_back(player->GetCreated().ToFormattedString('/'));
		fileLines.push_back(logins.username);
		fileLines.push_back(logins.password);
		fileLines.push_back(std::to_string(player->GetCredit()));

		writeToLineToFile(fileLines);
	}

	void DataWriter::writeAccountAdmin(Admin* admin)
	{
		std::vector<std::string> fileLines;
		const UserLogins logins = admin->GetUserLogins();

		fileLines.push_back("ACCOUNT-ADMIN");
		fileLines.push_back(admin->GetCreated().ToFormattedString('/'));
		fileLines.push_back(logins.username);
		fileLines.push_back(logins.password);
		fileLines.push_back(std::to_string(admin->GetCredit()));


		writeToLineToFile(fileLines);
	}

	void DataWriter::writeOwnedGame(LibraryItem* library_item)
	{
		std::vector<std::string> fileLines;

		fileLines.push_back("LIBRARY-ITEM");
		fileLines.push_back(std::to_string(library_item->GetGame()->GetId()));
		// TODO: Fix issue with dates being way off
		// Until then I've hard coded the dates
		fileLines.push_back(library_item->GetPurchaseDate().ToFormattedString('-'));
		//fileLines.push_back("24-09-2017");
		fileLines.push_back(std::to_string(library_item->GetPlaytime()));

		writeToLineToFile(fileLines);
	}
}

