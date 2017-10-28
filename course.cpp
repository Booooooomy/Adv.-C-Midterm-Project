#include <iostream>
#include <iomanip>
#include "Course.h"
using namespace std;

//verify if I did this part correct 
Course::Course(string csNum, string csName, string mtDays, double unt, Date stDate, Date enDate, Time stTime, Time enTime)
	:courseNum(csNum), courseName(csName), meetDays(mtDays), unit(unt), startDate(stDate), endDate(enDate), startTime(stTime), endTime(enTime)
{/*
 setCourseNum(csNum);
 setCourseName(csName);
 setMeetDays(mtDays);*/
}

//destructor
Course::~Course()
{
	cout << "The course has been deleted. " << endl;
}


///////////////////////////////////////////get functions
string Course::getCourseNum() const
{
	return courseNum;
}

string Course::getCourseName() const
{
	return courseName;
}

string Course::getMeetDays() const
{
	return meetDays;
}

double Course::getUnit() const
{
	return unit;
}

Date Course::getStartDate() const
{
	//should I apply checkDay function here?
	return startDate;
}

Date Course::getEndDate() const
{
	return startDate;
}

Time Course::getStartTime() const
{
	return startTime;
}

Time Course::getEndTime() const
{
	return endTime;
}


///////////////////////////////////////////set functions
Course& Course::setCourseNum(string& csNum)
{
	courseNum == (csNum != "" ? courseNum : "000");
	return *this;
}

Course& Course::setCourseName(string& csName)
{
	courseName == (csName != "" ? courseName : "Course Name");
	return *this;
}

Course& Course::setMeetDays(string& meets)
{
	meetDays == (meets != "" ? meetDays : "MTWTF");
	return *this;
}

//////////////////////////////////////////// iostream operators
ostream &operator << (ostream &output, const Course& course)//, const Date& date, const Time& time) //ohh!!
{
	/*
	Course Info: CSIS 112 -- Java
	# of Units: 3.00
	Course Dates: 09/06/2017 – 12/18/2017
	Meeting Days: T
	Meeting Time: 6:55PM - 10:05PM
	Daily Duration: 1.42 hours
	*/
	output << "Course Info: " << course.courseName << endl
		<< "# of Units: " << setprecision(2) << course.unit << endl
		<< "Course Dates: " << course.startDate << " - " << course.endDate << endl
		<< "Meeting Days: " << course.meetDays << endl
		//<< "Meeting Time: " << course.startTime << " - " << course.endTime << endl 
		//^ the error occurs bc there's no << operator in Time.h
		<< "Daily Duration: ";
	return output;
}

ostream &operator >> (istream &input, Course& course)
{
	input;
	return input;
}