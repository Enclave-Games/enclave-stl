#ifndef ENCLAVE_STL_UTILITY
#define ENCLAVE_STL_UTILITY

#include "base/config.h"

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
		return static_cast<typename std::remove_reference<T>::type&&>(t);
	}

	template <class T>
	ENCLAVE_CONSTEXPR void swap(T& a, T& b) ENCLAVE_NOEXC
	{
		T _temp = EUTIL_MOVE(a);
		a = EUTIL_MOVE(b);
		b = EUTIL_MOVE(_temp);
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
			return reinterprest_cast<T>(u);
		}
	};
}


#endif