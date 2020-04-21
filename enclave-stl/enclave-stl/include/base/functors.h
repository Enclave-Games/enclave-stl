#ifndef ENCLAVE_STL_FUNCTORS
#define ENCLAVE_STL_FUNCTORS

#include "base/config.h"

namespace efun
{
	template <typename _Ty = void>
	struct less
	{
		ENCLAVE_CONSTEXPR bool operator()(_Ty&& left, _Ty&& right) const
		{
			return left < right;
		}
	};

	template <>
	struct less<void>
	{
		template <class _Ty1, class _Ty2>
		ENCLAVE_CONSTEXPR bool operator()(_Ty1&& left, _Ty2&& right) const
		{
			return left < right;
		}
	};

	template< class T = void >
	struct equal_to
	{
		ENCLAVE_CONSTEXPR bool operator()(T&& left, T&& right) const
		{
			return left == right;
		}
	};

	template<>
	struct equal_to<void>
	{
		template <class _Ty1, class _Ty2>
		ENCLAVE_CONSTEXPR bool operator()(_Ty1&& left, _Ty2&& right) const
		{
			return left == right;
		}
	};

	template< class T = void >
	struct not_equal_to
	{
		ENCLAVE_CONSTEXPR bool operator()(T&& left, T&& right) const
		{
			return left != right;
		}
	};

	template<>
	struct not_equal_to<void>
	{
		template <class _Ty1, class _Ty2>
		ENCLAVE_CONSTEXPR bool operator()(_Ty1&& left, _Ty2&& right) const
		{
			return left != right;
		}
	};

	template< class T = void >
	struct greater
	{
		ENCLAVE_CONSTEXPR bool operator()(T&& left, T&& right) const
		{
			return left > right;
		}
	};

	template<>
	struct greater<void>
	{
		template <class _Ty1, class _Ty2>
		ENCLAVE_CONSTEXPR bool operator()(_Ty1&& left, _Ty2&& right) const
		{
			return left > right;
		}
	};

	template< class T = void >
	struct greater_equal
	{
		ENCLAVE_CONSTEXPR bool operator()(T&& left, T&& right) const
		{
			return left >= right;
		}
	};

	template<>
	struct greater_equal<void>
	{
		template <class _Ty1, class _Ty2>
		ENCLAVE_CONSTEXPR bool operator()(_Ty1&& left, _Ty2&& right) const
		{
			return left >= right;
		}
	};

	template < typename _Ty = void >
	struct less_equal
	{
		ENCLAVE_CONSTEXPR bool operator()(_Ty&& left, _Ty&& right) const
		{
			return left <= right;
		}
	};

	template <>
	struct less_equal<void>
	{
		template <class _Ty1, class _Ty2>
		ENCLAVE_CONSTEXPR bool operator()(_Ty1&& left, _Ty2&& right) const
		{
			return left <= right;
		}
	};
}

#endif
