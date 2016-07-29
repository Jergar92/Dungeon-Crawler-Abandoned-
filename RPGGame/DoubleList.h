#include <assert.h>

#ifndef __DOUBLELIST__
#define __DOUBLELIST__

template<class TYPE>
class DoubleList
{
public:
	struct nodeD
	{
		TYPE data;
		nodeD* next = nullptr;
		nodeD* previous = nullptr;
		nodeD(const TYPE &data) : data(data){}
	};
	nodeD* first_node = nullptr;
public:
	DoubleList(){}
	~DoubleList(){}
	bool Empty()const
	{
		return first_node == nullptr;
	}

	unsigned int size()const
	{
		int num_elements = 0;
		nodeD* temp = first_node;
		while (temp != nullptr)
		{
			num_elements++;
			temp = temp->next;
		}
		return num_elements;
	}

	nodeD* end()const
	{
		nodeD* temp = first_node;
		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void push_back(const TYPE &data)
	{
		nodeD* temp = first_node;
		nodeD* new_node = new nodeD(data);
		if (temp == nullptr)
		{
			first_node = new_node;
		}
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			new_node->previous = temp;
			temp->next = new_node;
		}
	}

	void push_front(const TYPE &data)
	{
		nodeD* new_node = new nodeD(data);
		nodeD* temp = first_node;
		first_node = new_node;
		if (temp != nullptr)
		{
			first_node->next = temp;
			temp->previous = new_node;
		}
	}

	bool pop_back()
	{
		if (first_node != nullptr)
		{
			if (first_node->next != nullptr)
			{
				nodeD* copy = first_node;
				nodeD*popback = first_node;
				while (copy->next != nullptr) {
					copy = copy->next;
				}
				while (popback->next != copy){
					popback = popback->next;
				}
				popback->next = nullptr;
				delete copy;
				return true;
			}
			else
			{
				//popfront;
				nodeD* popback = first_node;
				first_node = nullptr;
				delete popback;
				return true;
			}
		}
		else return false;
	}

	bool pop_front()
	{
		if (first_node != nullptr)
		{
			nodeD* del = first_node;
			if (first_node->next != nullptr)
			{
				first_node = first_node->next;
				first_node->previous = nullptr;
			}
			else{ first_node = nullptr; }
			delete del;
			return true;
		}
		return false;
	}
	
	void insert(nodeD* newnode, TYPE Data){
		nodeD* new_node = new nodeD(Data);
		if (first_node != nullptr)
		{
			if (newnode->previous == nullptr)
			{
				new_node->next = newnode;
				newnode->previous = new_node;
				first_node = new_node;
			}
			else
			{
				new_node->previous = newnode->previous;
				newnode->previous->next = new_node;
				newnode->previous = new_node;
				new_node->next = newnode;
			}
		}
		else
		{
			first_node = new_node;
		}
	}

	void erase(nodeD* del)
	{
		if (size() == 1)
		{
			delete del;
			first_node = nullptr;
		}
		else
		{
			nodeD* temp = first_node;
			if (temp != nullptr)
			{
				if (del->previous == nullptr)
				{
					first_node = temp->next;
					first_node->previous = nullptr;

				}
				else if (del->next == nullptr)
				{
					temp = del->previous;
					temp->next = nullptr;
				}
				else
				{
					temp = del->previous;
					temp->next = del->next;
					temp->next->previous = del->previous;
				}
				delete del;
			}
		}
	}

	void clear()
	{
		if (first_node != nullptr)
		{
			nodeD* temp = end();
			if (temp->previous != nullptr)
			{
				nodeD* temp_prev = temp->previous;
				for (; temp_prev->previous != nullptr; temp_prev = temp_prev->previous)
				{
					temp_prev->next = nullptr;
					temp->previous = nullptr;
					delete temp;
					temp = temp_prev;
				}
				temp_prev->next = nullptr;
				delete temp_prev;
			}
			else { delete temp; }
			first_node = nullptr;
		}
	}
};

#endif //__DOUBLELIST__