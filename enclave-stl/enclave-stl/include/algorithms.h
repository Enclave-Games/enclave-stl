#ifndef ENCLAVE_STL_ALGORITHMS
#define ENCLAVE_STL_ALGORITHMS

#include <vector>
#include <exception>
#include <random>
#include "base/config.h"
#include "iterator.h"

// TODO LIST!!!
// sort
// sort<Compare>     
// for_each_n
// mismatch
// find
// find_end
// find_first_of
// search
// search_n
// copy_n
// unique
// unique<Compare>

namespace ealg
{
	template< class InputIt, class Distance >
	void advance(InputIt& it, Distance n)
	{
		it += n;
	}

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

	template< class ForwardIt, class T >
	void fill(ForwardIt first, ForwardIt last, const T& value)
	{
		for (; first != last; ++first) {
			*first = value;
		}
	}

	template< class OutputIt, class Size, class T >
	void fill_n(OutputIt first, Size count, const T& value)
	{
		for (Size i = 0; i < count; i++) {
			*first++ = value;
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

	template< class InputIt, class UnaryFunction >
	UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
	{
		for (; first != last; ++first)
		{
			f(*first);
		}
		return f;
	}

	template< class ForwardIt >
	ForwardIt max_element(ForwardIt first, ForwardIt last)
	{
		if (first == last)
		{
			return last;
		}

		ForwardIt largest = first;
		++first;
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
		return (a < b) ? b : a;
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

	template< class ForwardIt, class T >
	bool binary_search(ForwardIt first, ForwardIt last, const T& value)
	{
		first = ealg::lower_bound(first, last, value);
		return (!(first == last) && !(value < *first));
	}

	template< class InputIt1, class InputIt2, class OutputIt >
	OutputIt merge(InputIt1 first1,
				   InputIt1 last1, 
				   InputIt2 first2,
				   InputIt2 last2, OutputIt d_first)
	{
		for (; first1 != last1; ++d_first) {
			if (first2 == last2) {
				return ealg::copy(first1, last1, d_first);
			}
			if (*first2 < *first1) {
				*d_first = *first2;
				++first2;
			}
			else {
				*d_first = *first1;
				++first1;
			}
		}
		return ealg::copy(first2, last2, d_first);
	}

	template<class InputIt1, class InputIt2,
		class OutputIt, class Compare>
		OutputIt merge(InputIt1 first1, InputIt1 last1,
			InputIt2 first2, InputIt2 last2,
			OutputIt d_first, Compare comp)
	{
		for (; first1 != last1; ++d_first) {
			if (first2 == last2) {
				return ealg::copy(first1, last1, d_first);
			}
			if (comp(*first2, *first1)) {
				*d_first = *first2;
				++first2;
			}
			else {
				*d_first = *first1;
				++first1;
			}
		}
		return ealg::copy(first2, last2, d_first);
	}

	template<class ForwardIt, class T, class Compare>
	bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp)
	{
		first = std::lower_bound(first, last, value, comp);
		return (!(first == last) && !(comp(value, *first)));
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
			*(++start_dest_range) = *(++first);
		}
		return start_dest_range;
	}

	template< class InputIt, class OutputIt, class UnaryPredicate >
	OutputIt copy_if(InputIt first, InputIt last, OutputIt start_dest_range, UnaryPredicate pred)
	{
		while (first != last) {
			if (pred(*first)) {
				*(++start_dest_range) = *(++first);
			}
		}
		return start_dest_range;
	}

	template< class BidirIt1, class BidirIt2 >
	BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
	{
		while(first != last)
		{
			*(--d_last) = *(--last);
		}
		return d_last;
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

	template< class InputIt >
	typename estl::iterator_traits<InputIt>::difference_type 
			distance(InputIt first, InputIt last)
	{
		return last - first;
	}

	template< class ForwardIt, class T >
	ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value)
	{
		ForwardIt it;
		typename estl::iterator_traits<ForwardIt>::difference_type count, step;
		count = ealg::distance(first, last);

		while (count > 0)
		{
			it = first;
			step = count / 2;
			ealg::advance(it, step);
			if (*it < value) {
				first = ++it;
				count -= step + 1;
			}
			else {
				count = step;
			}
		}
		return first;
	}

	template< class ForwardIt, class T, class Compare >
	ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp)
	{
		ForwardIt it;
		typename estl::iterator_traits<ForwardIt>::difference_type count, step;
		count = ealg::distance(first, last);

		while (count > 0)
		{
			it = first;
			step = count / 2;
			ealg::advance(it, step);
			if (comp(*it, value)) {
				first = ++it;
				count -= step + 1;
			}
			else {
				count = step;
			}
		}
		return first;
	}

