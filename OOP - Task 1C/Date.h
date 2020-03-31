#pragma once
#include <string>
class Date {

public:

	Date(std::string);
	~Date();
	static Date* CurrentDate(); // static function to get current date
	const std::string ToFormattedString() const;
	bool CheckDates();
	bool CheckYear();
	bool CheckMonth();
	bool CheckDay();
	const int GetYear();
	const int GetMonth();
	const int GetDay();
private:

	int day;
	int month;
	int year;
	static Date* currentDate;
};

