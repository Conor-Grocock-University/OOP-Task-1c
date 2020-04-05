#include "Utils.h"

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
