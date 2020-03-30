#include "Date.h"
#include <time.h>
#include <ctime>
#include <string>
#include <iostream>
#include <stdio.h>


Date::Date(const std::string& date) : date(date)
{
}

const Date Date::CurrentDate()
{
	return new Date("30/03/2020"); // returning current timestamp
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