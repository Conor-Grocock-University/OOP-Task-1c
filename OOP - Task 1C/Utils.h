#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include "LibraryItem.h"

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
    static bool SortByName(LibraryItem*, LibraryItem*);
        // TODO: 1 versions of ToUpper
};
