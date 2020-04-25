#ifndef ENCLAVE_STL_SORT_EXTRA
#define ENCLAVE_STL_SORT_EXTRA

#include "base/config.h"
#include "base/functors.h"
#include "utility.h"


namespace esort
{
	template < class RandomIt >
	std::pair<RandomIt, RandomIt> partition(RandomIt start, RandomIt end)
	{
		auto start_unwrapped = eutil::get_unwrapped(start);
		auto end_unwrapped = eutil::get_unwrapped(end);

		RandomIt middle = start + (end - start);
		RandomIt pfirst = middle;
		RandomIt psecond = pfirst + 1;

		FOREVER_CYCLE
		{

		}
	}

	template< class RandomIt >
	void quick_sort(RandomIt start, RandomIt end)
	{
		esort::quick_sort(start, end, std::less<>());
	}

	template< class RandomIt, class Compare >
	void quick_sort(RandomIt start, RandomIt end, Compare comp)
	{
		if (start < end)
		{
			const auto middle = std::_Partition_by_median_guess_unchecked(start, end, comp);
			quick_sort(start, middle.first, comp);
			quick_sort(middle.second, end, comp);
		}

	}


	template< class RandomIt >
	void stable_sort(RandomIt first, RandomIt last)
	{
		esort::stable_sort(first, last, efun::less<>());
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
		partial_sort(first, last, efun::less<>());
	}

	template< class RandomIt, class Compare >
	void partial_sort(RandomIt first, RandomIt middle, RandomIt last, Compare comp)
	{

	}

	template < class RandomIt >
	void shell_sort(RandomIt first, RandomIt last)
	{
		esort::shell_sort(first, last, efun::less<>());
	}

	template< class RandomIt, class Compare >
	void shell_sort(RandomIt first, RandomIt last, Compare comp)
	{
		
	}
}

#endif
