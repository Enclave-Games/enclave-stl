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
		list();
		list(unsigned long initial_capacity);
		list(list&& rhs_list);
		size_t size();
		bool empty();
		void add(const Type& _element, size_t new_index);
		void push_front(const Type& _element);
		void push_front(Type&& _element);
		void push_back(const Type& _element);
		void push_back(Type&& _element);
		void pop_back();
		void unique();
		void clear() noexcept;
		void merge(const list& other);
		~list() noexcept;

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;

	public:
		class iterator
		{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference_type;
			typedef iterator self_type;
			reference_type operator*() {return *pointer};
			iterator(pointer ptr) : _pointer_type(ptr) { }
			bool operator==(const self_type rhs) {return _pointer_type == rhs._pointer_type};
			bool operator!=(const self_type rhs) {return _pointer_type != rhs._pointer_type};
			pointer operator->() { return _pointer_type; }

		private:
			pointer _pointer_type;
		};



		class const_iterator
		{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference_type;
			typedef iterator self_type;

			const_iterator(pointer ptr) : _pointer_type(ptr) { }
			bool operator==(const self_type rhs) { return _pointer_type == rhs._pointer_type };
			bool operator!=(const self_type rhs) { return _pointer_type != rhs._pointer_type };
			const pointer operator->() { return _pointer_type; }
			const reference_type operator*() { return *pointer };
		private:
			pointer _pointer_type;
		};

		
		Type& operator[](const size_t index);
		void& operator=(const list<Type>& list);
	private:
		size_t _size = 0;
		unsigned long initial_capacity = 0;
		bool _with_initial_capacity = false;
		Type* elements;
	};
}


#endif