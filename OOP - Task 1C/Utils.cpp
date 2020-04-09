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
	if (left->GetPurchaseDate().GetYear() < right->GetPurchaseDate().GetYear()) { return true; }
	else if (left->GetPurchaseDate().GetYear() == right->GetPurchaseDate().GetYear()) {
		if (left->GetPurchaseDate().GetMonth() < right->GetPurchaseDate().GetMonth()) { return true; }
		else if (left->GetPurchaseDate().GetMonth() == right->GetPurchaseDate().GetMonth()) {
			if (left->GetPurchaseDate().GetDay() < right->GetPurchaseDate().GetDay()) { return true; }
			
		}

	}
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


bool Utils::withinPriceRange(double& min, double& max, double gamePrice)
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

double Utils::toDouble(std::string& number)
{
	return std::stod(number);
}
bool Utils::isUserAdmin(User* user)
{
	try
	{
		if (dynamic_cast<Admin*>(user) == NULL)
			return false;
	}
	catch (const std::bad_cast) { return false; }
	return true;
}


bool Utils::isUserGuest(User* user)
{
	try {
		if (dynamic_cast<Guest*>(user) == NULL)
			return false;
	}
	catch (const std::bad_cast) { return false; }
	return true;
}

bool Utils::isUserPlayer(User* user)
{
	try
	{
		if (dynamic_cast<Player*>(user) == NULL)
			return false;
	}
	catch (const std::bad_cast) { return false; }
	return true;
}

int Utils::randomWithinRange(const int min, const int max)
{
	srand(time(nullptr));
	return rand() % max + min;
}

std::string Utils::formatPlaytime(const int& minutes)
{
	if (minutes <= 59) return std::to_string(minutes) + " Minutes";
	
	const double rounded = std::floor((((double)minutes / 60) * 100) + .5) / 100;
	std::string playTime = std::to_string(rounded);
	rounded < 5 ? playTime.resize(playTime.find('.') + 2) : playTime.resize(playTime.find('.'));
	return playTime + " Hours";
}
