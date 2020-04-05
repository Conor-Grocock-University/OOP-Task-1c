#pragma once
#include "Admin.h"
#include "Application.h"

namespace data
{
	class DataWriter
	{
	public:
		DataWriter(const Application& app);
		//~DataParser();

		void writeFile();
	private:
		const std::vector<std::string>& writeGame(Game*) const;
		const std::vector<std::string>& writeAccount(Account*) const;
		const std::vector<std::basic_string<char>>& writeAccountPlayer(Player*);
		const std::vector<std::basic_string<char>>& writeAccountAdmin(Admin*);
		const std::vector<std::basic_string<char>>& writeOwnedGame(LibraryItem*);

	private:
		bool error;
		//std::ofstream file;
		std::vector<std::string> lines;
	};
}

