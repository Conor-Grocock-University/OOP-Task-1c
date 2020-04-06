#pragma once
#include <fstream>

#include "Admin.h"
#include "Application.h"

namespace data
{
	class DataWriter
	{
	public:
		DataWriter(Application& app);
		void writeToLineToFile(const std::vector<std::string>& lines);
		//~DataParser();

		void writeFile();
	private:
		void writeGame(Game*);
		void writeAccount(Account*);
		void writeAccountPlayer(Player*);
		void writeAccountAdmin(Admin*);
		void writeOwnedGame(LibraryItem*);

	private:
		std::ofstream file;
		Application* app;
	};
}

