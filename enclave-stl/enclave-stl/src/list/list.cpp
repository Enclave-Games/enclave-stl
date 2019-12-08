#include "list.h"
#include <vector>

namespace enclave_stl
{
	template <typename Type>
	list<Type>::list()
	{
		_size = 0;
		elements = new Type[_size];
	}

	template <typename Type>
	void list<Type>::add(const Type& _element) // test implementation
	{
		//elements[_size++] = _element;
		_size++;
	}

	template <typename Type>
	unsigned int list<Type>::size()
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
