#ifndef ENCLAVE_STL_ALGORITHMS
#define ENCLAVE_STL_ALGORITHMS

#include <vector>
#include <algorithm>
#include "sequance_iterator.h"

namespace ealg
{
	template <typename RandomAccessIter>
	void sort(RandomAccessIter start, RandomAccessIter end)
	{
		if (start != end)
		{
			RandomAccessIter* current_data_array = nullptr;

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

	template<class T>
	const T& max(const T& a, const T& b)
	{
		return (b < a) ? a : b;
	}

	template<class T, class Compare>
	const T& max(const T& a, const T& b, Compare compare)
	{
		return (compare(b < a)) ? a : b;
	}

	template<class T>
	const T& max(const std::initializer_list<T> init_list)
	{
		return *std::max_element(init_list.begin(), init_list.end());
	}

	template<class T, class Compare>
	const T& max(const std::initializer_list<T> init_list, Compare compare)
	{
		return *std::max_element(init_list.begin(), init_list.end(), compare);
	}

	template<class T>
	const T& min(const T& a, const T& b)
	{
		return (b < a) ? b : a;
	}

	template<class T, class Compare>
	const T& min(const T& a, const T& b, Compare compare)
	{
		return (compare(b < a)) ? b : a;
	}

	template<class T>
	const T& min(const std::initializer_list<T> init_list)
	{
		return *std::min_element(init_list.begin(), init_list.end());
	}

	template<class T, class Compare>
	const T& min(const std::initializer_list<T> init_list, Compare compare)
	{
		return *std::min_element(init_list.begin(), init_list.end(), compare);
	}

	template< class ForwardIt >
	std::pair<ForwardIt, ForwardIt>
		minmax_element(ForwardIt first, ForwardIt last)
	{
		return std::minmax_element(first, last);
	}

	template<class ForwardIt, class Compare>
	std::pair<ForwardIt, ForwardIt>
		minmax_element(ForwardIt first, ForwardIt last, Compare comp)
	{
		auto min = first;
		auto max = first;

		if ((first == last) || (++first == last)) 
		{
			return { min, max };
		}

		if (comp(*first, *last))
		{
			min = first;
		}
		else
		{
			max = first;
		}

		while (++first != last)
		{
			ForwardIt temp = first;

			if (++first == last) 
			{
				if (comp(*first, *min))
				{
					min = first;
				}
				else if (!(comp(*i, *max)))
				{
					max = first;
				}
				break;
			}
			else
			{
				
			}
		}
		return { min, max };
	}
}

#endif