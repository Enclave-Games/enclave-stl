#include "list.h"
#include <vector>

namespace enclave_stl
{
	// initialize list with dynamic size
	template <typename Type>
	list<Type>::list()
	{
		elements = new Type[_size];
	}

	// initialize list with initial capacity
	template <typename Type>
	list<Type>::list(unsigned long initial_capacity)
	{
		this->initial_capacity = initial_capacity;
		this->_with_initial_capacity = true;
		elements = new Type[initial_capacity];
	}


	// added element to list
	template <typename Type>
	void list<Type>::add(const Type& _element) // TODO: upgrade it
	{
		if (_with_initial_capacity)
		{
			elements[initial_capacity] = _element;
		}
		else
		{
			elements[_size++] = _element;
		}
	}

	template <typename Type>
	void list<Type>::push_front(const Type& _element)
	{
		// TODO
	}

	template <typename Type>
	void list<Type>::push_back(const Type& _element)
	{
		// TODO
	}

	template <typename Type>
	void list<Type>::merge(list& other)
	{
		// TODO
	}

	template <typename Type>
	size_t list<Type>::size()
	{
		return this->_size;
	}

	template <typename Type>
	bool list<Type>::empty()
	{
		return this->_size == 0;
	}


	template <typename Type>
	Type& list<Type>::operator[](const size_t index)
	{
		return elements[index];
	}

	template <typename Type>
	void list<Type>::operator+(const list<Type>& list)
	{
		return 1 + 1; // test
	}

	template <typename Type>
	bool& operator<(list<Type>& other1, list<Type>& other2)
	{
		return other1.size() < other2.size();
	}

	template <typename Type>
	bool operator==(list<Type>& other1, list<Type>& other2)
	{
		return other1.size() == other2.size();
	}
}
