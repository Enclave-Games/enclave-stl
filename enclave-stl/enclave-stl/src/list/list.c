#include "list.h"

_Bool exist(int index)
{
	
}

_Bool exist(void* element)
{
	
}

_Bool is_empty()
{
	return list.size == 0;
}

void add(int index, void* element)
{
	list.size++;
}

void add(void* element)
{
	list.size++;

}

void remove(int index)
{
	list.size--;
}

void remove(void* element)
{
	list.size--;
}