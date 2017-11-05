/*
 *
 * String.c
 *
 * Copyright (C) 2017 by Liu Yunfeng.
 *
 *        Create : 2017-11-05 22:00:37
 * Last Modified : 2017-11-05 22:00:37
 */

#include "String.h"
/*
String_New
String_StripLeading                 - strip the leading spaces
String_StripTrailingSpace           - strip the trailing spaces
String_StripLeadingAndTrailingSpace - strip the leading and trailing spaces
String_SafeCopy                     - safely to copy a string
String_Dup                          - dup a string
String_Concat
String_Compare
String_Swap
String_Substr
String_Replace
String_Insert
String_Split
String_Destroy
*/

/**
 * String_New - Create a null string
 *
 * @size : length of string
 *
 * Return values
 * NULL     : Create string failed
 * New Addr : Create succeed, return the beginning address
 *
 */
char *String_New(int size)
{
	char *ptr = NULL;

	if(size<1)
		return NULL;

	ptr = xMalloc(size+sizeof(StringHeader));
	if(!ptr)
		return NULL;

	((StringHeader*)ptr)->presize = size;
	((StringHeader*)ptr)->cursize = size;
	((StringHeader*)ptr)->strflag = STR_MARK;

	return ptr + sizeof(StringHeader);
}

/**
 * String_Resize - Re-set string's length
 *
 * @in    : origin string
 * @osize : origin length of @in
 * @nsize : new length of string
 *
 * If resize succeed, it'll copy origin string into new string,
 * and it does not change origin string.
 *
 * @nsize must larger than @osize, but they can be equal.
 *
 * Return values
 * NULL     : Resize the string failed
 * New Addr : Resize succeed, return the beginning address
 *
 */
char *String_Resize(const char *in, int osize, int nsize)
{
	char *ptr = NULL;

	if(osize<1 || nsize<2 || osize>nsize)
		return NULL;

	ptr = xMalloc(nsize+sizeof(StringHeader));
	if(!ptr)
		return NULL;

	memcpy(ptr+sizeof(StringHeader), in, osize);

	((StringHeader*)ptr)->presize = osize;
	((StringHeader*)ptr)->cursize = nsize;
	((StringHeader*)ptr)->strflag = STR_MARK;

	return ptr + sizeof(StringHeader);
}

char *String_StripLeadingSpace(const char *in)
{
	;
}

char *String_StripTrailingSpace(const char *in)
{
	;
}

char *String_StripLeadingAndTrailingSpace(const char *in)
{
	;
}

char *String_Dup()
{
	;
}

void String_Destroy(void *ptr)
{
	if(!ptr)
		return;

	if(((StringHeader*)ptr)->strflag == STR_MARK)
		xFree(ptr-sizeof(StringHeader));

	return;
}
