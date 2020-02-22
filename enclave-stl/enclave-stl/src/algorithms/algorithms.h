#ifndef ENCLAVE_STL_ALGORITHMS
#define ENCLAVE_STL_ALGORITHMS

#include <vector>
#include "sequance_iterator.h"

namespace ealg
{
	template <typename RandomAccessIter>
	void sort(RandomAccessIter start, RandomAccessIter end)
	{
		if (start != end)
		{
			for (RandomAccessIter it = start; it != end; it++)
			{

			}
		}
	}

	template <typename ForwardIter>
	ForwardIter max(ForwardIter begin, ForwardIter end)
	{
		if (begin != end)
		{
			ForwardIter currentMax = begin;

			while (++begin != end)
			{
				if (*currentMax < *begin)
				{
					currentMax = begin;
				}
				return currentMax;
			}
		}
		return begin;
	}

	template <typename ForwardIter, typename Compare>
	ForwardIter max(ForwardIter begin, ForwardIter end, Compare compare)
	{
		if (begin != end)
		{
			ForwardIter currentMax = begin;

			while (++begin != end)
			{
				if (compare(*currentMax, *begin))
				{
					currentMax = begin;
				}
				return currentMax;
			}
		}
		return begin;
	}

	void qsort(int* a, int start, int end)
	{
		if (start < end)
		{
			uint16_t pivot = a[end];
			uint16_t P_index = start;
			size_t i, temp;


			for (i = start; i < end; i++)
			{
				if (a[i] <= pivot)
				{
					temp = a[i];
					a[i] = a[P_index];
					a[P_index] = temp;
					P_index++;
				}
			}
			temp = a[end];
			a[end] = a[P_index];
			a[P_index] = temp;

			qsort(a, start, P_index - 1);
			qsort(a, P_index + 1, end);
		}
	}
}

#endif