#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class Utils
{
public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    static bool startsWith(std::string&, std::string);
    static std::string toUpper(std::string& text);
    static void recursiveToUpper(char*);
    static std::string toLowerString(std::string&);
    static std::string toUpperString(std::string);
    static bool withinPriceRange(int&, int&, int);
    static int toInt(std::string&);
	
    static std::vector<std::string> Utils::splitVector(const std::vector<std::string>& original, int start, int end);
};

