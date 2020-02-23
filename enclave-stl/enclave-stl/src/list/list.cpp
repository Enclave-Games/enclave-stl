#include "list.h"

namespace estl
{
	template <typename ArrayType>
	list<ArrayType>::list()
		: _size(0),
		elements(nullptr),
		initial_capacity(0),
		_with_initial_capacity(false)

	{
	}

	// initialize list with initial capacity
	template <typename ArrayType>
	list<ArrayType>::list(uint32_t initial_capacity)
	{
		this->_with_initial_capacity = true;
		elements = new ArrayType[initial_capacity];
	}

	template <typename ArrayType>
	list<ArrayType>::list(const std::initializer_list<ArrayType>& init_list)
		: _size(init_list.size()), elements(new ArrayType[init_list.size()])
	{
		size_t count = 0;
		for (auto& element : init_list)
		{
			elements[count] = element;
			++count;
		}
	}

	template <typename ArrayType>
	void list <ArrayType>::clear() noexcept
	{
		_size = 0;
		elements = nullptr;
		delete[] elements;
	}

	template <typename ArrayType>
	void list<ArrayType>::add(const ArrayType& _element, size_t new_index)
	{
		// TODO
	}

	template <typename ArrayType>
	void list<ArrayType>::push_front(const ArrayType& _element)
	{
		ArrayType* new_list = new ArrayType[_size + 1];
		for (size_t i = 0; i < _size; i++)
		{
			new_list[i] = elements[i];
		}
		elements[0] = _element;
		elements = new_list;
		new_list = nullptr;
	}

	template <typename ArrayType>
	void list<ArrayType>::push_back(const ArrayType& _element)
	{
		ArrayType* new_elements = nullptr;
		if (_with_initial_capacity)
		{
			new_elements = new ArrayType[initial_capacity + 1];

			for (size_t i = 0; i < initial_capacity; i++)
				new_elements[i] = elements[i];

			delete[] elements;
			new_elements[initial_capacity++] = _element;
		}
		else
		{
			new_elements = new ArrayType[_size + 1];

			for (size_t i = 0; i < _size; i++)
				new_elements[i] = elements[i];

			delete[] elements;
			new_elements[_size++] = _element;

		}
		elements = new_elements;
		new_elements = nullptr;
	}

	template <typename ArrayType>
	void list<ArrayType>::array_copy(ArrayType* this_array, 
									 ArrayType* new_elements, 
									 size_t size)
	{

	}

	template <typename ArrayType>
	void list<ArrayType>::remove(size_t index)
	{
		if (index >= _size)
		{
			throw std::out_of_range("Out of range");
		}

		size_t old_index = static_cast<size_t>(elements[index]);
		array_copy(elements, _size);

		//delete old_index;
	}
	

	template <typename ArrayType>
	void list<ArrayType>::pop_back()
	{
		--this->_size;
		ArrayType* new_elements = new ArrayType[_size];

		for (size_t i = 0; i < _size; i++)
			new_elements[i] = elements[i];

		delete[] elements;
		elements = new_elements;
		new_elements = nullptr;
	}


	// TODO: do merge
	template <typename ArrayType>
	void list<ArrayType>::merge(list& other)
	{
		for (size_t i = 0; i < _size; i++)
		{
			for (size_t j = 0; j < other._size; j++)
			{
				if (this->elements[i] == other.elements[j])
				{
					break;
				}
				this->elements[i] += other.elements[j];
			}
		}

		_size += other._size;
	}

	template <typename ArrayType>
	size_t list<ArrayType>::size() const
	{
		return this->_size;
	}

	template <typename ArrayType>
	bool list<ArrayType>::empty()
	{
		return this->_size == 0;
	}

	template <typename ArrayType>
	list<ArrayType>::~list()
	{
		delete[] elements;
	}


	template <typename ArrayType>
	ArrayType& list<ArrayType>::operator[](const size_t index)
	{
		return elements[index];
	}

	template <typename ArrayType>
	bool& operator<(list<ArrayType>& other1, list<ArrayType>& other2)
	{
		return other1.size() < other2.size();
	}

	template <typename ArrayType>
	bool operator==(list<ArrayType>& other1, list<ArrayType>& other2)
	{
		return other1.size() == other2.size();
	}
}
