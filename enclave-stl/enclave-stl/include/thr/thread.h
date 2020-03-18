#ifndef ENCLAVE_STL_THREAD
#define ENCLAVE_STL_THREAD

#include "base/config.h"

namespace ethr
{
	class thread 
	{
	public:
		class id;

		thread(const thread&) = delete;
		thread& operator=(const thread&) = delete;

		void swap(thread& __curr_thread) noexcept;
		bool joinable() const noexcept;
		void join();

		ethr::thread::id get_id();

	private:
	};
}

#endif