#pragma once
#include <ctime>
#include <time.h>
class Date {

public:
	Date(const std::string&);

	static const Date CurrentDate(); // static function to get current date
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	//time_t GetTimstamp();

private:
	std::string date;
	int day;
	int month;
	int year;
	//time_t timestamp;
};

