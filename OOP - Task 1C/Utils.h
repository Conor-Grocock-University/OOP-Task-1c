#pragma once

#include <string>
#include <iostream>

class Utils
{
public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    static bool startsWith(std::string&, std::string&);
    // TODO: 2 versions of ToUpper
};
