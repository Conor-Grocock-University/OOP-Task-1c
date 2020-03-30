#pragma once
#include <ctime>
#include <time.h>
class Date {

public:
	Date(int day, int month, int year);

	static const int CurrentDate(); // static function to get current date
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	//time_t GetTimstamp();

private:
	int day;
	int month;
	int year;
	//time_t timestamp;
};

