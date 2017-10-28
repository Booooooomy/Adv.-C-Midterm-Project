#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

class Semester
{
	friend ostream &operator<<(ostream &, const Semester &);
	friend istream &operator>>(istream &, Semester &);

private:
	string semesterName;
	Date startDate;
	Date endDate;

public:
	Semester(string, Date, Date);
	~Semester();

	Semester& setSemesterName(string&);
	Semester& setStartDate(Date&);
	Semester& setEndDate(Date&);
	string getSemesterName() const;
	Date getStartDate() const;
	Date getEndDate() const;

};

#endif SEMESTER_H