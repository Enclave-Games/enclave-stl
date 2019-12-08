#ifndef ENCLAVE_STL_BINARY_SEARCH
#define ENCLAVE_STL_BINARY_SEARCH

#include <iostream>

namespace enclave_stl
{
	namespace algorithms
	{
		class binary_search
		{
		public:
			void search_element();
			unsigned get_low_element();
			unsigned get_high_element();

		private:
			unsigned int low_element = 0;
			unsigned int high_element = 0;
			bool sorted = false;
		};
	}
}

#endif