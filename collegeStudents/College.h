#define _SCL_SECURE_NO_WARNINGS
#ifndef COLLEGE_H
#define COLLEGE_H
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include "Student.h"
#include <cstdlib>   // Provides size_t and NULL


namespace HW6 {
	class college {
	public:
		typedef student value_type;
		typedef std::size_t size_type;
		static const size_type DEFAULT_CAPACITY = 30;
		college(size_type initial_capacity = DEFAULT_CAPACITY);
		college(const college& source); //copy constructor 
		void reserve(size_type new_capacity);
		void operator =(const college& source); //copy assignment
		void addStudent(const value_type& entry);
		bool removeStudent(const value_type& target);
		void addCourse(const value_type& entry);
		void removeCourse(const value_type& entry);
		void printStudents(bool toFile) const;
		size_type numStudents() const { return used; }

	private:
		std::unique_ptr<value_type[]> data;     // Pointer to partially filled dynamic array
		size_type used;       // How much of array is being used
		size_type capacity;   // Current capacity of the bag

	};

}
#endif
