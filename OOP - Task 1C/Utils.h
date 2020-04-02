#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class Utils
{
public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    static bool startsWith(std::string&, std::string);
    static std::string toUpper(std::string& text);
    // TODO: 1 versions of ToUpper
};
