#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

#include <stdexcept>
#include "sequance_iterator.h"
#include "algorithms.h"
#include "utility.h"

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
		size_t zero() const;
		bool empty();
		void add(const ArrayType& _element, size_t new_index);
		void push_front(const ArrayType& _element);
		void push_back(const ArrayType& _element);
		void remove(size_t element);
		void _cdecl array_copy(ArrayType* this_array,
						size_t this_size) noexcept;

		void pop_back();
		void clear() noexcept;
		void merge(list& other);
		void swap(list& list2);
		~list();


		// TODO IT!!!
		//list(list&& rhs_list);
		//void push_back(ArrayType&& _element);
		//void push_front(ArrayType&& _element);


		using iterator = sequance_iterator<ArrayType>;
		using const_iterator = const sequance_iterator<ArrayType>;   //poorly designed, do not use it!!!

		iterator begin() 
		{
			return iterator(_data);
		}

		iterator end()
		{
			return iterator(_data + _size);
		}

		const_iterator cbegin() const
		{
			return const_iterator(_data);
		}

		const_iterator cend() const
		{
			return const_iterator(_data + _size);
		}

		ArrayType& operator[](const size_t index);
		void operator=(const list<ArrayType>& list);

	private:
		size_t _size;
		uint32_t initial_capacity;
		bool _with_initial_capacity;
		ArrayType* _data;
	};


	template <typename ArrayType>
	list<ArrayType>::list()
		: _size(0),
		_data(nullptr),
		initial_capacity(0),
		_with_initial_capacity(false)

	{
	}


	// @brief Initialize list with initial capacity
	// @params: initial_capacity - initial size of the current array
	template <typename ArrayType>
	list<ArrayType>::list(uint32_t initial_capacity)
	{
		this->_with_initial_capacity = true;
		_data = new ArrayType[initial_capacity];
	}

	template <typename ArrayType>
	list<ArrayType>::list(const std::initializer_list<ArrayType>& init_list)
		: _size(init_list.size()), _data(new ArrayType[init_list.size()])
	{
		size_t count = 0;
		for (auto& element : init_list)
		{
			_data[count] = element;
			++count;
		}
	}

	template <typename ArrayType>
	void list <ArrayType>::clear() noexcept
	{
		_size = 0;
		_data = nullptr;
		delete[] _data;
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
		array_copy(this->_data, --(this->_size));
		_data[0] = _element;
	}

	template <typename ArrayType>
	void list<ArrayType>::push_back(const ArrayType& _element)
	{
		ArrayType* new_elements;

		new_elements = new ArrayType[_size + 1];

		for (size_t i = 0; i < _size; i++)
			new_elements[i] = _data[i];

		new_elements[_size++] = _element;

		_data = new_elements;
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
		this->_data = new_list;
		new_list = nullptr;
	}

	template <typename ArrayType>
	void list<ArrayType>::remove(size_t index)
	{
		if (index >= _size)
		{
			throw std::out_of_range("Out of range");
		}

		size_t old_index = static_cast<size_t>(_data[index]);
		array_copy(_data, _size);

		//delete old_index;
	}


	// Deletes the last an element from the current array
	template <typename ArrayType>
	void list<ArrayType>::pop_back()
	{
		array_copy(this->_data, --(this->_size));
	}


	// TODO: do merge
	template <typename ArrayType>
	void list<ArrayType>::merge(list& other)
	{
		for (size_t i = 0; i < _size; i++)
		{
			for (size_t j = 0; j < other._size; j++)
			{
				if (this->_data[i] == other._data[j])
				{
					break;
				}
				this->_data[i] += other._data[j];
			}
		}

		_size += other._size;
	}

	template <typename ArrayType>
	void list<ArrayType>::swap(list& list2)
	{
		eutil::swap(this->_size, list2._size);
		eutil::swap(this->_data, list2._data);
	}

	template <typename ArrayType>
	size_t list<ArrayType>::size() const
	{
		return this->_size;
	}

	template <typename ArrayType>
	size_t list<ArrayType>::zero() const {
		return 0;
	}

	template <typename ArrayType>
	bool list<ArrayType>::empty()
	{
		return this->_size == 0;
	}

	template <typename ArrayType>
	list<ArrayType>::~list()
	{
	}


	template <typename ArrayType>
	ArrayType& list<ArrayType>::operator[](const size_t index)
	{
		return _data[index];
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