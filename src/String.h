/*
 *
 * String.h
 *
 * Copyright (C) 2017 by Liu Yunfeng.
 *
 *        Create : 2017-11-05 22:00:37
 * Last Modified : 2017-11-05 22:00:37
 */

#ifndef __STRING_H__
#define __STRING_H__

#include "defs.h"

#define STRING_MARK 0x00535359

/**
 *
 * struct StringHeader - Header of a string
 *
 * @presize : Previous valid length
 * @cursize : Current valid length
 * @lengths : Current used length
 * @strflag : Mark it as a string
 *
 * @strflag is a fixed value as @STRING_MARK
 *
 * When use String_New() to create a string, it will alloc
 * 16Bytes + string-size Byte(s) memory.
 *
 * But function only return string-size Btye(s). The 16Bytes is hidden, it is
 * used to represent the current length of the string, and it'll keep the 
 * previous length.
 */
typedef struct StringHeader_ {
	unsigned int presize;
	unsigned int cursize;
	unsigned int lengths;
	unsigned int strflag;
} StringHeader;

/**
 * Determine whether the point is a STRING-type
 */
#define IS_STRING(ptr) (((StringHeader*)ptr)->strflag == STRING_MARK)

/**
 * Determine whether the character is a blank character
 */
#define IS_SPACECHAR(ch) (\
		ch == '\f' ||\
		ch == '\n' ||\
		ch == '\r' ||\
		ch == '\t' ||\
		ch == '\v' ||\
		ch == ' ')

#define STRING_LENGTH(str) \
	(((StringHeader*)(str-sizeof(StringHeader)))->lengths)
#define STRING_SIZEOF(str) \
	(((StringHeader*)(str-sizeof(StringHeader)))->cursize)
#define STRING_PRESIZE(str) \
	(((StringHeader*)(str-sizeof(StringHeader)))->presize)

#define STRING_SET_LENGTH(str, nsize) \
	(((StringHeader*)(str-sizeof(StringHeader)))->lengths = nsize)
#define STRING_SET_SIZEOF(str, nsize) \
	(((StringHeader*)(str-sizeof(StringHeader)))->cursize = nsize)
#define STRING_SET_PRESIZE(str, nsize) \
	(((StringHeader*)(str-sizeof(StringHeader)))->presize = nsize)

char *String_New(int size);
char *String_Create(char *ptr, int size);
char *String_Concat(char *s1, const char *s2);
char *String_StripLeadingSpace(const char *in);
char *String_StripTrailingSpace(const char *in);
char *String_StripLeadingAndTrailingSpace(const char *in);

char *String_StripLeadingAndTrailingSpace2(char *in);

char *String_Dup(const char *in);
char *String_SafeCopy(char *s1, const char *s2);
char *String_Concat2(const char *s1, int l1, const char *s2, int l2);

void String_Destroy(void *ptr);

#endif
