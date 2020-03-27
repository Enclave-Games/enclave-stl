#ifndef ENCLAVE_STL_MAKERS
#define ENCLAVE_STL_MAKERS

#include "algorithms.h"
#include <memory>

namespace emakers
{
	template< typename Sequence >
	void make_unique_sequance(Sequence& seq, bool resize_now)
	{
		ealg::sort(seq.begin(), seq.end());
		auto it = std::unique(seq.begin(), seq.end());

		if (resize_now) {
			seq.resize(ealg::distance(seq.begin(), it);
		}
	}
}

#endif