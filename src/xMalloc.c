/*
 *
 * xMalloc.c
 *
 * Copyright (C) 2017 by Liu Yunfeng.
 *
 *        Create : 2017-11-05 22:00:37
 * Last Modified : 2017-11-05 22:00:37
 */

#include "xMalloc.h"

void *xMalloc(size_t size)
{
	void *ptr = malloc(size);

	if(!ptr)
		return NULL;

	memset(ptr, 0x0, size);

	return ptr;
}

void *xCalloc(size_t nmemb, size_t size)
{
	void *ptr = calloc(nmemb, size);

	if(!ptr)
		return NULL;

	return ptr;
}

void *xRealloc(void* ptr, size_t size)
{
	if(!ptr)
		return NULL;

	void *data = realloc(ptr, size);

	return data;
}

void *xFree(void *ptr)
{
	if(ptr)
		free(ptr);
}
