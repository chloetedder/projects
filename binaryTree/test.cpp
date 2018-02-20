#define _SCL_SECURE_NO_WARNINGS
#include "btree.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <istream>
#include <array>
#include <string>
#include <stack>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <algorithm>

#include "BST.h"
using namespace std;

string change(string s);
node* sortedArrayToBST(pair<string, int> arr[], int start, int end);

struct Assoc
{
	vector<pair<string, int>> vec;

	//const int& operator[](const string&) const;
	int& operator[](const string&);
};

int main()
{
	Assoc values;
	ifstream in;
	string fileName;
	cout << "please enter filename: ";
	cin >> fileName;
	in.open(fileName);

	string word;

	while (!in.eof())
	{
		for (string word; in >> word;)
			++values[change(word)];
	}


	sort(values.vec.begin(), values.vec.end());
	int size = values.vec.size();


	pair<string, int> *ar = new pair<string, int>[size];
	copy(values.vec.begin(), values.vec.end(), ar);

	/*for (auto x : values.vec)
	{
	cout << x.first << endl;
	}*/
	node *assocRoot = sortedArrayToBST(ar, 0, size - 1);
	//cout << assocRoot->key_value << endl;
	searchT assoc1(assocRoot);

	cout << "Assoc Tree Levels:\n";
	assoc1.printLevel();
	cout << endl << endl;
	string min = ar[0].first;
	string max = ar[size - 1].first;
	node *next = assoc1.min(assocRoot);

	ofstream out;
	out.open("assocTree.txt");
	out << "{" << next->key_value << ", " << next->count << "}\n";
	while (next->key_value.compare(max) != 0)
	{

		next = ++assoc1;
		out << "{" << next->key_value << ", " << next->count << "}\n";
	}
	out.close();



	ifstream in2;
	string fileName2;
	cout << "please enter filename: ";
	cin >> fileName2;
	in2.open(fileName2);

	map<string, int> second;
	for (string word2; in2 >> word2;)
	{
		++second[change(word2)];
	}


	out.open("map.txt");
	for (auto x : second)
	{
		out << "{" << x.first << ", " << x.second << "}" << endl;
	}
	out.close();
	size = second.size();
	pair<string, int> *ar2 = new pair<string, int>[size];
	copy(second.begin(), second.end(), ar2);

	node *mapRoot = sortedArrayToBST(ar, 0, size - 1);
	searchT mapTree(mapRoot);
	cout << "Map Tree Levels:\n";
	mapTree.printLevel();

	out.open("assoc.txt");
	for (auto x : values.vec)
	{
		out << "{" << x.first << ", " << x.second << "}" << endl;
	}
	out.close();


	cout << endl << endl;
	string min1 = ar[0].first;
	string max1 = ar[size - 1].first;
	node *next1 = mapTree.min(mapRoot);

	out.open("mapTree.txt");
	out << "{" << next1->key_value << ", " << next1->count << "}\n";
	while (next1->key_value.compare(max1) != 0)
	{

		next1 = ++mapTree;
		out << "{" << next1->key_value << ", " << next1->count << "}\n";
	}
	out.close();



	system("pause");
	return 0;
}

string change(string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
	return s;
}

bool mySort(string x, string y)
{
	return (x.compare(y));
}

int& Assoc::operator[](const string& s)
{
	for (auto& x : vec)
		if (s == x.first)
			return x.second;
	vec.push_back({ s,0 });
	return vec.back().second;
}

int findMin(int totalN)
{
	int height = floor(log2(totalN));
	int first = pow(2, height);
	int second = (pow(2, height) / 2) + (totalN - (pow(2, height) - 1));
	if (first <= second)
		return first;
	if (second < first)
		return second;
	else
		cout << "error" << endl;
}

node* sortedArrayToBST(pair<string, int> arr[], int start, int end)
{
	//cout << start << end << endl;
	if (start > end)
	{
		//cout << "start>end" << endl;
		return NULL;
	}
	if (start == end)
	{
		node *x = new node(arr[start].first);
		x->count = arr[start].second;
		x->right = NULL;
		x->left = NULL;
		//cout << "start==end" << endl;
		return x;
	}

	if (start < 0)
	{
		//cout << "start<0" << endl;
		return NULL;
	}

	if (end < 0)
	{
		//cout << "end<0" << endl;
		return NULL;
	}
	int total = (end - start) + 1;
	int min = findMin(total) - 1;
	if (start != 0)
	{
		min = min + start;
	}

	pair<string, int> mid = arr[min];
	node *temp = new node(mid.first);
	temp->count = mid.second;
	temp->parent = NULL;

	temp->left = sortedArrayToBST(arr, start, min - 1);
	temp->left->parent = temp;

	temp->right = sortedArrayToBST(arr, min + 1, end);
	if (temp->right != NULL)
		temp->right->parent = temp;

	return temp;
}
