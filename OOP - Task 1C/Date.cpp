#include "Date.h"
#include <string>
#include <iostream>
#include <ctime>

Date::Date(std::string date)
{
	std::string delimiter = "/"; // creating a delimiter that will be used to split the string

	size_t pos = 0;
	std::string dates[3] = {}; // creating a fixed 3 item array of strings which will be the day / month / year
	int i = 0; // incrementor
	try
	{
		while ((pos = date.find(delimiter)) != std::string::npos) { // while there are "/" characters in the string
			dates[i] = date.substr(0, pos); // storing the first, second & third split strings in the array
			date.erase(0, pos + delimiter.length()); // removing the first position of the string (DD/MM/YYYY becomes MM/YYYY etc.)

			i++;
		}
	
		// storing correct dates in variables
		day = std::stoi(dates[0]);
		month = std::stoi(dates[1]);
		year = std::stoi(dates[2]);
		currentDate = CurrentDate(); // creating an instance of current date
		CheckDates(); // checking to see if the dates are valid
	}
	catch (...) // catching any exceptions (if the dates aren't numbers for example)
	{
		std::cout << "ERROR PARSING DATES!";
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
