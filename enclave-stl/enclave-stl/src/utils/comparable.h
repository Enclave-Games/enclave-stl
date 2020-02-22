#ifndef ENCLAVE_STL_COMPARABLE
#define ENCLAVE_STL_COMPARABLE

namespace estl
{
	template<typename Object>
	class comparable
	{
	public:
		// DO NOT FORGIVE OVERRIDE IT!
		virtual int compareTo(const Object& value) = 0;
	};
}


#endif
