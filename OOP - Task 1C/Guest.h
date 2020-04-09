#pragma once

#include "LibraryItem.h"
#include "User.h"
#include "Date.h"
#include "List.h"
#include <vector>

class Guest : public User
{
public:
	Guest();
	~Guest();
	void AddGame(const Game* game);
	std::vector<LibraryItem*> GetLibrary() const;

private:

};
