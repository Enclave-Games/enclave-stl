#ifndef ENCLAVE_STL_MAP
#define ENCLAVE_STL_MAP

#include <functional>
#include <exception>

namespace estl
{
	template<class Key, 
		class T,
		class Compare = std::less<Key>, 
		class Allocator = std::allocator<std::pair<const Key, T>>>
	class map
	{
	public:
		typedef map<Key, T, Allocator>  this_type;
		typedef Key						key_type;
		typedef T						mapped_type;
		typedef std::pair<const Key, T> value_type;
		typedef size_t					size_type;
		typedef ptrdiff_t				difference_type;
		typedef Compare					compare_type;
		typedef Allocator				allocator_type;
		typedef value_type&		reference;

		T& at(const Key& key);
		const T& at(const Key& key) const;
	protected:
	};
}

#endif