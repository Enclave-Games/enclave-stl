#ifndef ENCAVE_STL_LINKED_LIST
#define ENCAVE_STL_LINKED_LIST

#include <iostream>

namespace estl
{
	template <typename T>
	class linked_list
	{
	public:
		typedef struct node
		{
			T data;
			node* next;
		};

		linked_list();
		void push(const T& value);

		void pop();
		void remove(const T& value);
		
		void print();

		void clear() noexcept;
		bool is_empty();
		size_t length();

	private:
		node* head;
		size_t size;
	};
}



#endif // !ENCAVE_STL_LINKED_LIST
