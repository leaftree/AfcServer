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

#define STR_MARK 0x00535359

/**
 *
 * struct StringHeader - Header of a string
 *
 * @presize : Previous length
 * @cursize : Current length
 * @strflag : Mark it as a string
 *
 * @strflag is a fixed value as @STR_MARK
 *
 * When use String_New() to create a string, it will alloc
 * 12Bytes + string-size Byte(s) memory.
 *
 * But function only return string-size Btye(s). The 12Bytes is hidden, it is
 * used to represent the current length of the string, and it'll keep the 
 * previous length.
 */
typedef struct StringHeader_ {
	unsigned int presize;
	unsigned int cursize;
	unsigned int strflag;
} StringHeader;

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
*/

char *String_New(int size);
char *String_StripLeadingSpace(const char *in);
char *String_StripTrailingSpace(const char *in);
char *String_StripLeadingAndTrailingSpace(const char *in);

#endif
