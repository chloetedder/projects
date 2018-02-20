#ifndef H_SEARCHT
#define H_SEARCHT

#define _SCL_SECURE_NO_WARNINGS
#include <string>
#include "btree.h"

using namespace std;

class searchT : public binary
{
public:
	//typedef iteratorTree iterator;
	searchT();
	searchT(node *n) { root = n; };
	~searchT();

	void insert(node *x);
	void insert(string key_value);
	node* search(string key_value);
	node* successor(node *x);
	node* min(node *here);
	node* min();
	node* operator++();
	void levelOrder(node *root);
	void printLevel();
	//could put into an array and then just print out the values associated with that
	//and go through the array to print

private:
	void insert(string key_value, node *leaf);
	node* search(string key_value, node *leaf);

	node *root;
	node *current;
};

#endif

