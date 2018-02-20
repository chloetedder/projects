#include "BST.h"

#define _SCL_SECURE_NO_WARNINGS
#include "BST.h"
#include <iostream>
#include <queue>

using namespace std;

searchT::searchT()
{
	root = nullptr;
}

void searchT::insert(node *x)
{
	root = x;
	current = x;
}

void searchT::insert(string key_value, node *leaf)
{
	if (key_value < leaf->key_value)
	{
		if (leaf->left != nullptr)
			searchT::insert(key_value, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key_value;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
			leaf->left->parent = leaf;
			leaf->count++;
			current = leaf->left;
		}
	}
	else if (key_value > leaf->key_value)
	{
		if (leaf->right != nullptr)
			insert(key_value, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key_value;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
			leaf->right->parent = leaf;
			leaf->count++;
			current = leaf->right;
		}
	}

	else if (key_value == leaf->key_value)
	{
		leaf->count++;
	}
}

node* searchT::search(string key_value, node *leaf)
{
	if (leaf != nullptr)
	{
		if (key_value == leaf->key_value)
		{
			leaf->count++;
			return leaf;
		}
		if (key_value < leaf->key_value)
			return search(key_value, leaf->left);
		else
			return search(key_value, leaf->right);
	}
	else return nullptr;
}

void searchT::insert(string key_value)
{
	if (root != nullptr)
		insert(key_value, root);
	else
	{
		root = new node;
		root->key_value = key_value;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
		current = root;
	}
}

node* searchT::search(string key_value)
{
	return search(key_value, root);
}

searchT::~searchT()
{
}

node* searchT::min(node *here)
{
	while (here->left != NULL) {
		here = here->left;
	}
	return here;
}

node* searchT::min()
{
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

node* searchT::successor(node *x)
{
	/*cout << "here" << endl;
	node *temp = x->parent;
	if (temp != NULL && x == temp->left)
	{
		cout << "left" << endl;
		return temp;
	}
	if (x->right != NULL)
	{
		cout << "ran" << endl;
		return min(x->right);
	}

	while (temp != NULL && x == temp->right)
	{
		cout << "right" << endl;
		x = temp;
		temp = temp->parent;
	}
	current = temp;
	return temp;*/

	if (x->right != NULL)
	{
		current = min(x->right);
		return current;
	}
	else
	{
		while (x == x->parent->right)
		{
			x = x->parent;
		}
		if (x = x->parent->left)
		{
			current = x->parent;
		}
		return current;

	}
}

node* searchT::operator++()
{
	return successor(current);
}

void searchT::levelOrder(node *root)
{
	int levels;
	queue<node*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		levels = Q.size();
		while (levels > 0)
		{
			node *temp = (node*)Q.front();
			Q.pop();
			cout << " " << temp->key_value;
			if (temp->left != NULL)
				Q.push(temp->left);
			if (temp->right != NULL)
				Q.push(temp->right);
			levels--;
		}
		cout << endl;
	}
}

void searchT::printLevel()
{
	levelOrder(root);
}
