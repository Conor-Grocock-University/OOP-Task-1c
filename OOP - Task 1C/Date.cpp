#include "Date.h"
#include <string>
#include <iostream>

Date::Date(std::string date)
{
	std::string delimiter = "/"; // creating a delimiter that will be used to split the string

	size_t pos = 0;
	std::string dates[3] = {}; // creating a fixed 3 item array of strings which will be the day / month / year
	int i = 0; // incrementor

	while ((pos = date.find(delimiter)) != std::string::npos) { // while there are "/" characters in the string
		dates[i] = date.substr(0, pos); // storing the first, second & third split strings in the array
		date.erase(0, pos + delimiter.length()); // removing the first position of the string (DD/MM/YYYY becomes MM/YYYY etc.)

		i++;
	}

	// storing correct dates in variables
	day = std::stoi(dates[0]);
	month = std::stoi(dates[1]);
	year = std::stoi(dates[2]);
}

// destructor
Date::~Date()
{
} 

const Date Date::CurrentDate()
{
	return Date; // returning current timestamp
}


const std::string Date::ToFormattedString() const
{
	return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year); // formatting to "DD/MM/YYYY"
}
