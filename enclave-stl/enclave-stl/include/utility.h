#ifndef ENCLAVE_STL_UTILITY
#define ENCLAVE_STL_UTILITY

#include "base/config.h"
#include "type_traits.h"
#include <iostream>

namespace eutil
{
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
		return static_cast<std::remove_reference_t<T>&&>(t);
	}

	template <class T>
	ENCLAVE_CONSTEXPR void swap(T& left, T& right) ENCLAVE_NOEXC
	{
		T _temp = EUTIL_MOVE(left);
		left = EUTIL_MOVE(right);
		right = EUTIL_MOVE(_temp);
	}

	template <class Iter, std::enable_if_t<!std::_Unwrappable_v<Iter>, int> = 0>
	constexpr const Iter&& get_unwrapped(const Iter && It) {
		return static_cast<const Iter&&>(It);
	}

	template <class Iter, std::enable_if_t<!std::_Unwrappable_v<Iter>, int> = 0>
	constexpr const Iter & get_unwrapped(const Iter & It) {
		return It;
	}

	template <class Iter, std::enable_if_t<std::_Unwrappable_v<Iter>, int> = 0>
	constexpr auto get_unwrapped(const Iter & It) {
		return It._Unwrapped();
	}

	template <class _T>
	ENCLAVE_CONSTEXPR _T* get_unwrapped(const _T* _Ptr) {
		return _Ptr;
	}

	template <class T>
	T next(T x)
	{
		return ++x;
	}

	template <class T, class Distance>
	T next(T x, Distance n)
	{
		ealg::advance(x, n);
		return x;
	}

	template <class T>
	T prior(T x)
	{
		return --x;
	}

	template <class T, class Distance>
	T prior(T x, Distance n)
	{
		ealg::advance(x, -n);
		return x;
	}

	template< class T >
	struct static_cast_to
	{
		template< class U >
		T operator()(U u) const
		{
			return static_cast<T>(u);
		}
	};

	template< class T >
	struct dynamic_cast_to
	{
		template< class U >
		T operator()(U u) const
		{
			return dynamic_cast<T>(u);
		}
	};

	template< class T >
	struct const_cast_to
	{
		template< class U >
		T operator()(U u) const
		{
			return const_cast<T>(u);
		}
	};

	template< class T >
	struct reinterpret_cast_to
	{
		template< class U >
		T operator()(U u) const
		{
			return reinterpret_cast<T>(u);
		}
	};
}


#endif