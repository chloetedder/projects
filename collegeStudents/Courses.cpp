#define _SCL_SECURE_NO_WARNINGS
#include "Courses.h"

namespace HW6
{
	Courses::Courses()
	{
		courseName = "";
		courseUnits = 0;
		courseGrade = ' ';
	}
	Courses::Courses(string n, int u, char g)
	{
		courseName = n;
		courseUnits = u;
		courseGrade = g;
	}
	Courses::Courses(const Courses& source)
	{
		courseName = source.courseName;
		courseUnits = source.courseUnits;
		courseGrade = source.courseGrade;
	}
	string Courses::getName()
	{
		return courseName;
	}
	int Courses::getUnit()
	{
		return courseUnits;
	}
	char Courses::getGrade()
	{
		return courseGrade;
	}
	void Courses::changeGrade(char g)
	{
		courseGrade = g;
	}
	void Courses::print()
	{
		cout << "Course:\n" << courseName << endl << "Units:\n" << courseUnits << "\nGrade:\n" << courseGrade << endl << endl;
	}

	void Courses::setCName(string c)
	{
		courseName = c;
	}

	void Courses::setUnit(int u)
	{
		courseUnits = u;
	}

	bool Courses::operator==(const Courses& source) const
	{
		if ((this->courseName == source.courseName) && (this->courseUnits == source.courseUnits) && (this->courseGrade == source.courseGrade))
			return true;
		return false;
	}

	void Courses::operator =(const Courses& source)
	{
		this->courseName = source.courseName;
		this->courseGrade = source.courseGrade;
		this->courseUnits = source.courseUnits;
	}
	bool Courses::operator!=(const Courses& other)
	{
		if ((this->courseName == other.courseName) && (this->courseUnits == other.courseUnits) && (this->courseGrade == other.courseGrade))
			return false;
		return true;
	}
}
