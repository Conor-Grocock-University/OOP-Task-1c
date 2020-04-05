#include "DataWriter.h"

namespace data
{
	class DataWriter
	{
		const std::vector<std::string>& writeGame(Game* game) const
		{
			std::vector<std::string> fileLines;

			fileLines.push_back("GAME");
			fileLines.push_back(std::to_string(game->getId()));
			fileLines.push_back(game->GetName());
			fileLines.push_back(game->GetDescription());
			fileLines.push_back(std::to_string(game->GetCost()));
			fileLines.push_back(std::to_string(game->GetAgeRating()));
			
			return fileLines;
		}

		const std::vector<std::string>& writeAccount(Account* account) const
		{
			std::vector<std::string> fileLines;

			fileLines.push_back("ACCOUNT");
			fileLines.push_back(account->getCreated().ToFormattedString());
			const AccountLogins logins = account->GetAccountLogins();
			fileLines.push_back(logins.email);
			fileLines.push_back(logins.password);
			
			return fileLines;
		}

		const std::vector<std::basic_string<char>>& writeAccountPlayer(Player* player)
		{
			std::vector<std::string> fileLines;

			fileLines.push_back("ACCOUNT-PLAYER");
			fileLines.push_back(player->GetCreated().ToFormattedString());
			const UserLogins logins = player->GetUserLogins();
			fileLines.push_back(logins.username);
			fileLines.push_back(logins.password);

			return fileLines;
		}

		const std::vector<std::basic_string<char>>& writeAccountAdmin(Admin* admin)
		{
			std::vector<std::string> fileLines;

			fileLines.push_back("ACCOUNT-ADMIN");
			fileLines.push_back(admin->GetCreated().ToFormattedString());
			const UserLogins logins = admin->GetUserLogins();
			fileLines.push_back(logins.username);
			fileLines.push_back(logins.password);

			return fileLines;			
		}

		const std::vector<std::basic_string<char>>& writeOwnedGame(LibraryItem*)
		{
		}

	};
}

