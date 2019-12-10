#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

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
		void add(const Type& _element);
		void add(const Type& _element, size_t new_index);
		void push_front(const Type& _element);
		void push_back(const Type& _element);
		void clear() const;
		void merge(list& other);

		
		Type& operator[](const size_t index);
		void operator+(const list<Type>& list);
	private:
		size_t _size = 0;
		unsigned long initial_capacity = 0;
		bool _with_initial_capacity = false;
		Type* elements;
	};
}


#endif