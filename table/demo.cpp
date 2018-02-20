#include <iostream>
#include "table.h"

using namespace std;
using namespace main_savitch_12B;

int main()
{
	struct tractor
	{
		int key;
		double cost;
		int horsepower;
		tractor() { key = 0; cost = 0; horsepower = 0; }
		tractor(int k, double c, int h) { key = k; cost = c; horsepower = h; }
	};

	table<tractor> deere;

	tractor one(100, 2000,  700);

	tractor two;
	one.key = 100;
	one.cost = 500000;
	one.horsepower = 500;

	tractor three;
	one.key = 101;
	one.cost = 3000;
	one.horsepower = 900;

	tractor four;
	one.key = 102;
	one.cost = 3000;
	one.horsepower = 900;

	deere.insert(one);
	deere.insert(two);
	deere.insert(three);

	deere.remove(101);
	
	table<tractor> ford(deere);
	table<tractor> rain = deere;

	bool found;
	tractor result;
	deere.find(100, found, result);
	cout << deere.is_present(102) << endl;

	system("pause");
	return 0;
}