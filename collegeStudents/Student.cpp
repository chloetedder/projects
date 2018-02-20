#define _SCL_SECURE_NO_WARNINGS
#include <cassert>  // Provides assert
#include <cstdlib>  // Provides NULL, rand, size_t
#include "node1.h"  // Provides node and the linked list functions
#include "student.h"
using namespace std;

namespace HW6
{

	student::student()
		// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		many_nodes = 0;
		first = "";
		last = "";
		gpa = 0;
	}

	student::student(string f, string l)
	{
		first = capitalizeF(f);
		last = capitalizeL(l);
		gpa = 0;
		head_ptr = NULL;
		many_nodes = 0;
	}

	student::student(const student& source)
		// Library facilities used: node1.h
	{
		node *tail_ptr;  // Needed for argument of list_copy

		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;

		first = source.first;
		last = source.last;
		gpa = source.gpa;
	}

	student::~student()
		// Library facilities used: node1.h
	{
		list_clear(head_ptr);
		many_nodes = 0;
	}

	student::size_type student::count(const value_type& target) const
		// Library facilities used: cstdlib, node1.h
	{
		size_type answer;
		const node *cursor; // Use const node* since we don't change the nodes.

		answer = 0;
		cursor = list_search(head_ptr, target);
		while (cursor != NULL)
		{
			// Each time that cursor is not NULL, we have another occurrence of
			// target, so we add one to answer, and move cursor to the next
			// occurrence of the target.
			++answer;
			cursor = cursor->link();
			cursor = list_search(cursor, target);
		}
		return answer;
	}

	student::size_type student::erase(const value_type& target)
		// Library facilities used: cstdlib, node1.h
	{
		size_type answer = 0;
		node *target_ptr;

		target_ptr = list_search(head_ptr, target);
		while (target_ptr != NULL)
		{
			// Each time that target_ptr is not NULL, we have another occurrence
			// of target. We remove this target using the same technique that
			// was used in erase_one.
			target_ptr->set_data(head_ptr->data());
			target_ptr = target_ptr->link();
			target_ptr = list_search(target_ptr, target);
			list_head_remove(head_ptr);
			--many_nodes;
			++answer;
		}
		return answer;
	}

	bool student::erase_one(const value_type& target)
		// Library facilities used: cstdlib, node1.h
	{
		node *target_ptr;

		target_ptr = list_search(head_ptr, target);
		if (target_ptr == NULL)
			return false; // target isn't in the bag, so no work to do
		target_ptr->set_data(head_ptr->data());
		list_head_remove(head_ptr);
		--many_nodes;
		return true;
	}

	void student::insert(const value_type& entry)
		// Library facilities used: node1.h
	{
		list_head_insert(head_ptr, entry);
		++many_nodes;
	}

	void student::operator +=(const student& addend)
		// Library facilities used: cstdlib, node1.h
	{
		node *copy_head_ptr;
		node *copy_tail_ptr;

		if (addend.many_nodes > 0)
		{
			list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
			copy_tail_ptr->set_link(head_ptr);
			head_ptr = copy_head_ptr;
			many_nodes += addend.many_nodes;
		}
	}

	string student::capitalizeF(string f)
	{
		string newF = "";
		for (int x = 0; x < f.size(); x++)
		{
			char l = f.at(x);
			switch (l)
			{
			case 'a':
			case 'A':
				newF += "A";
				break;
			case'b':
			case 'B':
				newF += "B";
				break;
			case 'c':
			case 'C':
				newF += "C";
				break;
			case'd':
			case 'D':
				newF += "D";
				break;
			case 'e':
			case 'E':
				newF += "E";
				break;
			case'f':
			case 'F':
				newF += "F";
				break;
			case 'g':
			case 'G':
				newF += "G";
				break;
			case'h':
			case 'H':
				newF += "H";
				break;
			case 'i':
			case 'I':
				newF += "I";
				break;
			case'j':
			case 'J':
				newF += "J";
				break;
			case 'k':
			case 'K':
				newF += "K";
				break;
			case'l':
			case 'L':
				newF += "L";
				break;
			case 'm':
			case 'M':
				newF += "M";
				break;
			case'n':
			case 'N':
				newF += "N";
				break;
			case 'o':
			case 'O':
				newF += "O";
				break;
			case'p':
			case 'P':
				newF += "P";
				break;
			case 'q':
			case 'Q':
				newF += "Q";
				break;
			case'r':
			case 'R':
				newF += "R";
				break;
			case 's':
			case 'S':
				newF += "S";
				break;
			case't':
			case 'T':
				newF += "T";
				break;
			case 'u':
			case 'U':
				newF += "U";
				break;
			case'v':
			case 'V':
				newF += "V";
				break;
			case 'w':
			case 'W':
				newF += "W";
				break;
			case'x':
			case 'X':
				newF += "X";
				break;
			case 'y':
			case 'Y':
				newF += "Y";
				break;
			case'z':
			case 'Z':
				newF += "Z";
				break;
			default:
				cout << "name error\n";
				break;
			}
		}

		return newF;
	}
	string student::capitalizeL(string L)
	{
		string newL = "";
		for (int x = 0; x < L.size(); x++)
		{
			char l = L.at(x);
			switch (l)
			{
			case 'a':
			case 'A':
				newL += "A";
				break;
			case'b':
			case 'B':
				newL += "B";
				break;
			case 'c':
			case 'C':
				newL += "C";
				break;
			case'd':
			case 'D':
				newL += "D";
				break;
			case 'e':
			case 'E':
				newL += "E";
				break;
			case'f':
			case 'F':
				newL += "F";
				break;
			case 'g':
			case 'G':
				newL += "G";
				break;
			case'h':
			case 'H':
				newL += "H";
				break;
			case 'i':
			case 'I':
				newL += "I";
				break;
			case'j':
			case 'J':
				newL += "J";
				break;
			case 'k':
			case 'K':
				newL += "K";
				break;
			case'l':
			case 'L':
				newL += "L";
				break;
			case 'm':
			case 'M':
				newL += "M";
				break;
			case'n':
			case 'N':
				newL += "N";
				break;
			case 'o':
			case 'O':
				newL += "O";
				break;
			case'p':
			case 'P':
				newL += "P";
				break;
			case 'q':
			case 'Q':
				newL += "Q";
				break;
			case'r':
			case 'R':
				newL += "R";
				break;
			case 's':
			case 'S':
				newL += "S";
				break;
			case't':
			case 'T':
				newL += "T";
				break;
			case 'u':
			case 'U':
				newL += "U";
				break;
			case'v':
			case 'V':
				newL += "V";
				break;
			case 'w':
			case 'W':
				newL += "W";
				break;
			case'x':
			case 'X':
				newL += "X";
				break;
			case 'y':
			case 'Y':
				newL += "Y";
				break;
			case'z':
			case 'Z':
				newL += "Z";
				break;
			default:
				cout << "name error\n";
				break;
			}
		}
		return newL;
	}
	bool student::operator!=(const student& source)
	{

		if ((this->first == source.first) && (this->last == source.last))
			return false;
		return true;
	}
	bool student::operator==(const student& source)
	{
		if ((this->first == source.first) && (this->last == source.last))
			return true;
		return false;
	}

	void student::operator =(const student& source)
		// Library facilities used: node1.h
	{
		node *tail_ptr; // Needed for argument to list_copy

		if (this == &source)
		{
			return;
		}
		list_clear(head_ptr);
		many_nodes = 0;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		this->first = source.first;
		this->last = source.last;
		this->gpa = source.gpa;
	}

	student operator +(const student& b1, const student& b2)
	{
		student answer;

		answer += b1;
		answer += b2;
		return answer;
	}

	void student::printFile(ofstream& fout)
	{
		this->calcGPA();
		fout << "Student Name:\n" << first << " " << last << endl << "GPA:\n" << gpa << endl << endl;
		for (const node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			fout << "Course:\n";
			Courses c = cursor->data();
			fout << c.getName() << "\nUnits:\n" << c.getUnit() << "\nGrade:\n" << c.getGrade() << endl << endl;
		}
	}

	void student::print()
	{
		this->calcGPA();
		cout << "Student Name:\n" << first << " " << last << endl << "GPA:\n" << gpa << endl << endl;
		for (const node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			Courses c = cursor->data();
			c.print();
		}
	}

	void student::setGPA(double g)
	{
		gpa = g;
	}

	void student::calcGPA()
	{
		double sum = 0;
		int totalUnits = 0;
		for (const node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			Courses c = cursor->data();
			int u = c.getUnit();
			char g = c.getGrade();
			double grade = 0;
			totalUnits += u;

			switch (g)
			{
			case 'A':
				grade = 4;
				break;
			case 'B':
				grade = 3;
				break;
			case 'C':
				grade = 2;
				break;
			case 'D':
				grade = 1;
			case 'F':
				grade = 0;
				break;
			default:
				cout << "error in grade\n";
				break;
			}
			sum += grade*u;
		}
		if (totalUnits == 0)
			gpa = 0;
		else
			gpa = sum / totalUnits;

	}

	void student::setName(string f, string l)
	{
		first = capitalizeF(f);
		last = capitalizeL(l);
	}

	string student::getFirst() const
	{
		return first;
	}
	string student::getLast() const
	{
		return last;
	}
}

