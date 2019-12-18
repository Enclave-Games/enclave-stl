#include "list.h"

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


	template <typename Type>
	void list<Type>::clear() const
	{
		
	}
	
	template <typename Type>
	void list<Type>::add(const Type& _element, size_t new_index)
	{
		// TODO
	}

	template <typename Type>
	void list<Type>::push_front(const Type& _element)
	{
		Type* new_list = new Type[_size + 1];
		elements[0] = _element;
		for (size_t i = 0; i < _size; i++)
		{
			new_list[i] = elements[i];
		}
		elements = new_list;
		new_list = nullptr;
	}

	template <typename Type>
	void list<Type>::push_back(const Type& _element)
	{
		if (_with_initial_capacity)
		{
			Type* new_elements = new Type[initial_capacity + 1];

			for (int i = 0; i < initial_capacity; i++)
				new_elements[i] = elements[i];

			delete[] elements;
			new_elements[initial_capacity++] = _element;
<<<<<<< HEAD

			elements = new_elements;
			new_elements = nullptr;
=======
			elements = new_elements;
			new_elements = nullptr;

>>>>>>> 18526fd3828b1b6dfde89704dcbae7c65f3457d6
		}
		else
		{
			Type* new_elements = new Type[_size + 1];

			for (int i = 0; i < _size; i++)
				new_elements[i] = elements[i];

			delete[] elements;
			new_elements[_size++] = _element;
			elements = new_elements;
			new_elements = nullptr;
		}
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
