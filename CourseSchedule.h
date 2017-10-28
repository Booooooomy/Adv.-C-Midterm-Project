#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include "semester.h"
#include <string>

class CourseSchedule
{
private:
	static int numCourses;
	Course* Courses;
	int maxSize;
	string sname; // student name
	Semester smester;
	Date startDate;
	Date endDate;
	void checkDates(Semester, Date, Date);

public:
	CourseSchedule(string, Semester, int);
	~CourseSchedule();
	string getStudentName() const;
	Semester getSemester() const;
	int getnumCourse() const;
	void setStudentName(string);
};

#endif COURSESHEDULE_H