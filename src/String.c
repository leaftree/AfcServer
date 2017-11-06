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
	((StringHeader*)ptr)->lengths = 0x0;
	((StringHeader*)ptr)->strflag = STRING_MARK;

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
	((StringHeader*)ptr)->lengths = osize;
	((StringHeader*)ptr)->strflag = STRING_MARK;

	return ptr + sizeof(StringHeader);
}

/**
 * String_StripLeadingSpace - Strip the space character
 *
 * @in : origin string
 *
 * Return values
 * NULL     : all character is Space Character, or @in is invalid,
 *            or alloc memory fail.
 * New Addr : Strip succeed, return the beginning address(a new address)
 *
 * If @in is invalid, it'll return NULL, and set errno as EINVAL
 * If all character is Space Character, it'll return NULL, and errno set as Zero
 * If @xMalloc fail, it'll return NULL and set errno as ENOMEM
 *
 * Caller should check errno when call @String_StripLeadingSpace fail.
 */
char *String_StripLeadingSpace(const char *in)
{
    errno=0;

    char ch;
    char *ptr = NULL;
    const char *baseptr = in;

    if(!in) {
        errno=EINVAL;
        return NULL;
    }

    printf("%s %d %s\n", __func__, __LINE__, baseptr);
    while(IS_SPACECHAR(*baseptr++)) {
    printf("%s %s\n", __func__, baseptr);
        /* null */
    }

    if(!*baseptr) {
        errno=0;
        return NULL;
    }

    int len = strlen(baseptr);
	
    ptr = String_Resize(baseptr, len, len+1);
    if(!ptr) {
        errno=ENOMEM;
        return NULL;
    }

    return ptr;
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

	if(IS_STRING(ptr))
		xFree(ptr-sizeof(StringHeader));

	return;
}
