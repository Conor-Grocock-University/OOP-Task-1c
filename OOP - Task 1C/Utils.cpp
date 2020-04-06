#include "Utils.h"
#include <cstdio>

std::string Utils::getLineFromUser()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

char Utils::getCharFromUser()
{
	return toupper(getLineFromUser()[0]);
}


void Utils::recursiveToUpper(char* str)
{
	if (*str != '\0') {
		*str = toupper(*str);  // do this char
		recursiveToUpper(str + 1); // recursively do the remaining chars
	}
}


bool Utils::SortByName(LibraryItem* left, LibraryItem* right)
{
	return left->GetGame()->GetName() < right->GetGame()->GetName();
}

bool Utils::SortByDate(LibraryItem* left, LibraryItem* right)
{
	if (left->GetPurchaseDate().GetYear() == right->GetPurchaseDate().GetYear())			   // if both items have the same year
		if (left->GetPurchaseDate().GetMonth() == right->GetPurchaseDate().GetMonth())	       // if both items have the same month
			if (left->GetPurchaseDate().GetDay() == right->GetPurchaseDate().GetDay())	       // if both items have the same month
				return true;
	
	if (left->GetPurchaseDate().GetYear()  < right->GetPurchaseDate().GetYear())  return true; // if the left hand item has a year that is less than the right side year
	if (left->GetPurchaseDate().GetMonth() < right->GetPurchaseDate().GetMonth()) return true; // if the left hand item has a month that is less than the right side month
	if (left->GetPurchaseDate().GetDay()   < right->GetPurchaseDate().GetDay())   return true; // if the left item has a day that is less than the right side day
	
	
	return false;
}

std::string Utils::toUpper(std::string& text)
{
	std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	return text;
}


std::string Utils::toLowerString(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++) // for each time that str[index] is not null (end of string)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')    // checking for uppercase characters
			str[i] = str[i] + 32;         // converting uppercase to lowercase
	}
	return str;
}

std::string Utils::toUpperString(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)	// for each time that str[index] is not end of string
	{
		if (str[i] >= 'a' && str[i] <= 'z')   //checking for lowercase characters
			str[i] = str[i] - 32;        // converting lowercase to uppercase
	}

	return str;
}

bool Utils::startsWith(std::string& searchText, std::string gameName)
{
	return toUpper(gameName).find(toUpper(searchText)) == 0; // if the search text is found at the beginning of game name (if the game name starts with search text)
}


bool Utils::withinPriceRange(int& min, int& max, int gamePrice)
{
	return ((gamePrice - max) * (gamePrice - min) <= 0); // if the price is within the range of min and max values
}

int Utils::toInt(std::string& number)
{
	return std::stoi(number);
}

std::vector<std::string> Utils::splitVector(const std::vector<std::string>& original, int start, int end)
{
	return std::vector<std::string>(original.begin() + start, original.begin() + start + end);
}

