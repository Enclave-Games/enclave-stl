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
		size_t size();
		bool empty();
		void add(const Type& _element, size_t new_index);
		void push_front(const Type& _element);
		void push_back(const Type& _element);
		void pop_back();
		void unique();
		void clear() noexcept;
		void merge(list& other);

	public:
		class iterator
		{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference_type;
			typedef iterator self_type;

		private:
			pointer _pointer_type;
		};



		class const_iterator
		{

		};

		
		Type& operator[](const size_t index);
		Type& operator=(const list<Type>& list);
	private:
		size_t _size = 0;
		unsigned long initial_capacity = 0;
		bool _with_initial_capacity = false;
		Type* elements;
	};
}


#endif