#ifndef ENCLAVE_STL_CONFIG
#define ENCLAVE_STL_CONFIG

///////////////////////////////////////////////////////////////////////////////
/// File - config.h
/// This is the ENCLAVE_STL configuration file. All configurable parameters of ENCLAVE_STL
/// are controlled through this file. However, all the settings here can be
/// manually overridden by the user
//
///////////////////////////////////////////////////////////////////////////////

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

#define ENCLAVE_ASSERT(expression) static_assert(expression, #expression)

#define ENCLAVE_ASSERT_MSG(expression, message) static_assert(expression, message)

#define ENCLAVE_CONSTEXPR constexpr

#define ENCLAVE_NOEXC noexcept

#endif