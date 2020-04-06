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
    static std::string toLowerString(std::string); // we don't want to pass by reference as we don't want to altar the base string value
    static std::string toUpperString(std::string);
    static bool withinPriceRange(int&, int&, int);
    static int toInt(std::string&);
    static bool SortByName(LibraryItem*, LibraryItem*);
    static bool SortByDate(LibraryItem*, LibraryItem*);
        // TODO: 1 versions of ToUpper
};
