#ifndef ENCLAVE_STL_ALGORITHMS
#define ENCLAVE_STL_ALGORITHMS

#include <vector>
#include <exception>
#include "base/config.h"
#include "sequance_iterator.h"

// TODO LIST!!!
// sort
// sort<Compare>     
// sort_heap         
// sort_heap<Compare>

// copy_if
// copy_backward
// equal
// equal<Compare>
// equal_range
// equal_range<Compare>
// move
// binary_search
// binary_search<Compare>
// binary_search_i
// binary_search_i<Compare>
// distance
// change_heap
// change_heap<Compare>
// random_shuffle
// rand
// shuffle

namespace ealg
{
	template <typename RandomAccessIter>
	void sort(RandomAccessIter start, RandomAccessIter end)
	{
		if (start == end)
		{
			throw std::exception("Fail sort!");
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
	ENCLAVE_CONSTEXPR InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate q)
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
	ENCLAVE_CONSTEXPR InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
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
	ENCLAVE_CONSTEXPR bool any_of(InputIt first, InputIt last, UnaryPredicate p)
	{
		return ealg::find_if(first, last, p) != last;
	}

	template< class InputIt, class UnaryPredicate >
	ENCLAVE_CONSTEXPR bool none_of(InputIt first, InputIt last, UnaryPredicate p)
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

	template< class InputIt1, class InputIt2 >
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	template< class InputIt, class T>
	typename std::iterator_traits<InputIt>::difference_type
		count(InputIt first, InputIt last, const T& value)
	{
		typename std::iterator_traits<InputIt>::difference_type counter = 0;
		for (; first != last; ++first)
		{
			if (*first == value) {
				++counter;
			}
		}
		return counter;
	}

	template< class InputIt, class UnaryPredicate>
	typename std::iterator_traits<InputIt>::difference_type
		count_if(InputIt first, InputIt last, UnaryPredicate predicate)
	{
		typename std::iterator_traits<InputIt>::difference_type counter = 0;
		for (; first != last; ++first)
		{
			if (predicate(*first)) {
				++counter;
			}
		}
		return counter;
	}

	template< class T >
	T&& forward(typename std::remove_reference<T>::type& t) ENCLAVE_NOEXC
	{
		ENCLAVE_ASSERT_MSG(!is_lvalue_reference<T>::value,
			"can not forward an rvalue as an lvalue");
		return static_cast<T&&>(t);
	}
	
	template< class T >
	typename std::remove_reference<T>::type&& move(T&& t) ENCLAVE_NOEXC
	{
		return static_cast<typename std::remove_reference<T>::type&&>(t);
	}

	template< class RandomIt >
	void random_shuffle(RandomIt first, RandomIt last)
	{

	}

	template< class RandomIt, class RandomFunc >
	void random_shuffle(RandomIt first, RandomIt last, RandomFunc& r)
	{

	}

	template< class RandomIt, class URBG >
	void shuffle(RandomIt first, RandomIt last, URBG&& g)
	{

	}
}

#endif