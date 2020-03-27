#ifndef ENCLAVE_STL_MAKERS
#define ENCLAVE_STL_MAKERS

#include "algorithms.h"
#include <memory>

namespace emakers
{
	template< typename Sequence >
	void make_unique_sequance(Sequence& seq)
	{
		ealg::sort(seq.begin(), seq.end());
		auto it = std::unique(seq.begin(), seq.end());
		seq.resize(ealg::distance(seq.begin(), it);
	}
}

#endif