	template< class ForwardIt, class T >
	ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value)
	{
		ForwardIt it;
		typename estl::iterator_traits<ForwardIt>::difference_type count, step;
		count = ealg::distance(first, last);

		while (count > 0)
		{
			it = first;
			step = count / 2;
			ealg::advance(it, step);
			if (!(value < *it)) {
				first = ++it;
				count -= step + 1;
			}
			else {
				count = step;
			}
		}
		return first;
	}

	template< class ForwardIt, class T, class Compare >
	ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp)
	{
		ForwardIt it;
		typename estl::iterator_traits<ForwardIt>::difference_type count, step;
		count = ealg::distance(first, last);

		while (count > 0)
		{
			it = first;
			step = count / 2;
			ealg::advance(it, step);
			if (!comp(value, *it))
			{
				first = ++it;
				count -= step + 1;
			}
			else
			{
				count = step;
			}
		}
		return first;
	}

	template< class ForwardIt, class T >
	std::pair<ForwardIt, ForwardIt> equal_range(ForwardIt first, ForwardIt last, const T& value)
	{
		return std::make_pair(ealg::lower_bound(first, last, value),
			ealg::upper_bound(first, last, value));
	}

	template< class ForwardIt, class T, class Compare >
	std::pair<ForwardIt, ForwardIt> equal_range(ForwardIt first, ForwardIt last, const T& value, Compare comp)
	{
		return std::make_pair(ealg::lower_bound(first, last, value, comp),
			ealg::upper_bound(first, last, value, comp));
	}

	template< class InputIt, class T>
	typename estl::iterator_traits<InputIt>::difference_type
		count(InputIt first, InputIt last, const T& value)
	{
		typename estl::iterator_traits<InputIt>::difference_type counter = 0;
		for (; first != last; ++first)
		{
			if (*first == value) {
				++counter;
			}
		}
		return counter;
	}

	template< class InputIt, class UnaryPredicate>
	typename estl::iterator_traits<InputIt>::difference_type
		count_if(InputIt first, InputIt last, UnaryPredicate predicate)
	{
		typename estl::iterator_traits<InputIt>::difference_type counter = 0;
		for (; first != last; ++first)
		{
			if (predicate(*first)) {
				++counter;
			}
		}
		return counter;
	}

	template< class RandomIt >
	void random_shuffle(RandomIt first, RandomIt last)
	{
		typename estl::iterator_traits<RandomIt>::difference_type i, n;
		n = last - first;
		for (i = n - 1; i > 0; --i) {
			eutil::swap(first[i], first[std::rand() % (i + 1)]);
		}
	}

	template< class RandomIt, class RandomFunc >
	void random_shuffle(RandomIt first, RandomIt last, RandomFunc& r)
	{
		typename estl::iterator_traits<RandomIt>::difference_type i, n;
		n = last - first;
		for (i = n - 1; i > 0; --i) {
			eutil::swap(first[i], first[r(i + 1)]);
		}
	}

	template< class RandomIt, class URBG >
	void shuffle(RandomIt first, RandomIt last, URBG&& g)
	{
		typedef typename estl::iterator_traits<RandomIt>::difference_type diff_t;
		typedef std::uniform_int_distribution<diff_t> distr_t;
		typedef typename distr_t::param_type param_t;

		distr_t D;
		diff_t n = last - first;
		for (diff_t i = n - 1; i > 0; --i) {
			eutil::swap(first[i], first[D(g, param_t(0, i))]);
		}
	}
}

#endif