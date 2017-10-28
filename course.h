#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Course
{
	friend ostream &operator<<(ostream &, const Course &);

private:
	string courseNum;
	string courseName;
	string meetDays;
	double unit;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;

public:
	Course(string, string, string, double, Date, Date, Time, Time);
	~Course();
	string getCourseNum() const;
	string getCourseName() const;
	string getMeetDays() const;
	double getUnit() const;
	Date getStartDate() const;
	Date getEndDate() const;
	Time getStartTime() const;
	Time getEndTime() const;

	Course& setCourseNum(string&);
	Course& setCourseName(string&);
	Course& setMeetDays(string&);
};

#endif
