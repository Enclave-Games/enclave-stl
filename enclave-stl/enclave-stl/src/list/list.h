#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

namespace enclave_stl
{
	template<typename Type>
	class list
	{
	public:
		list();

		bool exist(const int index) noexcept;

		bool exist(Type* element) noexcept;

		int is_empty();

		void add(int index, const Type* element);

		void push_back(const Type& value);

		void add(const Type& element);

		void remove(int index);

		void remove(Type* element);

		size_t size();

		bool& operator<=(const list& other);

		bool& operator>=(const list& other);

		list& operator=(const list& other);

		bool& operator==(const list& other);

		bool& operator<(const list& other);

		bool& operator>(const list& other);

		void clear() noexcept;

		virtual ~list();

	private:
		int _size = 10;
		Type _data;
	};
}


#endif