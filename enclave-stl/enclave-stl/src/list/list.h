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
		auto& list<Type>::operator+(const list<Type>& index);
	private:
		size_t  _size = 0;
		unsigned long initial_capacity = 0;
		bool _with_initial_capacity = false;
		Type* elements;
	};
}


#endif