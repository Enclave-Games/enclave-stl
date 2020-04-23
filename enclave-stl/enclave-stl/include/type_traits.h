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

		constexpr operator value_type() const noexcept {
			return value;
		}
	};

	template <bool val>
	using bool_constant = integral_constant<bool, val>;

	using true_type  = bool_constant<true>;
	using false_type = bool_constant<false>;

	template< class T >
	struct is_void : false_type 
	{};

	template<>
	struct is_void<void> : true_type
	{};

	template<>
	struct is_void<const void> : true_type
	{};

	template<>
	struct is_void<const volatile void> : true_type
	{};

	template< class T, class U >
	struct is_same 
	{
	};

	template< bool B, class T = void >
	struct enable_if
	{
		using type = T;
	};

	template <typename T>
	struct enable_if<false, T> {};

	template <typename T>
	struct enable_if<true, T> {};


	// Helpers
	template < bool B, class T = void >
	using enable_if_t = typename etypes::enable_if<B, T>::type;

	template <class T>
	constexpr bool is_void_v = etypes::is_void<T>::value;
}

#endif