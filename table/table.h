#include <cstdlib>
#include <cassert>
#include "node2.h"

namespace main_savitch_12B
{
	template <class RecordType>
	class table
	{
	public:
		static const std::size_t TABLE_SIZE = 811;
		table();
		table(const table& source);
		~table();
		void insert(const RecordType& entry);
		void remove(int key);
		void operator =(const table& source);
		void find(int key, bool& found, RecordType& result) const;
		bool is_present(int key) const;
		std::size_t size() const { return total_records; }
		
	private:
		node::nodeT<RecordType> *data[TABLE_SIZE];
		std::size_t total_records;
		std::size_t hash(int key) const;
	};

	

	template <class RecordType>
	table<RecordType>::table()
	{
		for (size_t x = 0; x < TABLE_SIZE; x++)
		{
			data[x] = NULL;
		}
		total_records = 0;
	}

	template <class RecordType>
	table<RecordType>::table(const table& source)
	{
		for (size_t x = 0; x < TABLE_SIZE; x++)
		{
			node::nodeT<RecordType> *head = source.data[x];
			node::nodeT<RecordType> *tail;
			list_copy(head, data[x], tail);
		}
		total_records = source.total_records;
	}

	template <class RecordType>
	table<RecordType>::~table()
	{
		for (size_t x = 0; x < total_records; x++)
		{
			//node::nodeT<RecordType> *entry = (*data)[x];
			if (data[x] != NULL)
			{
				//node::nodeT<RecordType> *next = entry->link();
				//delete entry;
				//entry = next;
				list_clear(data[x]);
			}
			
		}
	}

	template <class RecordType>
	std::size_t table<RecordType>::hash(int key) const
	{
		return key % 100;
	}

	template <class RecordType>
	void table<RecordType>::insert(const RecordType& entry)
	{

		//assert(entry.key >= 0);
		
		int value = hash(entry.key);
		node::nodeT<RecordType>* prev = NULL;
		node::nodeT<RecordType>* temp = data[value];
		
		if (temp == NULL)
		{
			temp = new node::nodeT<RecordType>(entry);
			data[value] = temp;
			total_records++;
			
		}
		else
		{
			while (temp != NULL)
			{
				prev = temp;
				temp = temp->link();
			}
			temp = new node::nodeT<RecordType>(entry);
			prev->set_link(temp);
		}
	}
	
	template <class RecordType>
	void table<RecordType>::remove(int key)
	{
		//assert(key >= 0);


		int index = hash(key);
		
		if (!(data[index] == NULL))
		{
			node::nodeT<RecordType>* temp = data[index];
			list_clear(temp);
			total_records--;
			if (temp == NULL)
			{
				return;
			}
			
		}
		
	}

	template <class RecordType>
	void table<RecordType>::find(int key, bool& found, RecordType& result) const
	{
		size_t index = hash(key);
		if (data[index] == NULL)
		{
			found = false;
			//result = NULL;
		}
		else
		{
			found = true;
			node::nodeT<RecordType> *temp = data[index];
			//result
		}
	}

	template <class RecordType>
	bool table<RecordType>::is_present(int key) const
	{
		size_t index = hash(key);
		if (data[index] == NULL)
			return false;
		else
			return true;
	}

	template <class RecordType>
	void table<RecordType>::operator =(const table& source)
	{
		nodeT<RecordType> *tail;

		if (this == &source)
			return;
		for (size_t x; x < TABLE_SIZE; x++)
		{
			node::nodeT<RecordType> *sHead = source.data[x];
			list_clear(data[x]);
			many_nodes = 0;
			list_copy(sHead, data[x], tail);
			many_nodes = source.many_nodes;
		}
		
		total_records = source.total_records;
	}
}

