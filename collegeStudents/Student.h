#define _SCL_SECURE_NO_WARNINGS
#ifndef STUDENT_H
#define STUDENT_H
#include <cstdlib>   // Provides size_t and NULL
#include "node1.h"   // Provides node class
#include <fstream>

namespace HW6
{
	class student
	{
	public:
		// TYPEDEFS
		typedef std::size_t size_type;
		typedef Courses value_type;
		//or node::value_type
		// CONSTRUCTORS and DESTRUCTOR
		student();
		student(string f, string l);
		student(const student& source);
		~student();
		// MODIFICATION MEMBER FUNCTIONS
		size_type erase(const value_type& target);
		bool erase_one(const value_type& target);
		void insert(const value_type& entry);
		void operator +=(const student& addend);
		void operator =(const student& source);
		bool operator!=(const student& source);
		bool operator==(const student& source);
		void setName(string f, string l);
		void setGPA(double g);
		// CONSTANT MEMBER FUNCTIONS
		size_type size() const { return many_nodes; }
		size_type count(const value_type& target) const;
		string capitalizeF(string f);
		string capitalizeL(string L);
		void printFile(ofstream& fout);
		void print();
		string getFirst() const;
		string getLast() const;
		void calcGPA();
	private:
		string first;
		string last;
		double gpa;
		node *head_ptr;       // List head pointer 
		size_type many_nodes; // Number of nodes on the list
	};
	// NONMEMBER FUNCTIONS for the bag class:    
	student operator +(const student& b1, const student& b2);
}
#endif

