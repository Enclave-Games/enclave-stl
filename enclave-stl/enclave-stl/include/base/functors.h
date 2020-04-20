#ifndef ENCLAVE_STL_FUNCTORS
#define ENCLAVE_STL_FUNCTORS

namespace efun
{
	template <typename _Ty = void>
	struct less
	{
		constexpr bool operator()(_Ty&& left, _Ty&& right) const
		{
			return left < right;
		}
	};

	template <>
	struct less<void>
	{
		template <class _Ty1, class _Ty2>
		constexpr bool operator()(_Ty1&& left, _Ty2&& right) const
		{
			return left < right;
		}
	};
}

#endif
