#include "list.h"
#include <vector>

namespace enclave_stl
{
	template <typename Type>
	list<Type>::list()
	{
		_size = 10;
		_data = new Type[_size];
	}

	template <typename Type>
	bool list<Type>::exist(Type* element)
	{
		return _data[_size] == element;
	}

	template <typename Type>
	void list<Type>::add(const Type& element)
	{
		_data[_size++] = element;
	}

	template <typename Type>
	size_t list<Type>::size()
	{
		return this->_size;
	}
}
