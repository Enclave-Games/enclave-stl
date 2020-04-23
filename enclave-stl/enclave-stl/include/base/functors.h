#ifndef ENCLAVE_STL_FUNCTORS
#define ENCLAVE_STL_FUNCTORS

#include "base/config.h"

namespace efun
{
	template <typename T = void>
	struct less
	{
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const T&& right) const
		{
			return left < right;
		}
	};

	template <>
	struct less<void>
	{
		template <class T, class Ty2>
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const Ty2&& right) const
		{
			return left < right;
		}
	};

	template< class T = void >
	struct equal_to
	{
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const T&& right) const
		{
			return left == right;
		}
	};

	template<>
	struct equal_to<void>
	{
		template <class T, class Ty2>
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const Ty2&& right) const
		{
			return left == right;
		}
	};

	template< class T = void >
	struct not_equal_to
	{
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const T&& right) const
		{
			return left != right;
		}
	};

	template<>
	struct not_equal_to<void>
	{
		template <class T, class Ty2>
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const Ty2&& right) const
		{
			return left != right;
		}
	};

	template< class T = void >
	struct greater
	{
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const T&& right) const
		{
			return left > right;
		}
	};

	template<>
	struct greater<void>
	{
		template <class T, class Ty2>
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const Ty2&& right) const
		{
			return left > right;
		}
	};

	template< class T = void >
	struct greater_equal
	{
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const T&& right) const
		{
			return left >= right;
		}
	};

	template<>
	struct greater_equal<void>
	{
		template <class T, class Ty2>
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const Ty2&& right) const
		{
			return left >= right;
		}
	};

	template < typename T = void >
	struct less_equal
	{
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const T&& right) const
		{
			return left <= right;
		}
	};

	template <>
	struct less_equal<void>
	{
		template <class T, class Ty2>
		ENCLAVE_CONSTEXPR bool operator()(const T&& left, const Ty2&& right) const
		{
			return left <= right;
		}
	};

	template< class T = int >
	struct plus
	{
		ENCLAVE_CONSTEXPR T operator()(const T& left, const T& right) const
		{
			return left + right;
		}
	};

	template< class T = int >
	struct minus
	{
		ENCLAVE_CONSTEXPR T operator()(const T& left, const T& right) const
		{
			return left - right;
		}
	};

	template< class T = int >
	struct multiplies
	{
		ENCLAVE_CONSTEXPR T operator()(const T& left, const T& right) const
		{
			return left * right;
		}
	};

	template< class T = int >
	struct divides
	{
		ENCLAVE_CONSTEXPR T operator()(const T& left, const T& right) const
		{
			return left / right;
		}
	};

	template< class T = int >
	struct modulus
	{
		ENCLAVE_CONSTEXPR T operator()(const T& left, const T& right) const
		{
			return left % right;
		}
	};

	template< class T = int >
	struct negate
	{
		ENCLAVE_CONSTEXPR T operator()(const T& arg) const
		{
			return -arg;
		}
	};
}

#endif
