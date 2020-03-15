#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

#include <stdexcept>
#include "sequance_iterator.h"
#include <iostream>

namespace estl
{
	template<
		typename ArrayType>
	class list : public sequance_iterator<ArrayType>
	{
	public:
		list();
		explicit list(uint32_t initial_capacity);
		list(const std::initializer_list<ArrayType> &init_list);
		size_t size() const;
		bool empty();
		void add(const ArrayType& _element, size_t new_index);
		void push_front(const ArrayType& _element);
		void push_back(const ArrayType& _element);
		void remove(size_t element);
		void _cdecl array_copy(ArrayType* this_array,
						size_t this_size) noexcept;

		template<typename ... Args>
		ArrayType& construct_now(Args&& ... args);

		void pop_back();
		void clear() noexcept;
		void merge(list& other);
		~list();


		// TODO IT!!!
		//list(list&& rhs_list);
		//void push_back(ArrayType&& _element);
		//void push_front(ArrayType&& _element);


		using iterator = sequance_iterator<ArrayType>;
		using const_iterator = const sequance_iterator<ArrayType>;   //poorly designed, do not use it!!!

		iterator begin() 
		{
			return iterator(elements);
		}

		iterator end()
		{
			return iterator(elements + _size);
		}

		const_iterator cbegin() const
		{
			return const_iterator(elements);
		}

		const_iterator cend() const
		{
			return const_iterator(elements + _size);
		}

		ArrayType& operator[](const size_t index);
		void operator=(const list<ArrayType>& list);

	private:
		size_t _size;
		uint32_t initial_capacity;
		bool _with_initial_capacity;
		ArrayType* elements;
	};


	template <typename ArrayType>
	list<ArrayType>::list()
		: _size(0),
		elements(nullptr),
		initial_capacity(0),
		_with_initial_capacity(false)

	{
	}


	// Initialize list with initial capacity
	// Parameter: initial_capacity - initial size of the current array
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

	//template <typename ArrayType>
	//template<typename ... Args>
	//ArrayType& list<ArrayType>::construct_now(Args&& ... args)
	//{
	//	ArrayType* new_elements;

	//	new_elements = new ArrayType[_size + 1];

	//	for (size_t i = 0; i < _size; i++)
	//		new_elements[i] = elements[i];

	//	delete[] elements;

	//	//auto element = new (new_elements + _size) (std::forward<Args>(...));

	//	elements = new_elements;
	//	new_elements = nullptr;

	//	//return *element;
	//}

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


	// Inserts an element at the beginning of the current array
	// Parameter: _element - some element
	template <typename ArrayType>
	void list<ArrayType>::push_front(const ArrayType& _element)
	{
		array_copy(this->elements, --(this->_size));
		elements[0] = _element;
	}

	template <typename ArrayType>
	void list<ArrayType>::push_back(const ArrayType& _element)
	{
		ArrayType* new_elements;

		new_elements = new ArrayType[_size + 1];

		for (size_t i = 0; i < _size; i++)
			new_elements[i] = elements[i];

		delete[] elements;
		new_elements[_size++] = _element;

		elements = new_elements;
		new_elements = nullptr;
	}

	template <typename ArrayType>
	void list<ArrayType>::array_copy(ArrayType* this_array,
		size_t size) noexcept
	{
		ArrayType* new_list = new ArrayType[size];
		for (size_t i = 0; i < size; i++)
		{
			new_list[i] = this_array[i];
		}
		this->elements = new_list;
		new_list = nullptr;
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


	// Deletes the last an element from the current array
	template <typename ArrayType>
	void list<ArrayType>::pop_back()
	{
		array_copy(this->elements, --(this->_size));
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

#endif