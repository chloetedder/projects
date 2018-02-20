#pragma once
#include <string>

using namespace std;

class node
{
public:
	node();
	node(string s) { key_value = s; };
	node *left;
	node *right;
	node *parent;
	string key_value;
	int count;
	~node();
};

