#pragma once
#include <string>
class Date {

public:

	Date(std::string);
	~Date();
	static const Date CurrentDate(); // static function to get current date
	const std::string ToFormattedString() const;
	
private:

	int day;
	int month;
	int year;
};

