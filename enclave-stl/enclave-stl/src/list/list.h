#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

namespace enclave_stl
{
	template<typename Type>
	class list
	{
	public:
		list();

		bool exist(const int index);

		bool exist(Type* element);

		int is_empty();

		void add(int index, Type* element);

		void add(Type element);

		void remove(int index);

		void remove(Type* element);

		virtual ~list();

	private:
		int _size = 10;
		Type _data[];
	};
}


#endif