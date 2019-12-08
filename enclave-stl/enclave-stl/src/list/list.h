#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

namespace enclave_stl
{
	template<typename Type>
	class list
	{
	public:
		list();
		unsigned int size();
		bool empty();
		void add(const Type& _element);


		Type& operator[](const size_t index);
	private:
		unsigned int _size;
		Type* elements;
	};
}


#endif