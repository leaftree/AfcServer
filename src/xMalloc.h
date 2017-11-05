
/**
 * xMalloc.h
 *
 * Copyright (C) 2017 by Liu YunFeng.
 *
 *        Create : 2017-11-05 22:01:47
 * Last Modified : 2017-11-05 22:01:47
 */

#ifndef __XMALLOC_H__
#define __XMALLOC_H__

#include "defs.h"

__BEGIN_DECLS

void *xMalloc(size_t size);

void *xCalloc(size_t nmemb, size_t size);

void *xRealloc(void *ptr, size_t size);

void *xFree(void *ptr);

__END_DECLS

#endif /* __MALLOC_H__ */
