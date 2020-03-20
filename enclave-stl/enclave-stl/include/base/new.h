#ifndef ENCLAVE_STL_NEW
#define ENCLAVE_STL_NEW

#include "base/config.h"

namespace edynamic_memory
{
	void* operator new(SIZE_T size);
	void* operator new(std::size_t size, std::align_val_t alignment);
	void* operator new(std::size_t size, const std::nothrow_t&);
}

#endif