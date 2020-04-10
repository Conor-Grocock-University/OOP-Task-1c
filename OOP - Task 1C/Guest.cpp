#include "Guest.h"

Guest::Guest(Date& date)
	: User("Guest", "", date)
{
}

Guest::Guest()
	: User("Guest", "", Date::CurrentDate())
{
}

Guest::~Guest()
{
}

