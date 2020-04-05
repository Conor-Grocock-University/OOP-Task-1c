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