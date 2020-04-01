#include "Date.h"
#include <string>
#include <iostream>
#include <ctime>

Date::Date(char date[])
{
	int length = 10; // hardcoded length value as the date should only be 10 characters DD/MM/YYYY
	int sepCount = 0; // increments when a '/' is found
	int countFromSep = 0; // increments each loop
	char dayCh[2];
	char monthCh[2];
	char yearCh[4];

	try
	{
		for (int i = 0; i < length; i++) {
			if (date[i] == '/') { // if the next char is '/'
				sepCount++;
				countFromSep = 0;
				continue;	// continue looping
			}

			switch (sepCount) {
			case 0: {
				dayCh[countFromSep] = date[i]; // storing day 
			}
			case 1: {
				monthCh[countFromSep] = date[i]; // storing month
			}
			case 2: {
				yearCh[countFromSep] = date[i]; // storing year

			}
				  countFromSep++;
			}
		}

		/* converting chars to int */
		day = atoi(dayCh);
		month = atoi(monthCh);
		year = atoi(yearCh);
	}
	catch (...) // catching any exception
	{
		std::cout << "ERROR PARSING DATES"; 
	}

}

// destructor
Date::~Date()
{
} 

// validity checks for dates
bool Date::CheckDates()
{
	if (CheckYear())
	{
		if (CheckMonth())
		{
			if (CheckDay())
			{
				return true;
			}
		}
	}
	return false;

}

bool Date::CheckYear()
{
	if (year > currentDate->GetYear()) { return true; } // if the year is after the current year (in the future)
	else { return false; }
}
bool Date::CheckMonth()
{
	if (month >= 1 && month <= 12) { return true; } // if the month is between Jan - Dec
	else { return false; }
}

bool Date::CheckDay()
{
	if (day == 0) { return false; }
	else if (month == 4 || month == 6 || month == 9 || month == 11) // if month is April, June, Sep or Nov
	{
		if (day <= 30) { return true; }
		else { return false; }
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) // if month is Jan, Mar, May, Jul, Aug, Oct or Dec
	{
		if (day <= 31) { return true; }
		else { return true; }
	}
	else if (month == 2) // if month is Feb
	{
		if (day <= 29) { return true; }
		else { return false; }
	}
	else { return false; }
}

Date* Date::CurrentDate()
{
	time_t rawtime; // creating time obj (usually a timestamp)
	struct tm* dateStruct; // creating currentDate obj
	char buffer[80];		// creating a large enough buffer

	time(&rawtime);
	dateStruct = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d/%m/%Y", dateStruct); // formatting time into DD/MM/YYYY format
	std::string dateString(buffer);   // converting to string

	 currentDate = new Date(dateString); // creating new date object (ptr)

	return currentDate; // returning current date object
}

const int Date::GetYear() 
{
	return year;
}
const int Date::GetMonth()
{
	return month;
}
const int Date::GetDay()
{
	return day;
}
const std::string Date::ToFormattedString() const
{
	return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year); // formatting to "DD/MM/YYYY"
}
