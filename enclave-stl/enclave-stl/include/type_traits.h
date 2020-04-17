#ifndef ENCLAVE_STL_TYPE_TRAITS
#define ENCLAVE_STL_TYPE_TRAITS

namespace etypes
{
	template< class T, T v >
	struct integral_constant
	{
		static constexpr T value = v;
		using value_type = T;
		using type = integral_constant;
	};

	template< class T >
	struct is_void
	{

	};

	template< class T, class U >
	struct is_same 
	{
	};
}

#endif