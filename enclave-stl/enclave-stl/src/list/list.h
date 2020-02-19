#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

#include <stdexcept>
#include "sequance_iterator.h"
#include <iostream>

namespace enclave_stl
{
	template<
		typename Type>
	class list : public sequance_iterator<Type>
	{
	public:
		list() = default;
		list(uint32_t initial_capacity);
		list(const std::initializer_list<Type> &init_list);
		size_t size() const;
		bool empty();
		void add(const Type& _element, size_t new_index);
		void push_front(const Type& _element);
		void push_back(const Type& _element);
		void pop_back();
		void clear() noexcept;
		void merge(list& other);
		~list();


		// TODO IT!!!
		//list(list&& rhs_list);
		//void push_back(Type&& _element);
		//void push_front(Type&& _element);


		using iterator = sequance_iterator<Type>;
		using const_iterator = const sequance_iterator<Type>;   //poorly designed, do not use it!!!

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

		Type& operator[](const size_t index);
		void operator=(const list<Type>& list);

	private:
		size_t _size = 0;
		uint32_t initial_capacity = 0;
		bool _with_initial_capacity = false;
		Type* elements;
	};
}


#endif