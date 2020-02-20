#ifndef ENCLAVE_STL_SEQUANCE_ITERATOR
#define ENCLAVE_STL_SEQUANCE_ITERATOR

#include <iterator>

namespace estl
{
	template<
		typename Type,
		typename IteratorTag = std::random_access_iterator_tag>
	class sequance_iterator
	{
	public:
		typedef Type value_type;
		typedef Type* pointer;
		typedef Type& reference_type;
		typedef sequance_iterator self_type;
		typedef IteratorTag iterator_type;
		value_type operator*() { return *_pointer_type; }
		sequance_iterator(pointer ptr) : _pointer_type(ptr) { }
		sequance_iterator() = default;
		self_type operator++() { self_type i = *this; _pointer_type++; return i; }
		self_type operator++(int junk) { ++_pointer_type; return *this; }
		bool operator==(const self_type& rhs) { return _pointer_type == rhs._pointer_type; }
		bool operator!=(const self_type& rhs) { return _pointer_type != rhs._pointer_type; }
		value_type* operator->() { return _pointer_type; }

	private:
		pointer _pointer_type;
	};

	template<
		typename Type,
		typename IteratorTag = std::random_access_iterator_tag>
	class const_sequance_iterator
	{
	public:
		typedef Type value_type;
		typedef Type* pointer;
		typedef Type& reference_type;
		typedef const_sequance_iterator self_type;
		typedef IteratorTag iterator_type;
		value_type operator*() { return *_pointer_type; }
		const_sequance_iterator(pointer ptr) : _pointer_type(ptr) { }
		const_sequance_iterator() = default;
		self_type operator++() { self_type i = *this; _pointer_type++; return i; }
		self_type operator++(int junk) { ++_pointer_type; return *this; }
		bool operator==(const self_type& rhs) { return _pointer_type == rhs._pointer_type; }
		bool operator!=(const self_type& rhs) { return _pointer_type != rhs._pointer_type; }
		value_type* operator->() { return _pointer_type; }

	private:
		pointer _pointer_type;
	};
}

template <class T>
using sequance_iterator = estl::sequance_iterator<T, std::random_access_iterator_tag>;

template <class T>
using const_sequance_iterator = estl::const_sequance_iterator<T, std::random_access_iterator_tag>;

#endif