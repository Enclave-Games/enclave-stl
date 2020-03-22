#ifndef ENCLAVE_STL_NEW
#define ENCLAVE_STL_NEW

#include "base/config.h"
#include <iostream>

namespace emem
{
	void* operator new(SIZE_T size);
	void* operator new(SIZE_T size, std::align_val_t alignment);
	void* operator new(SIZE_T size, const std::nothrow_t&);
}

#endif