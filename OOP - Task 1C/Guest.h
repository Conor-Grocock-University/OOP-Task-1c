#pragma once

#include "LibraryItem.h"
#include "User.h"
#include "Date.h"
#include "List.h"
#include <vector>

class Guest : public User
{
public:
	Guest(Date& date);
	Guest();

private:

};
