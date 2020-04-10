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

		void writeFile();
	private:
		void writeGame(Game*);
		void writeAccount(Account*);
		void writeAccountPlayer(Player*);
		void writeAccountAdmin(Admin*);
		void writeAccountGuest(Guest*);
		void writeOwnedGame(LibraryItem*);
		void writeGuestGame(LibraryItem* library_item);

		void writeToLineToFile(const std::vector<std::string>& lines);
	private:
		std::ofstream file;
		Application* app;
	};
}

