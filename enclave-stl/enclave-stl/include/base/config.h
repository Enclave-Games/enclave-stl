#ifndef ENCLAVE_STL_CONFIG
#define ENCLAVE_STL_CONFIG

///////////////////////////////////////////////////////////////////////////////
/// File - config.h
/// This is the ENCLAVE_STL configuration file. All configurable parameters of ENCLAVE_STL
/// are controlled through this file. However, all the settings here can be
/// manually overridden by the user
//
///////////////////////////////////////////////////////////////////////////////


#if ((__cplusplus >= 201103L) || (_MSC_VER >= 1900))
	#define _ESTL_NATIVE_CPP11_SUPPORT
	#define _ESTL_NATIVE_CPP11_TYPES_SUPPORT
#endif


#ifdef ENCLAVE_DEBUG
	#if defined(ENCLAVE_DEBUG) || defined(DEBUG)
	#define ENCLAVE_DEBUG 1
	#else
		#define ENCLAVE_DEBUG 0
	#endif
#endif

#ifdef ENCLAVE_RELEASE
	#if defined(ENCLAVE_RELEASE) || defined(RELEASE)
	#define ENCLAVE_RELEASE 1
	#else
		#define ENCLAVE_RELEASE 0
	#endif
#endif

#define EUTIL_MOVE(var) ::eutil::move(var)

#ifdef _ESTL_NATIVE_CPP11_SUPPORT
	#define ENCLAVE_ASSERT(expression) static_assert(expression, #expression)
	#define ENCLAVE_ASSERT_MSG(expression, message) static_assert(expression, message)
#endif

#if !defined(FOREVER_CYCLE)
	#define FOREVER_CYCLE for(;;)
#endif

#define ENCLAVE_CONSTEXPR constexpr

#define ENCLAVE_NOEXC noexcept

#define COUNT_OF(arr) sizeof(arr) / sizeof(arr[0])

#endif