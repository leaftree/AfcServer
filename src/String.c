/*
 *
 * String.c
 *
 * Copyright (C) 2017 by Liu Yunfeng.
 *
 *        Create : 2017-11-05 22:00:37
 * Last Modified : 2017-11-05 22:00:37
 */

#include "defs.h"

/**
                                             |<- return address 
	+---------+---------+---------+------------+-------------------+
	| 4 Btyes | 4 Btyes | 4 Btyes |  4 Btyes   |     n Btyes       |
	+---------+---------+---------+------------+--------~~~--------+
	| presize | cursize | lengths | 0x00535359 |        ...        |
	+---------+---------+---------+------------+--------~~~--------+
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
 * String_Create - Create a string and initialize by param
 *
 * @ptr  : origin string
 * @size : valid length of origin string
 *
 * Return values
 * NULL     : Create string failed or @ptr is null
 * New Addr : Create succeed, return the beginning address
 *
 */
char *String_Create(char *ptr, int size)
{
	if(!ptr || size<1)
		return NULL;

	char *dataptr = xMalloc(size+sizeof(StringHeader)+1);
	if(!dataptr)
		return NULL;

	((StringHeader*)ptr)->presize = size+1;
	((StringHeader*)ptr)->cursize = size+1;
	((StringHeader*)ptr)->lengths = size;
	((StringHeader*)ptr)->strflag = STRING_MARK;

	return dataptr + sizeof(StringHeader);
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
 * String_Dup - Duplicate a string
 *
 * @in : origin string
 *
 * Waring: @in should be a string, if it's C-string(char*), may be crash.
 *
 * Return values
 * NULL     : @in is null or duplicate failed
 * New Addr : duplicate succeed, return new string address
 */
char *String_Dup(const char *in)
{
	char *ptr = NULL;
	ptr = String_SafeCopy(ptr, in);

	return ptr;
}

/**
 * String_Concat - Concat two string
 *
 * @s1 : pionneer string
 * @l1 : length of pionneer string
 * @s2 : spliced string
 * @l2 : length of spliced string
 *
 * Return values
 * NULL     :
 * New Addr : 
 *
 */
char *String_Concat(const char *s1, int l1, const char *s2, int l2)
{
	char *ptr = NULL;

	if(!s1) return (char*)s2;
	if(!s2) return (char*)s1;

	ptr = String_New(l1+l2+1);
	if(!ptr)
		return NULL;

	memcpy(ptr, s1, l1);
	memcpy(ptr+l1, s2, l2);

	STRING_SET_LENGTH(ptr, l1+l2);

	return ptr;
}

/**
 * String_SafeCopy - Copy a string safely
 *
 * @s1 : object string
 * @s2 : origin string
 *
 * Return values
 * NULL     : copy work failed
 * New Addr : return the address of object string
 *
 * If @s1 is null, it'll allocated a space for @s1
 * If @s1 has no enough sapce, it'll extend it's space
 */
char *String_SafeCopy(char *s1, const char *s2)
{
	char *ptr = NULL;

	if(!s2 || STRING_SIZEOF(s2)<1)
		return NULL;

	if(!s1)
	{
		ptr = String_New(STRING_LENGTH(s2)+1);
		if(!ptr)
			return NULL;
	}
	else if(STRING_SIZEOF(s1) < STRING_SIZEOF(s2))
	{
		ptr = String_Resize(s1, STRING_LENGTH(s1), STRING_LENGTH(s2));
		if(!ptr)
			return NULL;
		String_Destroy(s1);
	}

	memcpy(ptr, s2, STRING_LENGTH(s2));
	STRING_SET_LENGTH(ptr, STRING_LENGTH(s2));
	s1 = ptr;

	return ptr;
}

/**
 * String_Compare - Compare(memory compare) two string
 *
 * @s1 : 1st string
 * @s2 : 2nd string
 *
 * Return values
 * = 0 : equal
 * > 0 : s1>s2
 * < 0 : s2>s1
 *
 * When return values is not zero, the value is they diff
 */
int String_Compare(const char *s1, const char *s2)
{
	if(!s1 || !s2)
	{
		if(!s1 && !s2)
			return 0;
		if(!s1)
			return *s2;
		if(!s2)
			return *s1;
	}

	return memcmp(s1, s2,
			STRING_LENGTH(s1) > STRING_LENGTH(s2) ?
			STRING_LENGTH(s2) : STRING_LENGTH(s1));
}

/**
 * String_Swap - Swap two string
 *
 * @s1 : 1st sring
 * @s2 : 2nd string
 *
 * No return value
 */
void String_Swap(char *s1, char *s2)
{
	return ;
}

char *String_Substr(char *s1, char *s2)
{
	return NULL;
}

char *String_Replace(char *ptr, char d, char s)
{
	return NULL;
}

char *String_Insert(char *ptr)
{
	return NULL;
}

char *String_Split(char *ptr)
{
	return NULL;
}

/**
 * String_Destroy - Free the memory of a string
 *
 * @ptr : The object needed to be free
 *
 * Return values
 * No return values
 */
void String_Destroy(void *ptr)
{
	if(!ptr)
		return;

	if(IS_STRING(ptr))
		xFree(ptr-sizeof(StringHeader));

	return;
}

/**
 * String_StripLeadingSpace - Strip the leading space character
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

	char *ptr = NULL;
	const char *baseptr = in;

	if(!in) {
		errno=EINVAL;
		return NULL;
	}

	while(IS_SPACECHAR(*baseptr)) {
		baseptr++;
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

/**
 * String_StripTrailingSpace - Strip the trailing space character
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
char *String_StripTrailingSpace(const char *in)
{
	errno=0;

	int len;
	char *ptr = NULL;
	const char *endptr = in;

	if(!in) {
		errno=EINVAL;
		return NULL;
	}

	len = strlen(in);
	endptr += (len-1);

	while(IS_SPACECHAR(*endptr) && len-->0) {
		endptr--;
	}

	if(len<1 || !endptr) {
		errno=0;
		return NULL;
	}

	ptr = String_Resize(in, len, len+1);
	if(!ptr) {
		errno=ENOMEM;
		return NULL;
	}

	return ptr;
}

/**
 * String_StripLeadingAndTrailingSpace -
 *   Strip the leading and trailing space character
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
char *String_StripLeadingAndTrailingSpace(const char *in)
{
	errno=0;

	int len;
	char *ptr = NULL;
	const char *iterptr = in;

	if(!in) {
		errno=EINVAL;
		return NULL;
	}

	len = strlen(in);
	iterptr += (len-1);

	while(IS_SPACECHAR(*iterptr) && len-->0) {
		iterptr--;
	}

	iterptr = in;
	while(IS_SPACECHAR(*iterptr) && len-->0) {
		iterptr++;
	}

	if(len<1 || !iterptr) {
		errno=0;
		return NULL;
	}

	ptr = String_Resize(iterptr, len, len+1);
	if(!ptr) {
		errno=ENOMEM;
		return NULL;
	}

	return ptr;
}

/****************************************
 *
 *
 *
 ***************************************/
char *String_StripLeadingSpace2(char *in)
{
	;
}

char *String_StripTrailingSpace2(char *in)
{
	;
}

char *String_StripLeadingAndTrailingSpace2(char *in)
{
	;
}

char *String_Concat2(char *s1, const char *s2)
{
	;
}
