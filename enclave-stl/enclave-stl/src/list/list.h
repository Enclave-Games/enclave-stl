#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

#include <stdexcept>

class iterator;
class const_iterator;

namespace enclave_stl
{
	template<typename Type>
	class list
	{
	public:
		list() = default;
		list(unsigned long initial_capacity);
		size_t size() const;
		bool empty();
		void add(const Type& _element, size_t new_index);
		void push_front(const Type& _element);
		void push_back(const Type& _element);
		void pop_back();
		void clear() noexcept;
		void merge(const list& other);
		~list();


		// TODO IT!!!
		//list(list&& rhs_list);
		//void push_back(Type&& _element);
		//void push_front(Type&& _element);



		class iterator
		{
		public:
			typedef Type value_type;
			typedef Type* pointer;
			typedef Type& reference_type;
			typedef iterator self_type;
			value_type operator*() { return *_pointer_type; }
			iterator(pointer ptr) : _pointer_type(ptr) { }
			iterator() = default;
			self_type operator++() { self_type i = *this; _pointer_type++; return i; }
			self_type operator++(int junk) { _pointer_type++; return *this; }
			bool operator==(const self_type& rhs) { return _pointer_type == rhs._pointer_type; }
			bool operator!=(const self_type& rhs) { return _pointer_type != rhs._pointer_type; }
			pointer operator->() { return _pointer_type; }

		private:
			pointer _pointer_type;
		};



		class const_iterator
		{
		public:
			typedef Type value_type;
			typedef Type* pointer;
			typedef Type& reference_type;
			typedef iterator self_type;

			const_iterator(pointer ptr) : _pointer_type(ptr) { }
			bool operator==(const self_type rhs) { return _pointer_type == rhs._pointer_type; }
			bool operator!=(const self_type rhs) { return _pointer_type != rhs._pointer_type; }
			const pointer operator->() { return _pointer_type; }
			const reference_type operator*() { return *pointer; }
		private:
			pointer _pointer_type;
		};

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
		unsigned long initial_capacity = 0;
		bool _with_initial_capacity = false;
		Type* elements;
	};
}


#endif