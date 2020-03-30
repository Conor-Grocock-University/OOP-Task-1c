#include "Date.h"
#include <time.h>
#include <ctime>
#include <string>
#include <iostream>
#include <stdio.h>


Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

const int Date::CurrentDate()
{
	time_t t = std::time(0); // getting current time
	long int now = static_cast<long int> (t); // casting to int

	return now; // returning current timestamp
}

int Date::GetDay() const
{
	return this->day;
}

int Date::GetMonth() const
{
	return this->month;
}

int Date::GetYear() const
{
	return this->year;
}

/*
time_t Date::GetTimstamp()
{
	struct tm tm;
	std::string format = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	
	timestamp = mktime(&tm);

	return this->timestamp;
}
*/