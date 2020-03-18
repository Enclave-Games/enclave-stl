#ifndef ENCLAVE_STL_CONFIG
#define ENCLAVE_STL_CONFIG

///////////////////////////////////////////////////////////////////////////////
/// This is the ENCLAVE_STL configuration file. All configurable parameters of ENCLAVE_STL
/// are controlled through this file. However, all the settings here can be
/// manually overridden by the user
//
///////////////////////////////////////////////////////////////////////////////

#define ENCLAVE_ASSERT(expression) static_assert(expression, #expression)

#define ENCLAVE_ASSERT_MSG(expression, message) static_assert(expression, message)

typedef size_t SIZE_T;

#endif