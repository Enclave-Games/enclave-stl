#ifndef ENCLAVE_STL_COMPARABLE
#define ENCLAVE_STL_COMPARABLE

namespace enclave_stl
{
	template<typename Object>
	class comparable
	{
	public:
		virtual int compareTo(const Object& value) = 0;
	};
}


#endif
