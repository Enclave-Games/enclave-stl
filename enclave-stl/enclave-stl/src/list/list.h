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
		void array_copy(ArrayType* this_array,
						ArrayType* new_element,
						size_t this_size) noexcept;

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
}


#endif