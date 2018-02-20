#define _SCL_SECURE_NO_WARNINGS
#ifndef CHORES_H
#define COURSE_H
#include <iostream>
#include <string>

using namespace std;

namespace HW6
{
	class Courses
	{
	public:
		Courses();
		Courses(string n, int u, char g);
		Courses(const Courses& source); //copy constructor
		string getName();
		int getUnit();
		char getGrade();
		void changeGrade(char g);
		void print();
		void setCName(string c);
		void setUnit(int u);
		bool operator==(const Courses& source) const;
		void operator =(const Courses& source);
		bool operator!=(const Courses& other);
	private:
		string courseName;
		int courseUnits;
		char courseGrade;
	};
}


#endif COURSE_H
