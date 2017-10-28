#include <iostream>
#include <iomanip>
using namespace std;

#include "Date.h"

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
	setDate(mn, dy, yr);
}

//destructor
Date::~Date()
{
}

// get/set functions - cascading allowed by *this 
Date& Date::setDate(int mn, int dy, int yr)
{
	setMonth(mn);
	setDay(dy);
	setYear(yr);
	return *this;
}

Date& Date::setMonth(int mn)
{
	month = (mn >= 1 && mn <= 31) ? mn : 1;
	return *this;
}

Date& Date::setDay(int dy)
{
	day = (dy >= 1 && dy <= 31) ? dy : 1;
	return *this;
}

Date& Date::setYear(int yr)
{
	year = (yr >= 2001 && yr <= 2999) ? yr : 2017;
	return *this;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (testDay > 0 && testDay <= daysPerMonth[month])
	{
		return testDay;
	}

	//determine whether testDay is valid for a specific month
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
	{
		return testDay;
	}

	cout << "Invalid Day " << testDay << " was set to 1" << endl;
	return 1;  //keep data in valid state
}

// iostream operator
ostream &operator << (ostream &output, const Date &date)
{
	output << setfill('0') << setw(2) << date.month << "/" << setw(2) << date.day << setw(2) << date.year;
	return output;
}

istream &operator >> (istream &input, Date &date)
{
	// check if it assepts 6 as if 06 was entered ////////////////////////

	// asssume that input is MM/DD/YYYY form
	input >> setw(2) >> date.month;
	input.ignore(); // skip /
	input >> setw(2) >> date.day;
	input.ignore(); // skip /
	input >> setw(4) >> date.year;
	return input;
}

// note: maybe I should change startTime to more common time class later 
// (I need to check endtime of classes as well) 
bool Date::operator > (const Date &right) const
{
	//can't directly access to private member variable in different class -- use get functions 
	return (StartTime.getHour() > right.StartTime.getHour() && StartTime.getMinute() > right.StartTime.getMinute() ? true : false);
}

bool Date::operator < (const Date &right) const
{
	return !(operator >(right)); // does it work?
}

bool Date::operator == (const Date &right) const
{
	return (StartTime.getHour() == right.StartTime.getHour() && StartTime.getMinute() == right.StartTime.getMinute() ? true : false);
}

bool Date::operator != (const Date &right) const
{
	return !(operator ==(right));
}

bool Date::operator >= (const Date &right) const
{
	return (operator >(right) || operator ==(right) ? true : false);
}

bool Date::operator <= (const Date &right) const
{
	return (operator <(right) || operator ==(right) ? true : false);
}