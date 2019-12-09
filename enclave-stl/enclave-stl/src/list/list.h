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
		size_t  size();
		bool empty();
		void add(const Type& _element);


		Type& operator[](const size_t index);
	private:
		size_t  _size;
		unsigned long initial_capacity;
		bool _with_initial_capacity = false;
		Type* elements;
	};
}


#endif