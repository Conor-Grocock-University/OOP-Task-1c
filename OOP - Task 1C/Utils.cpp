#include "Utils.h"
#include <iomanip>
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

std::string Utils::toUpper(std::string& text)
{
	std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	return text;
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
	return left->GetGameName() < right->GetGameName();
}

bool Utils::SortByDate(LibraryItem* left, LibraryItem* right)
{
	if (left->GetDateOfPurchase().GetYear() < right->GetDateOfPurchase().GetYear()) { return true; }
	else if (left->GetDateOfPurchase().GetYear() == right->GetDateOfPurchase().GetYear()) {
		if (left->GetDateOfPurchase().GetMonth() < right->GetDateOfPurchase().GetMonth()) { return true; }
		else if (left->GetDateOfPurchase().GetMonth() == right->GetDateOfPurchase().GetMonth()) {
			if (left->GetDateOfPurchase().GetDay() < right->GetDateOfPurchase().GetDay()) { return true; }
			else {return false;}
		} else { return false; }
	} else	{ return false;}

}


std::string Utils::toLowerString(std::string& str)
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

int Utils::randomWithinRange(int min, int max)
{
	srand(time(NULL));
	int number = rand() % max + min;
	return number;
}

std::string Utils::formatPlaytime(const int& minutes)
{
	if (minutes > 59)
	{
		double rounded = std::floor((((double)minutes / 60) * 100) + .5) / 100;
		std::string playTime = std::to_string(rounded);
		rounded < 5 ? playTime.resize(4) : playTime.resize(1);
		return playTime + " Hours";
	}else
		return  std::to_string(minutes) + " Minutes";
}



