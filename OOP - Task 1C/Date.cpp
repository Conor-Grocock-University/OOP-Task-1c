#include "Date.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
Date::Date(const char date[])
{
	int length = 10; // hardcoded length value as the date should only be 10 characters DD/MM/YYYY
	int sepCount = 0; // increments when a '/' is found
	int countFromSep = 0; // increments each loop
	char dayCh[2] = "";
	char monthCh[2] = "";
	char yearCh[4] = "";

	try
	{
		for (int i = 0; i < length; i++) {
			if (date[i] == '/' || date[i] == '-') { // if the next char is '/'
				sepCount++;
				countFromSep = 0;
				continue;	// continue looping
			}

			switch (sepCount) {
			case 0: {
					assert(countFromSep < 2);
				dayCh[countFromSep] = date[i]; // storing day 
			}
			case 1: {
					assert(countFromSep < 2);
				monthCh[countFromSep] = date[i]; // storing month
			}
			case 2: {
					assert(countFromSep < 4);
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
	if (year > GetCurrentYear()) { return true; } // if the year is after the current year (in the future)
	else { return false; }
}
bool Date::CheckMonth()
{
	if (month >= 1 && month <= 12) { return true; } // if the month is between Jan - Dec
	else { return false; }
}

bool Date::CheckDay()
{
	if (day >= 1 && day <= GetDaysInMonth()) { return true; }
	else { return false; }
}

/*Function to get the days in each month */
int Date::GetDaysInMonth()
{
	//leap year condition, if month is feb
	if (month ==  2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	//months which have 30 days
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31; // all other months have 30 days
}

int Date::GetCurrentYear()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	return 	newtime.tm_year + 1900;

}
Date Date::CurrentDate()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int month = 1 + newtime.tm_mon;
	int day = newtime.tm_mday;
	int year = newtime.tm_year + 1900;
	char dates[10];

	dates[0] = (day / 10) + '0';
	dates[1] = (day % 10) + '0';
	dates[2] = '/';
	dates[3] = (month / 10) + '0';
	dates[4] = (month % 10) + '0';
	dates[5] = '/';
	dates[6] = (year / 1000) + '0';
	dates[7] = (year / 100) % 10 + '0';
	dates[8] = (year / 10) % 10 + '0';
	dates[9] = (year % 10) + '0';


	Date currentDate = Date(dates); // creating new date object (ptr)

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
