#include "linked_list.h"

namespace enclave_stl
{
	template <typename T>
	linked_list<T>::linked_list()
	{
		size = 0;
		head = new node;
	}

	template <typename T>
	void linked_list<T>::push(const T& value)
	{
		node* temp_node = new node;
		temp_node->next = nullptr;
		temp_node->data = value;
		temp_node->next = head->next;
		head->next = temp_node->next;
		++size;
	}

	template <typename T>
	void linked_list<T>::pop()
	{

	}

	template <typename T>
	void linked_list<T>::remove(const T& value)
	{

	}

	template <typename T>
	void linked_list<T>::clear() noexcept
	{

	}

	template <typename T>
	size_t linked_list<T>::length()
	{
		return size;
	}

	template <typename T>
	bool linked_list<T>::is_empty()
	{
		return head->next == NULL;
	}

	template <typename T>
	void linked_list<T>::print()
	{
		while (head != nullptr)
		{
			std::cout << head->data << std::endl;
		}
	}
}