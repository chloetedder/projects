#define _SCL_SECURE_NO_WARNINGS
#include "college.h"
#include <cassert>  // Provides assert
#include <cstdlib> 

using namespace std;

namespace HW6 {

	college::college(size_type initial_capacity) {
		data = unique_ptr<value_type[]>(new value_type[initial_capacity]);
		//data = make_unique<value_type[]>(initial_capacity);
		capacity = initial_capacity;
		used = 0;
		ifstream fin;
		fin.open("college.txt");
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				Courses c;
				string s;
				getline(fin, s);
				if (s.compare("Student Name:") == 0)
				{
					getline(fin, s);
					int i = s.find(" ");
					string f = s.substr(0, i);
					string l = s.substr(i + 1);
					data[used].setName(f, l);
					used++;
				}
				if (s.compare("GPA:") == 0)
				{
					double g;
					fin >> g;
					data[used - 1].setGPA(g);
				}
				if (s.compare("Course:") == 0)
				{
					getline(fin, s);
					c.setCName(s);
					getline(fin, s);
					int u;
					fin >> u;
					c.setUnit(u);
					getline(fin, s);
					getline(fin, s);
					char g;
					fin >> g;
					c.changeGrade(g);
					data[used - 1].insert(c);
				}
			}
		}
	}

	college::college(const college& source) {
		data = make_unique<value_type[]>(source.capacity);
		capacity = source.capacity;
		used = source.used;
		copy(source.data.get(), source.data.get() + used, data.get());
	}

	void college::reserve(size_type new_capacity)
		// Library facilities used: algorithm
	{
		//unique_ptr<value_type[]> larger_array;

		if (new_capacity == capacity)
			return; // The allocated memory is already the right size.

		if (new_capacity < used)
			new_capacity = used; // Can’t allocate less than we are using.

								 //larger_array = unique_ptr<value_type[]>(new value_type[new_capacity]);
		auto larger_array = make_unique<value_type[]>(new_capacity);
		copy(data.get(), data.get() + used, larger_array.get());
		//delete [ ] data;
		//data = larger_array;
		data = move(larger_array);
		capacity = new_capacity;
	}

	void college::operator =(const college& source) // Library facilities used: algorithm
	{
		//unique_ptr<value_type[]> new_data;

		// Check for possible self-assignment:
		if (this == &source)
			return;

		// If needed, allocate an array with a different size:
		if (capacity != source.capacity)
		{
			auto new_data = unique_ptr<value_type[]>(new value_type[source.capacity]);
			copy(source.data.get(), source.data.get() + source.used, new_data.get());
			//delete [ ] data;
			data = move(new_data);
			used = source.used;
			capacity = source.capacity;
		}
		else
		{
			// Copy the data from the source array:
			used = source.used;
			copy(source.data.get(), source.data.get() + used, data.get());
		}
	}

	void college::addStudent(const value_type& entry)
	{
		if (used == capacity)
			reserve(used + 1);
		data[used] = entry;
		++used;
	}

	bool college::removeStudent(const value_type& target)
	{
		size_type index; // The location of target in the data array    

						 // First, set index to the location of target in the data array,
						 // which could be as small as 0 or as large as used-1.
						 // If target is not in the array, then index will be set equal to used.
		index = 0;
		while ((index < used) && ((data[index].getFirst() != target.getFirst()) || (data[index].getLast() != target.getLast())))
			++index;

		if (index == used) // target isn't in the bag, so no work to do
			return false;

		// When execution reaches here, target is in the bag at data[index].
		// So, reduce used by 1 and copy the last item onto data[index].
		--used;
		data[index] = data[used];
		return true;
	}

	void college::addCourse(const value_type& entry)
	{
		string n;
		int u;
		char g;
		cout << "Enter name of course: " << endl;
		cin.ignore();
		getline(cin, n);
		cout << "Enter number of units: " << endl;
		cin >> u;
		cout << "Enter course grade: " << endl;
		cin >> g;
		Courses c(n, u, g);
		for (size_type a = 0; a < used; a++)
		{
			if ((data[a].getFirst() == entry.getFirst()) && (data[a].getLast() == entry.getLast()))
			{
				data[a].insert(c);
			}
		}
	}
	void college::removeCourse(const value_type& entry)
	{
		string n;
		int u;
		char g;
		cout << "Enter name of course: " << endl;
		cin.ignore();
		getline(cin, n);
		cout << "Enter number of units: " << endl;
		cin >> u;
		cout << "Enter course grade: " << endl;
		cin >> g;
		Courses c(n, u, g);
		for (size_type a = 0; a < used; a++)
		{
			if ((data[a].getFirst() == entry.getFirst()) && (data[a].getLast() == entry.getLast()))
			{
				data[a].erase(c);
			}
		}

	}

	void college::printStudents(bool toFile) const {
		if (toFile) {
			ofstream fout;
			fout.open("college.txt");
			fout << "List of Students:" << endl;
			for (size_type i = 0; i < used; i++) {
				data[i].printFile(fout);
			}
			fout.close();
		}

		cout << "List of Students:" << endl;
		for (size_type i = 0; i < used; i++) {
			data[i].print();
		}
	}
}

