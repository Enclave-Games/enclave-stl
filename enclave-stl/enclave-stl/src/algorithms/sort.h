#ifndef ENCLAVE_STL_SORT
#define ENCLAVE_STL_SORT


namespace enclave_stl
{
	template <typename Iter>
	void sort(Iter first, Iter second);

	constexpr void sort();
}

#endif