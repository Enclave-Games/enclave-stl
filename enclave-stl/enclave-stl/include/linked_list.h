#ifndef ENCAVE_STL_LINKED_LIST
#define ENCAVE_STL_LINKED_LIST

#include "base/config.h"
#include "algorithms.h"
#include "iterator.h"

namespace estl
{
	template < class T >
	struct list_node
	{
		T data;
		list_node* next;
	};

	template <class T, class Pointer = T*, class Reference = T& >
	struct linked_list_iterator
	{
		using value_type = T;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using reference = Reference;
		using pointer = Pointer;
		using iterator = linked_list_iterator<T, T*, T&>;
	};


	template < typename T>
	class linked_list
	{
	public:

		typedef linked_list<T>								this_type;

		typedef T											value_type;
		typedef T*											pointer;
		typedef const T*									const_pointer;
		typedef T&											reference;
		typedef const T&									const_reference;
		typedef linked_list_iterator<T, T*, T&>             iterator;
		typedef linked_list_iterator<T, const T*, const T&> const_iterator;
		typedef size_t										size_type;
		typedef ptrdiff_t									difference_type;

		linked_list();
		explicit linked_list(size_type count);
		linked_list(const linked_list& other);
		linked_list(linked_list&& other);

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		iterator begin() ENCLAVE_NOEXC;
		const_iterator begin() const;
		const_iterator cbegin() const ENCLAVE_NOEXC;

		iterator end() ENCLAVE_NOEXC;
		const_iterator end() const;
		const_iterator cend() const ENCLAVE_NOEXC;

		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		void clear();

		iterator insert(iterator pos, const T& value);
		iterator insert(const_iterator pos, const T& value);

		template< class... Args >
		iterator emplace(const_iterator pos, Args&& ... args);

		iterator erase(iterator pos);
		iterator erase(const_iterator pos);

		void push_back(const T& value);

		template< class... Args >
		void emplace_back(Args&& ... args);

		template< class... Args >
		reference emplace_back(Args&& ... args);

		void pop_back();

		void push_front(const T& value);

		template< class... Args >
		void emplace_front(Args&& ... args);

		template< class... Args >
		reference emplace_front(Args&& ... args);

		void pop_front();

		void resize(size_type count, T value = T());
		void resize(size_type count);
		void resize(size_type count, const value_type& value);


		void swap(linked_list& other);
		
		void merge(linked_list& other);

		template <class Compare>
		void merge(linked_list& other, Compare comp);

		void splice(const_iterator pos, linked_list& other);

		void remove(const T& value);

		template< class UnaryPredicate >
		void remove_if(UnaryPredicate p);

		void reverse();

		void unique();

		template< class BinaryPredicate >
		void unique(BinaryPredicate p);

		void sort();

		template< class Compare >
		void sort(Compare comp);

	private:
		list_node* _head;
		list_node* _tail;
	};

	template <typename T>
	linked_list<T>::linked_list()
	{
		
	}

	template <typename T>
	void linked_list<T>::push_back(const T& value)
	{
		list_node* temp_node = new list_node;
		temp_node->data = value;
		temp_node->next = nullptr;

		if (_head == nullptr) {
			_head = temp_node;
			_tail = temp_node;
		}
		else {
			_tail->next = temp_node;
			_tail = _tail->next;
		}
		++size;
	}

	template <typename T>
	void linked_list<T>::remove(const T& value)
	{

	}

	template <typename T>
	void linked_list<T>::clear()
	{

	}


	template <typename T>
	bool operator==(const linked_list<T>& lhs, const linked_list<T>& rhs)
	{

	}

	template <typename T>
	bool operator!=(const linked_list<T>& lhs, const linked_list<T>& rhs)
	{

	}

	template <typename T>
	bool operator<(const linked_list<T>& lhs, const linked_list<T>& rhs)
	{

	}

	template <typename T>
	bool operator<=(const linked_list<T>& lhs, const linked_list<T>& rhs)
	{

	}

	template <typename T>
	bool operator>=(const linked_list<T>& lhs, const linked_list<T>& rhs)
	{

	}

	template <typename T>
	bool operator>(const linked_list<T>& lhs, const linked_list<T>& rhs)
	{

	}
}



#endif
