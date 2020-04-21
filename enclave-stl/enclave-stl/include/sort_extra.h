#ifndef ENCLAVE_STL_SORT_EXTRA
#define ENCLAVE_STL_SORT_EXTRA

#include "base/config.h"
#include "base/functors.h"

namespace esort
{
	template< class RandomIt >
	void stable_sort(RandomIt first, RandomIt last)
	{
		return esort::stable_sort(first, last, efun::less<>());
	}

	template< class RandomIt, class Compare >
	void stable_sort(RandomIt first, RandomIt last, Compare comp)
	{
		if (first != last)
		{
			for (RandomIt start = first; start != last;)
			{

			}
		}
	}

	template< class RandomIt >
	void partial_sort(RandomIt first, RandomIt middle, RandomIt last)
	{
		return partial_sort(first, last, efun::less<>());
	}

	template< class RandomIt, class Compare >
	void partial_sort(RandomIt first, RandomIt middle, RandomIt last, Compare comp)
	{

	}
}

#endif
