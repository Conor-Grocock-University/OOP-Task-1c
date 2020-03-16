#pragma once

class Date {

public:
	Date(int day, int month, int year);

	static int CurrentDate(); // static function to get current date
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	int GetTimstamp() const;

private:
	int day;
	int month;
	int year;
	int timestamp;
};

