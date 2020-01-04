#ifndef ENCAVE_STL_LINKED_LIST
#define ENCAVE_STL_LINKED_LIST

#include <iostream>

namespace enclave_stl
{
	template <typename T>
	class linked_list
	{
	public:
		linked_list();
		void push(T value);

		void pop();
		void remove(const T& value);
		
		void print();

		void clear() noexcept;
		bool is_empty();
		size_t length();

	private:
		typedef struct node
		{
			T data;
			node* next;
		};

		node* head;
		size_t size;
	};
}



#endif // !ENCAVE_STL_LINKED_LIST
