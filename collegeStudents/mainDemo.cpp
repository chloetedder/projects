#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include "college.h"

using namespace std;
using namespace HW6;

int main()
{
	college USM;

	int choice = 0;
	bool stayInLoop = true;
	string fileName, first, last;

	cout << "Printing the initial list of students\n" << endl;
	USM.printStudents(false);

	while (stayInLoop)
	{
		cout << "\nEnter 0 for adding a student's record" << endl;
		cout << "Enter 1 for deleteing a student's record" << endl;
		cout << "Enter 2 for adding a single course record to a student record" << endl;
		cout << "Enter 3 for deleting a single course record from a student record" << endl;
		cout << "Enter 4 to exit the program\n" << endl;
		cin >> choice;

		if (choice == 4)
		{
			cout << "Writing students to file\n";
			USM.printStudents(true);
			cout << "Exiting program\n" << endl;

			system("pause");
			return 0;
		}

		cout << "Enter the student's first name who is to be manipulated" << endl;
		cin >> first;
		cout << "Enter the student's last name who is to be manipulated" << endl;
		cin >> last;
		student s(first, last);

		switch (choice)
		{
		case 0:

			USM.addStudent(s);

			cout << "Printing the updated list after adding a student\n" << endl;
			USM.printStudents(true);
			break;
		case 1:
			USM.removeStudent(s);

			cout << "Printing the updated list after deleting a student\n" << endl;
			USM.printStudents(true);
			break;
		case 2:
			USM.addCourse(s);
			cout << "Printing the updated list after adding a course\n" << endl;
			USM.printStudents(true);
			break;
		case 3:
			USM.removeCourse(s);
			cout << "Printing the updated list after deleting a course\n" << endl;
			USM.printStudents(true);
			break;
		default:
			cout << "Invalid input try again\n" << endl;
			break;
		}
	}



	system("pause");
	return 0;
}

