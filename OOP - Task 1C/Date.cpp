#include "Date.h"
#include <string>
#include <iostream>

Date::Date(const std::string& date) : date(date)
{
}

const Date Date::CurrentDate()
{
	return Date; // returning current timestamp
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

const std::string Date::ToFormattedString() const
{
	return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year); // formatting to "DD/MM/YYYY"
}
