#pragma once
#include <string>
class Date {

public:

	Date(const char[]);
	static Date CurrentDate(); // static function to get current date
	const std::string ToFormattedString() const;
	const std::string ToFormattedString(char seperator) const;
	int GetDaysInMonth();
	int GetCurrentYear();
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
};

