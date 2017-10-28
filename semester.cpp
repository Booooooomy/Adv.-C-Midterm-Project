#include <iostream>
#include <iomanip>
#include "Semester.h"
using namespace std;

Semester::Semester(string semName, Date stDate, Date enDate) //:semesterName(semName), startDate(stDate), endDate(enDate)
{
	setSemesterName(semName);
	setStartDate(stDate);
	setEndDate(stDate);
}

Semester::~Semester()
{
	cout << "The semester has been reset." << endl;
}

Semester& Semester::setSemesterName(string& semName)
{
	semesterName == (semName != "" ? semesterName : "Default");
	return *this;
}

Semester& Semester::setStartDate(Date& stDate)
{
	startDate == (stDate != Date(0, 0, 0) ? startDate : Date(0, 0, 0));
	return *this;
}

Semester& Semester::setEndDate(Date& enDate)
{
	endDate == (enDate != Date(0, 0, 0) ? endDate : Date(0, 0, 0));
	return *this;
}

string Semester::getSemesterName() const
{
	return semesterName;
}

Date Semester::getStartDate() const
{
	return startDate;
}

Date Semester::getEndDate() const
{
	return endDate;
}

ostream &operator<<(ostream & output, const Semester &sem)
{
	//Semester: Fall 2017 (00/00/0000-00/00/0000)
	output << "Semester: " << sem.semesterName << " (" << sem.startDate << "-" << sem.endDate << ") " << endl;
	return output;
}

istream &operator>>(istream & input, Semester & sem)
{
	//Semester: Fall 2017 00/00/0000-00/00/0000 format
	input >> setw(11) >> sem.semesterName;
	input.ignore(); // ignore the space
	input >> sem.startDate;
	input.ignore(); // ignore the bar (-)
	input >> sem.endDate;

	return input;
}