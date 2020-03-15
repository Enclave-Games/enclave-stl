#ifndef ENCLAVE_STL_ASSOCIATIVE_ITERATOR
#define ENCLAVE_STL_ASSOCIATIVE_ITERATOR

#include <iterator>

template<
	class Type,
	class IteratorTag = std::bidirectional_iterator_tag>
	class associative_iterator
	{
	public:
		typedef Type value_type;
		typedef Type* pointer;
		typedef std::size_t size_type;
		typedef associative_iterator self_type;
		typedef IteratorTag iterator_type;
		

	private:
		pointer _pointer_type;
};


#endif