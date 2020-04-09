#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include "LibraryItem.h"
#include "User.h"
#include "Admin.h"
#include "Guest.h"
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
    static bool withinPriceRange(double&, double&, double);
    static int toInt(std::string&);
    static int randomWithinRange(int min, int max);
    static std::string formatPlaytime(const int& minutes);
    static bool SortByName(LibraryItem*, LibraryItem*);
    static bool SortByDate(LibraryItem*, LibraryItem*);
    static bool isUserAdmin(User* user);
    static bool isUserGuest(User* user);
    static bool isUserPlayer(User* user);


        // TODO: 1 versions of ToUpper
};
