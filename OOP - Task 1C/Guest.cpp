#include "Guest.h"

Guest::Guest() : User("Guest", "", Date::CurrentDate())
{
}

Guest::~Guest()
{
}

void Guest::AddGame(const Game* game)
{
	library.push_back(new LibraryItem(Date::CurrentDate(), game)); 
}

std::vector<LibraryItem*> Guest::GetLibrary() const
{
	return library;
}