// Test implementation//

#ifndef ENCLAVE_STL_LIST
#define ENCLAVE_STL_LIST

#include <stdlib.h>

typedef struct list;

typedef struct list {
	void *data[];
};

_Bool exist(int index);

_Bool exist(void* element);

_Bool is_empty();

void add(int index, void* element);

void add(void* element);

void remove(int index);

void remove(void* element);

#endif