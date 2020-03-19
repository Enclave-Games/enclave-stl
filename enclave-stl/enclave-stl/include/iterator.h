#ifndef ENCLAVE_STL_ITERATOR
#define ENCLAVE_STL_ITERATOR

namespace estl
{
	template <typename Category, typename T, typename Distance,
		typename Pointer = T *, typename Reference = T &>

	struct iterator
	{
		typedef Category  iterator_category;
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
	};

	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
	};
}

#endif

