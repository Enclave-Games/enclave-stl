#ifndef ENCLAVE_STL_ALGORITHMS
#define ENCLAVE_STL_ALGORITHMS

#include <vector>

namespace enclave_stl
{
	namespace algorithms
	{
		template <typename RandomIter>
		void sort(RandomIter first, RandomIter second)
		{

		}


		void selection_sort()
		{

		}

	
		void qsort(int* a, int start, int end)
		{
			if (start < end)
			{
				int pivot = a[end];
				int P_index = start;
				int i, t; //t is temporary variable


				for (i = start; i < end; i++)
				{
					if (a[i] <= pivot)
					{
						t = a[i];
						a[i] = a[P_index];
						a[P_index] = t;
						P_index++;
					}
				}
				t = a[end];
				a[end] = a[P_index];
				a[P_index] = t;

				qsort(a, start, P_index - 1);
				qsort(a, P_index + 1, end);
			}
		}
	}
}

#endif