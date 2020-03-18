#ifndef ENCLAVE_STL_ALGORITHMS
#define ENCLAVE_STL_ALGORITHMS

#include <vector>
#include <algorithm>
#include "sequance_iterator.h"

// TODO LIST!!!
// sort
// count
// count_if
// equal
// equal<Compare>
// copy_if
// move
// binary_search
// binary_search<Compare>
// binary_search_i
// binary_search_i<Compare>

namespace ealg
{
	template <typename RandomAccessIter>
	void sort(RandomAccessIter start, RandomAccessIter end)
	{
		if (start == end)
		{
			return;
		}

		if (start != end)
		{
			RandomAccessIter pivot = end;
			RandomAccessIter p_index = start;

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

	template< class ForwardIt >
	ForwardIt max_element(ForwardIt first, ForwardIt last)
	{
		if (first == last)
		{
			return last;
		}

		ForwardIt largest = first;

		for (; first != last; ++first)
		{
			if (*largest < *first)
			{
				largest = first;
			}
		}

		return largest;
	}

	template< class ForwardIt, class Compare >
	ForwardIt max_element(ForwardIt first, ForwardIt last, Compare comp)
	{
		if (first == last)
		{
			return last;
		}

		ForwardIt largest = first;

		for (; first != last; ++first)
		{
			if (comp(*largest, *first))
			{
				largest = first;
			}
		}

		return largest;
	}

	template< class ForwardIt >
	ForwardIt min_element(ForwardIt first, ForwardIt last)
	{
		if (first == last)
		{
			return last;
		}

		ForwardIt smallest = first;

		for (; first != last; ++first)
		{
			if (*smallest > *first)
			{
				smallest = first;
			}
		}

		return smallest;
	}

	template< class ForwardIt, class Compare >
	ForwardIt min_element(ForwardIt first, ForwardIt last, Compare compare)
	{
		if (first == last)
		{
			return last;
		}

		ForwardIt smallest = first;

		for (; first != last; ++first)
		{
			if (*smallest < *first)
			{
				smallest = first;
			}
		}

		return smallest;
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
		return *ealg::max_element(init_list.begin(), init_list.end());
	}

	template<class T, class Compare>
	const T& max(const std::initializer_list<T> init_list, Compare compare)
	{
		return *ealg::max_element(init_list.begin(), init_list.end(), compare);
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
		return *ealg::min_element(init_list.begin(), init_list.end());
	}

	template<class T, class Compare>
	const T& min(const std::initializer_list<T> init_list, Compare compare)
	{
		return *ealg::min_element(init_list.begin(), init_list.end(), compare);
	}

	template< class ForwardIt >
	std::pair<ForwardIt, ForwardIt>
		minmax_element(ForwardIt first, ForwardIt last)
	{
		return std::minmax_element(first, last);
	}

	template<class ForwardIt, class Compare >
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
				else if (!(comp(*temp, *max)))
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

	template< class ForwardIt >
	ForwardIt adjacent_find(ForwardIt first, ForwardIt last)
	{
		if (first == last)
		{
			return last;
		}
		ForwardIt next = first;
		next++;
		for (; next != last; ++next, ++first)
		{
			if (*first == *next)
			{
				return first;
			}
		}
		return last;
	}

	template< class ForwardIt, class Compare >
	ForwardIt adjacent_find(ForwardIt first, ForwardIt last, Compare comp)
	{
		if (first == last)
		{
			return last;
		}
		ForwardIt next = first;
		next++;
		for (; next != last; ++next, ++first)
		{
			if (comp(*first, *next))
			{
				return first;
			}
		}
		return last;
	}

	template< class InputIt, class T >
	InputIt find(InputIt first, InputIt last, const T& value)
	{
		for (; first != last; ++first)
		{
			if (*first == value)
			{
				return first;
			}
		}

		return last;
	}

	template<class InputIt, class UnaryPredicate>
	constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate q)
	{
		for (; first != last; ++first)
		{
			if (!q(*first))
			{
				return first;
			}
		}

		return last;
	}

	template<class InputIt, class UnaryPredicate>
	constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
	{
		for (; first != last; ++first)
		{
			if (p(*first))
			{
				return first;
			}
		}

		return last;
	}

	template< class InputIt, class UnaryPredicate >
	bool all_of(InputIt first, InputIt last, UnaryPredicate p)
	{
		return ealg::find_if_not(first, last, p) == last;
	}

	template< class InputIt, class UnaryPredicate >
	constexpr bool any_of(InputIt first, InputIt last, UnaryPredicate p)
	{
		return ealg::find_if(first, last, p) != last;
	}

	template< class InputIt, class UnaryPredicate >
	constexpr bool none_of(InputIt first, InputIt last, UnaryPredicate p)
	{
		return ealg::find_if(first, last, p) == last;
	}

	template< class InputIt, class OutputIt >
	OutputIt copy(InputIt first, InputIt last, OutputIt start_dest_range)
	{
		while (first != last) {
			*start_dest_range++ = *first++;
		}
		return start_dest_range;
	}

	template< class T >
	T&& forward(typename std::remove_reference<T>::type& t) noexcept
	{
		static_assert(!is_lvalue_reference<T>::value,
			"can not forward an rvalue as an lvalue");
		return static_cast<T&&>(t);
	}
}

#endif