#ifndef ENCAVE_STL_LINKED_LIST
#define ENCAVE_STL_LINKED_LIST

namespace enclave_stl
{
	class linked_list
	{
	public:
		typedef struct node
		{
			void* data;
			struct node* next;
		} node;

	private:
		node* head;
	};
}



#endif // !ENCAVE_STL_LINKED_LIST
