#ifndef H_BINARY
#define H_BINARY

#include "node.h"

class binary : public node
{
public:
	binary();
	~binary();

	void insert(string key);
	node *searchT(string key);
	void destroy_tree();

private:
	void destroy_tree(node *leaf);
	void insert(string key, node *leaf);
	node *searchT(string key, node *leaf);

	node *root;
};
#endif
