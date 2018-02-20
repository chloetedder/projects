#ifndef H_nodeT
#define H_nodeT

#include <cstdlib>
#include <iterator>
#include <cassert>

namespace node
{
	template <class Item>
	class nodeT
	{
	public:
		// TYPEDEF
		typedef Item value_type;
		typedef std::size_t size_type;

		// CONSTRUCTOR
		nodeT(const Item& init_data = Item(), nodeT<Item>* init_link = NULL)
		{
			data_field = init_data; link_field = init_link;
		}

		// Member functions to set the data and link fields:
		void set_data(const Item& new_data) { data_field = new_data; }
		void set_link(nodeT<Item>* new_link) { link_field = new_link; }

		// Constant member function to retrieve the current data:
		Item data() const { return data_field; }

		// Two slightly different member functions to retreive
		// the current link:
		const nodeT<Item>* link() const { return link_field; }
		nodeT<Item>* link() { return link_field; }

	private:
		Item data_field;
		nodeT<Item>* link_field;
	};

	// FUNCTIONS for the linked list toolkit
	template <class Item>
	std::size_t list_length(const nodeT<Item>* head_ptr);
	template <class Item>
	void list_head_insert(nodeT<Item>*& head_ptr, const Item& entry);
	template <class Item>
	void list_insert(nodeT<Item>* previous_ptr, const Item& entry);
	template <class NodePtr, class Item>
	NodePtr list_search(NodePtr head_ptr, const Item& target);
	template <class NodePtr, class SizeType>
	NodePtr list_locate(NodePtr head_ptr, SizeType position);
	template <class Item>
	void list_head_remove(nodeT<Item>*& head_ptr);
	template <class Item>
	void list_remove(nodeT<Item>* previous_ptr);
	template <class Item>
	void list_clear(nodeT<Item>*& head_ptr);
	template <class Item>
	void list_copy(const nodeT<Item>* source_ptr, nodeT<Item>*& head_ptr, nodeT<Item>*& tail_ptr);



	template <class Item>
	class node_iterator
		: public std::iterator<std::forward_iterator_tag, Item>
	{
	public:
		node_iterator(nodeT<Item>* initial = NULL) { current = initial; }
		Item& operator *() const { return current->data(); }
		node_iterator& operator ++()
		{
			current = current->link();
			return *this;
		}
		node_iterator operator ++(int)
		{
			node_iterator original(current);
			current = current->link();
			return original;
		}
		bool operator ==(const node_iterator other) const
		{
			return current == other.current;
		}
		bool operator !=(const node_iterator other) const
		{
			return current != other.current;
		}
	private:
		nodeT<Item>* current;
	};

	template <class Item>
	class const_node_iterator
		:public std::iterator<std::forward_iterator_tag, const Item>
	{
	public:
		const_node_iterator(const nodeT<Item>* initial = NULL)
		{
			current = initial;
		}
		const Item& operator *() const
		{
			return current->data();
		}
		const_node_iterator& operator ++()
		{
			current = current->link();
			return *this;
		}
		const_node_iterator operator++(int)
		{
			const_node_iterator original(current);
			current = current->link();
			return origianl;
		}
		bool operator ==(const const_node_iterator other) const
		{
			return current == other.current;
		}
		bool operator !=(const const_node_iterator other) const
		{
			return current != other.current;
		}
	private:
		const nodeT<Item> current;
	};


	template <class Item>
	void list_clear(nodeT<Item>*& head_ptr)
		// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}

	template <class Item>
	void list_copy(const nodeT<Item>* source_ptr, nodeT<Item>*& head_ptr, nodeT<Item>*& tail_ptr)
		// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data());
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data());
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}

	template <class Item>
	void list_head_insert(nodeT<Item>*& head_ptr, const Item& entry)
	{
		head_ptr = new nodeT<Item>(entry, head_ptr);
	}

	template <class Item>
	void list_head_remove(nodeT<Item>*& head_ptr)
	{
		nodeT<Item> *remove_ptr;
		//nodeT<Item> *temp;
		//temp = head_ptr->link();

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}


	template <class Item>
	void list_insert(nodeT<Item>* previous_ptr, const Item& entry)
	{
		nodeT<Item> *insert_ptr;

		insert_ptr = new nodeT<Item>(entry, previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
	}

	template <class Item>
	size_t list_length(const nodeT<Item>* head_ptr)
		// Library facilities used: cstdlib
	{
		const nodeT<Item> *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			++answer;

		return answer;
	}

	template <class NodePtr, class SizeType>
	NodePtr list_locate(NodePtr head_ptr, SizeType position)
		// Library facilities used: cassert, cstdlib
	{
		NodePtr cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	template <class Item>
	void list_remove(nodeT<Item>* previous_ptr)
	{
		nodeT<Item> *remove_ptr;

		remove_ptr = previous_ptr->link();
		previous_ptr->set_link(remove_ptr->link());
		delete remove_ptr;
	}

	template <class NodePtr, class Item>
	NodePtr list_search(NodePtr head_ptr, const Item& target)
		// Library facilities used: cstdlib
	{
		NodePtr cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}
}


#endif H_nodeT
